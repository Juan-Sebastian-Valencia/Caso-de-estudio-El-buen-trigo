#include "InventarioIngredientes.h"
#include <algorithm>

InventarioIngredientes::InventarioIngredientes(){
    ingredientes = {};
}

//Implementación de los métodos de gestion de ingredientes de la panaderia
void InventarioIngredientes::agregarIngrediente(const Ingredientes& nuevoIngrediente)
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

void InventarioIngredientes::restarIngredientesReceta(const Recetas& receta){  // Método pendiente por terminar
    /*for(Ingredientes ingrediente : receta.getIngredientesReceta()){
        for(Ingredientes ingredientesInventario : ingredientes){
            if(ingredientesInventario.getNombre() == ingrediente.getNombre()){

            }
        }
    }*/
}

Ingredientes& InventarioIngredientes::buscarIngrediente(const std::string& nombreIngrediente){
    for(int i = 0; i <= ingredientes.size(); i++){
        if(ingredientes.at(i).getNombre() == nombreIngrediente){
            return ingredientes[i];
            break;
        }
    }
}

bool InventarioIngredientes::verificarNivelMinimo(const Ingredientes& ingrediente) const{
    if(ingrediente.getStock() < ingrediente.getNivelMinimo()) return true;
    else false;
}