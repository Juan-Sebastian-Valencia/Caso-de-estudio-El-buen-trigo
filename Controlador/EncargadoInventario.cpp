#include "EncargadoInventario.h"

EncargadoInventario::EncargadoInventario(){}

void EncargadoInventario::registrarIngrediente(InventarioIngredientes& inv) {
    string nombre, unidad;
    float cantidad, minimo;

    cout << "Nombre del ingrediente: ";
    cin >> nombre;
    cout << "Unidad de medida: ";
    cin >> unidad;
    cout << "Cantidad disponible: ";
    cin >> cantidad;
    cout << "Nivel mínimo de alerta: ";
    cin >> minimo;

    inv.agregarIngrediente(Ingrediente(nombre, unidad, cantidad, minimo));
    cout << " Ingrediente registrado con éxito.\n";
}

void EncargadoInventario::editarIngrediente(InventarioIngredientes& inv) {
    string nombre;

    auto ingredientes = inv.getIngredientes();

    cout << "Nombre del ingrediente a editar: ";
    cin >> nombre;
    
    for (auto& i : ingredientes) {
        if (i.getNombre() == nombre) {
            string nuevaNombre, nuevaUnidad;
            float nuevaCantidad, nuevoMinimo;

            cout << "Nuevo nombre para " << nombre << ": ";
            cin >> nuevaNombre;
            cout << " Nueva unidad de medida: ";
            cin >> nuevaUnidad;
            cout << " Nueva cantidad disponible: ";
            cin >> nuevaCantidad;
            cout << " Nuevo nivel mínimo de alerta: ";
            cin >> nuevoMinimo;

            i = Ingrediente(nuevaNombre, nuevaUnidad, nuevaCantidad, nuevoMinimo);
            cout << " Ingrediente actualizado con éxito.\n";
            return;
        }
    }
}

void EncargadoInventario::eliminarIngrediente(InventarioIngredientes& inv){
    string nombre;
    auto ingredientes = inv.getIngredientes();

    cout << "Nombre del ingrediente a eliminar: ";
    cin >> nombre;
    for (auto it = ingredientes.begin(); it != ingredientes.end(); ++it) {
        if (it->getNombre() == nombre) {
            ingredientes.erase(it);
            cout << " Ingrediente eliminado con éxito.\n";
            return;
        }
    }
}

void EncargadoInventario::consultarInventario(const InventarioIngredientes& inv) {
    auto ingredientes = inv.getIngredientes();
    if (ingredientes.empty()) {
        cout << " No hay ingredientes registrados.\n";
        return;
    }

    cout << "\n--- Inventario de Ingredientes ---\n";
    for (const auto& i : ingredientes)
        cout << i.getNombre() << " (" << i.getStock() << " " << i.getUnidadMedida() << ")\n";
}

void EncargadoInventario::verificarNivelMinimo(const InventarioIngredientes& inv) {
    cout << "\n--- Alertas de Reposición ---\n";
    inv.mostrarAlertas();
}
