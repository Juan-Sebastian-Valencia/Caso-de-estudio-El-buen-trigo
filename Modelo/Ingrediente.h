/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Ingredientes
Responsabilidades:        

  - Representar los ingredientes de la panaderia. Debe tener un nombre,
    cantidad, unidad de medida y nivel minimo.

Colaboradores:            
    ...
===============================================================================
*/

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>

class Ingrediente{

    private:  // Atributos de la clase
        std::string nombre;
        std::string unidadMedida;
        double stock;
        double nivelMinimo;

    public:  //Métodos de la clase
        Ingrediente(std::string n = "", std::string u = "", float c = 0, float min = 0);  //Constructor de la clase

        //Getters 
        std::string getNombre() const;
        std::string getUnidadMedida() const;
        double getStock() const;
        double getNivelMinimo() const;

        //setters
        void setNombre(const std::string& nombre);
        void setUnidadMedida(const std::string& UnidadMedida);
        void setStock(const double stock);
        void setNivelMinimo(const double nivelMinimo);
};

#endif //INGREDIENTE