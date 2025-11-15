/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       EncargadoInventario
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/
#ifndef ENCARGADOINVENTARIO_H
#define ENCARGADOINVENTARIO_H

#include "Stock.h"
#include "Inventario.h"
#include "VistaEncargadoInventario.h"
#include "BaseDeDatos.h"
#include <iostream>

class EncargadoInventario {
private:
    BaseDeDatos bd;
public:
    EncargadoInventario();

    void registrarIngrediente(Inventario& inv);
    void editarIngrediente(Inventario& inv);
    void eliminarIngrediente(Inventario& inv);
    void consultarInventario(const Inventario& inv);
    void verificarNivelMinimo(VistaEncargadoInventario& inv);
};

#endif
