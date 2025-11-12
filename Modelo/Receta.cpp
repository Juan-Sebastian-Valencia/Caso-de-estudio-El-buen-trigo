#include "Receta.h"

Receta::Receta(){
    nombre = " ";
    numeroIngredientes = 0;
    ingredientesReceta = {};
    cantidadIngredientes = {};
}

//Implementación de getters de la clase
std::string Receta::getNombre() const { return nombre; }

int Receta::getNumeroIngredientes() const { return numeroIngredientes; }

std::vector<Ingrediente>& Receta::getIngredientesReceta()  
    { return ingredientesReceta; }

std::vector<double>& Receta::getCantidadIngredientes() 
    { return cantidadIngredientes; }


//Implementación de setters de la clase
void Receta::setNombre(const std::string& nombre)
    { this -> nombre = nombre; }

void Receta::setNumeroIngredientes(const int numeroIngredientes)
    {this -> numeroIngredientes = numeroIngredientes; }

    
//Implementación de métodos de manipulación de los vectores
void Receta::agregarIngredienteReceta(const Ingrediente& nuevoIngrediente)
    { ingredientesReceta.push_back(nuevoIngrediente); }

void Receta::agregarCantidadIngrediente(const double cantidadIngrediente)
    { cantidadIngredientes.push_back(cantidadIngrediente); }