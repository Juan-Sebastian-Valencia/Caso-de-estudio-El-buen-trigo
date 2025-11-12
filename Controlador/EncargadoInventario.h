#ifndef ENCARGADOINVENTARIO_H
#define ENCARGADOINVENTARIO_H

#include "Modelo/InventarioPanes.h"
#include "Modelo/InventarioIngredientes.h"
#include <iostream>
using namespace std;

class EncargadoInventario {
public:
    EncargadoInventario();

    void registrarIngrediente(InventarioIngredientes& inv);
    void editarIngrediente(InventarioIngredientes& inv);
    void eliminarIngrediente(InventarioIngredientes& inv);
    void consultarInventario(const InventarioIngredientes& inv);
    void verificarNivelMinimo(const InventarioIngredientes& inv);
};

#endif
