#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "Receta.h"
#include "InventarioPanes.h"

class Produccion {
private:
    Receta receta;
    int cantidadProducir;

public:
    Produccion(Receta r, int cant);
    void registrarProduccion(InventarioPanes& inv);
};

#endif
