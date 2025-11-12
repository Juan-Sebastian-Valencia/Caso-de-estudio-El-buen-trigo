#include "InventarioIngredientes.h"
#include <algorithm>

InventarioIngredientes::InventarioIngredientes(){
    ingredientes = {};
}

//Implementación de los métodos de gestion de ingredientes de la panaderia
void InventarioIngredientes::agregarIngrediente(const Ingrediente& nuevoIngrediente)
    { ingredientes.push_back(nuevoIngrediente); }

void InventarioIngredientes::eliminarIngrediente(const std::string& nombreIngrediente){
    for(int i = 0; i <= ingredientes.size(); i++){
        if(ingredientes.at(i).getNombre() == nombreIngrediente){
            ingredientes.erase(ingredientes.begin() + i);  // Revisar esta linea de codigo luego
        }
    }
}

void InventarioIngredientes::modificarStockIngrediente(const std::string& nombreIngrediente, double nuevoStock)
    { buscarIngrediente(nombreIngrediente).setStock(nuevoStock); }

void InventarioIngredientes::restarIngrediente(const std::string& nombreIngrediente, double cantidadRestar){
    buscarIngrediente(nombreIngrediente).setStock(buscarIngrediente(nombreIngrediente).getStock() - cantidadRestar);
}

void InventarioIngredientes::restarIngredientesReceta(const Receta& receta){  // Método pendiente por terminar
    /*for(Ingrediente ingrediente : receta.getIngredientesReceta()){
        for(Ingrediente ingredientesInventario : ingredientes){
            if(ingredientesInventario.getNombre() == ingrediente.getNombre()){

            }
        }
    }*/
}

Ingrediente& InventarioIngredientes::buscarIngrediente(const std::string& nombreIngrediente){
    for(int i = 0; i <= ingredientes.size(); i++){
        if(ingredientes.at(i).getNombre() == nombreIngrediente){
            return ingredientes[i];
            break;
        }
    }
}

bool InventarioIngredientes::verificarNivelMinimo(const Ingrediente& ingrediente) const{
    if(ingrediente.getStock() < ingrediente.getNivelMinimo()) return true;
    else false;
}

std::vector<Ingrediente> InventarioIngredientes::getIngredientes() const {
    return ingredientes;
}
