#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Modelo/InventarioIngredientes.h"
#include "BaseDeDatos.h"
#include <fstream>
#include <iostream>
using namespace std;

class Administrador {
public:
    Administrador();

    void generarReporte(const InventarioIngredientes& inv);
    void exportarReporteTxt(const InventarioIngredientes& inv);
};

#endif
