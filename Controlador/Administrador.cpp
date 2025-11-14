#include "Administrador.h"

Administrador::Administrador() {}

void Administrador::generarReporte(const Inventario& inv, const Stock& stockDePanes, const VistaAdministrador& vadm) {
    VistaAdministrador vista;
    std::cout << "\n --- Reporte de Inventario ---\n";
    vista.mostrarReporteInventario(std::map<Ingredientes, double>());
    std::cout << "\n --- Reporte de Stock ---\n";
    vista.mostrarReporteStock(std::vector<Panes>());
}

void Administrador::exportarReporteTxt(const VistaAdministrador& vadm) {
    ofstream file("reporte_inventario.txt");
    if (!file.is_open()) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    VistaAdministrador vista;

    file << "===== REPORTE DE INVENTARIO Y STOCK =====\n\n";
    
    file << "[Ingredientes]\n";
    vista.mostrarReporteInventario(std::map<Ingredientes, double>());

    file << "\n[Stock]\n";
    vista.mostrarReporteStock(std::vector<Panes>());

    file.close();
    cout << "Reporte exportado exitosamente como 'reporte_inventario.txt'.\n";
}
