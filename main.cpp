#include <iostream>
#include "ControladorGeneral.h"
#include "Panadero.h"
#include "EncargadoInventario.h"
#include "Administrador.h"
#include "Vista.h"
using namespace std;

int main() {
    ControladorGeneral app;
    Vista vista;

    app.inicializarBaseDeDatos("Datos/");

    bool salir = false;

    while (!salir) {
        vista.mostrarMenu();
        int opcion = vista.obtenerOpcionMenu();
        
        switch (opcion) {
            case 1: app.ejecutarMenuPanadero(opcion); break;
            case 2: app.ejecutarMenuEncargado(opcion); break;
            case 3: app.ejecutarMenuAdministrador(opcion); break;
            case 4: salir = true; break;
            default:
                cout << "Opción inválida.\n";
                continue;
        }
    }

    cout << "\nGracias por usar El Buen Trigo. ¡Hasta pronto!\n";
    return 0;
}
