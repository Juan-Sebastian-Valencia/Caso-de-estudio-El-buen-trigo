/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       InventarioIngredientes
Responsabilidades:        
    
  - Gestionar los Ingredientes de la panaderia proporcionando métodos como
    "agregarIngrediente()", "eliminarIngredientes()", etc.
      

Colaboradores:            
    
  - Contiene objetos de la clase Ingredientes.
  - Conoce objetos de la clase Recetas.

===============================================================================
*/

#ifndef INVENTARIOINGREDIENTES_H
#define INVENTARIOINGREDIENTES_H

#include "Ingredientes.h"
#include "Recetas.h"
#include <vector>

class InventarioIngredientes{

    private:  //Atributo de la clase
        std::vector<Ingredientes> ingredientes;

    public:  //Métodos de la clase
        InventarioIngredientes();  // Constructor de la clase

        //Métodos para gestionar los ingredientes de la panaderia
        void agregarIngrediente(const Ingredientes& nuevoIngrediente);
        void eliminarIngrediente(const std::string& nombreIngrediente);
        void modificarStockIngrediente(const std::string& nombreIngrediente, double nuevaCantidad);
        void restarIngrediente(const std::string& nombreIngrediente, double cantidadRestar);
        void restarIngredientesReceta(const Recetas& receta);
        Ingredientes& buscarIngrediente(const std::string& nombreIngrediente);
        bool verificarNivelMinimo(const Ingredientes& ingrediente) const;
};

#endif // INVENTARIOINGREDIENTES_H
