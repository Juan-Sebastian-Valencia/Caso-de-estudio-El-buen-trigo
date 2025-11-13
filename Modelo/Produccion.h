#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "Recetas.h"
#include "InventarioPanes.h"

class Produccion {
private:
    Recetas receta;
    int cantidadProducir;

public:
    Produccion(Recetas r, int cant);
    void registrarProduccion(InventarioPanes& inv);
};

#endif
