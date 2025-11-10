#include "InventarioPanes.h"

InventarioPanes::InventarioPanes(){
    panes = {};
}

//Implementación de getter de la clase
std::vector<Panes> InventarioPanes::getVectorPanes() const {return panes; }


//Implementación de métodos para gestionar los panes de la panaderia
void InventarioPanes::agregarPan(const Panes& nuevoPan, InventarioIngredientes& inventario) {
    panes.push_back(nuevoPan);
    inventario.restarIngredientesReceta(nuevoPan.getReceta());
}

void InventarioPanes::eliminarPanes(std::string& nombrePan, int cantidadEliminar)
    {buscarPan(nombrePan).setStock(buscarPan(nombrePan).getStock() - cantidadEliminar); }

Panes& InventarioPanes::buscarPan(std::string& nombrePan){
    for(int i = 0; i <= panes.size(); i++){
        if(panes.at(i).getNombre() == nombrePan){
            return panes[i];
            break;
        }
    }
}