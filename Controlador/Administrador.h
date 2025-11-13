/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Administrador
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Modelo/Inventario.h"
#include "BaseDeDatos.h"
#include "Modelo/Stock.h"
#include <fstream>
#include <iostream>
using namespace std;

class Administrador {
public:
    Administrador();

    void generarReporte(const Inventario& inv);
    void exportarReporteTxt(const Inventario& inv);
};

#endif
