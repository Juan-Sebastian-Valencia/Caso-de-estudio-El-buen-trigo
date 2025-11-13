/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Panadero
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/
#ifndef PANADERO_H
#define PANADERO_H

#include "../Modelo/InventarioIngredientes.h"
#include "../Modelo/Recetas.h"
#include "../Modelo/InventarioPanes.h"
#include <vector>
#include <string>

class Panadero {
public:
    Panadero();

    // Registra una nueva receta
    void registrarReceta(std::vector<Recetas>& recetas, const Recetas& nuevaReceta);

    // Modifica una receta existente (según el índice)
    void modificarReceta(std::vector<Recetas>& recetas, int indice, const Recetas& recetaModificada);

    // Produce pan con base en una receta existente
    void producirPan(const std::string& nombreReceta);

    // Consulta el stock de panes (devuelve el vector para que la Vista lo muestre)
    std::vector<Panes> consultarStock(const InventarioPanes& inventarioPanes) const;
};

#endif // PANADERO_H
