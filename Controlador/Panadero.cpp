#include "Panadero.h"

Panadero::Panadero() {}

// ===========================================================
// Registra una receta (solo agrega al vector recibido)
// ===========================================================
void Panadero::registrarReceta(std::vector<Receta>& recetas, const Receta& nuevaReceta) {
    recetas.push_back(nuevaReceta);
}

// ===========================================================
// Modifica una receta existente (reemplaza el objeto)
// ===========================================================
void Panadero::modificarReceta(std::vector<Receta>& recetas, int indice, const Receta& recetaModificada) {
    if (indice >= 0 && indice < static_cast<int>(recetas.size())) {
        recetas[indice] = recetaModificada;
    }
}

// ===========================================================
// Produce pan (actualiza el inventario de panes e ingredientes)
// ===========================================================
void Panadero::producirPan(const std::string& nombreReceta) {
    // Lógica para producir pan basada en la receta
    // Esta función debería interactuar con InventarioPanes e InventarioIngredientes
}

// ===========================================================
// Devuelve el stock actual de panes (sin imprimir nada)
// ===========================================================
std::vector<Panes> Panadero::consultarStock(const InventarioPanes& inventarioPanes) const {
    return inventarioPanes.getVectorPanes();
}
