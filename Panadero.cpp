#include "Panadero.h"

Panadero::Panadero() {}

// Registra una receta (solo agrega al vector recibido)
void Panadero::registrarReceta(std::vector<Recetas>& recetas) {
    VistaPanadero vista;
    vista.obtenerDatosRegistroReceta();
 
    std::string nombre = vista.obtenerNombreReceta();
    int cantidadProduccion = vista.obtenerCantidadIngredientes();
    auto ingredientesReceta = vista.obtenerIngredientesReceta(cantidadProduccion);

    Recetas receta(nombre, cantidadProduccion, ingredientesReceta);

    // Formatear línea para guardar en archivo
    std::string linea = nombre + ";";
    for (auto& ing : receta.getIngredientesReceta()) {
        linea += ing.first.getNombre() + ":" + ing.first.getUnidadMedida() + ":" + std::to_string(ing.second) + ";";
    }
    recetas.push_back(receta);

    std::cout << "[Panadero] Receta registrada con éxito.\n";
    bd->agregarLinea("recetas.txt", linea);
}

// Modifica una receta existente (reemplaza el objeto)
void Panadero::modificarReceta(std::vector<Recetas>& recetas, const Recetas& recetaModificada) {
    VistaPanadero vista;
    std::cout << "\n[Panadero] Modificando receta...\n";
    std::string nombre = vista.obtenerNombreReceta();
    int cantidadProduccion = vista.obtenerCantidadIngredientes();
    auto ingredientesReceta = vista.obtenerIngredientesReceta(cantidadProduccion);
    Recetas recetaModifica(nombre, cantidadProduccion, ingredientesReceta);

    for (auto& receta : recetas) {
        if (receta.getNombre() == recetaModifica.getNombre()) {
            receta = recetaModifica;
            break;
        }
    }

    std::vector<std::string> nuevasLineas;
    for (const auto& r : recetas) {
        std::string linea = nombre + ";";
        for (const auto& ing : r.getIngredientesReceta()) {
            linea += ing.first.getNombre() + ":" + ing.first.getUnidadMedida() + ":" + std::to_string(ing.second) + ";";
        }
        nuevasLineas.push_back(linea);
    }
    
    bd->sobrescribirArchivo("recetario.txt", nuevasLineas);

    std::cout << "[Panadero] Receta modificada con éxito.\n";
}

// Produce pan (actualiza el inventario de panes e ingredientes)
void Panadero::producirPan(const std::string& nombreReceta, Inventario& inventario, Stock& stockDePanes, const std::vector<Recetas>& recetas) {
    VistaPanadero vista;
    std::string nombreDeReceta = vista.obtenerNombreReceta();
    int cantidadProduccion = vista.obtenerCantidadProduccion();
    
    VistaEncargadoInventario veinv;
    if (cantidadProduccion<0){
        veinv.ingredienteNegativo();
    }

    const Recetas* recetaSeleccionada = nullptr;

    for (const auto& receta : recetas) {
            if (receta.getNombre() == nombreDeReceta) {
                recetaSeleccionada = &receta;
                break;
            }
        }
        if (!recetaSeleccionada) {
            std::cout << "[Panadero] Receta no encontrada.\n";
            return;
        }

    // Verificar si hay suficientes ingredientes
    if (!inventario.verificarCantIngredientes(recetaSeleccionada->getIngredientesReceta(), cantidadProduccion)){
        std::cout << "[Panadero] Producción cancelada.\n";
        return;
    }

    // restar ingredientes del inventario
    for (const auto& ingrediente : recetaSeleccionada->getIngredientesReceta()) {
        inventario.restarCantidadIngrediente(ingrediente.first.getNombre(), ingrediente.second * cantidadProduccion);
    }
    // Añadir pan producido al stock
    Panes nuevoPan(nombreDeReceta, cantidadProduccion, *recetaSeleccionada);
    stockDePanes.agregarPan(nuevoPan, inventario);
    std::cout << "[Panadero] Producción completada. Se han producido " << cantidadProduccion << " unidades de " << nombreReceta << ".\n";
    bd->agregarLinea("stock.txt", nombreDeReceta + ";" + std::to_string(cantidadProduccion) + ";");
}

void Panadero::setBaseDatos(BaseDeDatos& bd) {
    this->bd = &bd;
}