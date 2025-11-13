#include "Produccion.h"
#include <iostream>
using namespace std;

Produccion::Produccion(Receta r, int cant)
    : receta(r), cantidadProducir(cant) {}

void Produccion::registrarProduccion(InventarioPanes& inv) {
    cout << "Produciendo " << cantidadProducir << " unidades de " << receta.getNombre() << endl;
    inv.mostrarAlertas();
}
