#include <Ingrediente.h>

Ingrediente::Ingrediente(std::string n, std::string u, float c, float min) : nombre(n), unidadMedida(u), stock(c), nivelMinimo(min) {}


//Implementación de getters de la clase
std::string Ingrediente::getNombre() const { return nombre; }
std::string Ingrediente::getUnidadMedida() const {return unidadMedida; }
double Ingrediente::getStock() const {return stock; }
double Ingrediente::getNivelMinimo() const {return nivelMinimo; }

//Implementación de setters de la clase
void Ingrediente::setNombre(const std::string& nombre) { this -> nombre = nombre; }
void Ingrediente::setUnidadMedida(const std::string& unidadMedida) 
    { this -> unidadMedida = unidadMedida; }
void Ingrediente::setStock(const double stock) { this -> stock = stock; }
void Ingrediente::setNivelMinimo(const double nivelMinimo) 
    {this -> nivelMinimo = nivelMinimo; }