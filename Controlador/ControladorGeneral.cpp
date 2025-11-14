#include "ControladorGeneral.h"

ControladorGeneral::ControladorGeneral() {}

void ControladorGeneral::ejecutarMenuPanadero(int opcion) {
    do{
        VistaPanadero vpan;
        vpan.mostrarMenuPanadero();
        int opcion = vpan.obtenerOpcionMenu();
        switch (opcion) {
            case 1:
                panadero.registrarReceta(recetas, Recetas());
                break;
            case 2:
                panadero.modificarReceta(recetas, Recetas());
                break;
            case 3:
                panadero.consultarStock(Stock());
                break;
            case 4:
                std::cout << "Saliendo del menú de Panadero...\n";
                break;
            default:
                break;
        }
    }while(opcion != 4);
}

void ControladorGeneral::ejecutarMenuEncargado(int opcion) {
    do{
        VistaEncargadoInventario vinv;
        vinv.mostrarMenuEncargadoInventario();
        int opcion = vinv.obtenerOpcionMenu();
        switch (opcion) {
            case 1: {
                Inventario ingrediente;
                encargadoInventario.registrarIngrediente(ingrediente);
                break;
            }
            case 2:{
                Inventario ingrediente;
                encargadoInventario.consultarInventario(ingrediente);
                break;
            }
            case 3:{
                VistaEncargadoInventario vinv;
                encargadoInventario.verificarNivelMinimo(vinv);
                break;
            }
            case 4:
                std::cout << "Saliendo del menú de Encargado de Inventario...\n";
                break;
            default:
                break;
        }
    } while(opcion != 4);
}

void ControladorGeneral::ejecutarMenuAdministrador(int opcion) {
    do{
        VistaAdministrador vadm;
        vadm.mostrarMenuAdministrador();
        int opcion = vadm.obtenerOpcionMenu();
        switch (opcion) {
            case 1:{
                VistaAdministrador vadm;
                administrador.exportarReporteTxt(vadm);
                break;
            }
            case 2:
                std::cout << "Saliendo del menú de Administrador...\n";
                break;
            default:
                break;
        }
    }while(opcion != 2);
}
