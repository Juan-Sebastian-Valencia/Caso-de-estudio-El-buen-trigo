#include "Administrador.h"

Administrador::Administrador() {}

void Administrador::generarReporte(const InventarioIngredientes& inv) {
    cout << "\n --- Reporte de Inventario ---\n";
    for (const auto& i : inv.getIngredientes()) {
        cout << "- " << i.getNombre() << ": " << i.getCantidad() << " " << i.getUnidad();
        if (i.verificarNivelMinimo()) cout << " Bajo nivel";
        cout << endl;
    }

    cout << "\n --- Stock de Productos ---\n";
    for (const auto& p : inv.getProductos())
        cout << "- " << p.getTipo() << ": " << p.getCantidad() << " unidades\n";
}

void Administrador::exportarReporteTxt(const InventarioIngredientes& inv) {
    ofstream file("reporte_inventario.txt");
    if (!file.is_open()) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    file << "===== REPORTE DE INVENTARIO Y STOCK =====\n\n";

    file << "[Ingredientes]\n";
    for (const auto& i : inv.getIngredientes()) {
        file << "- " << i.getNombre() << ": " << i.getCantidad() << " " << i.getUnidad();
        if (i.verificarNivelMinimo()) file << " (Bajo nivel)";
        file << "\n";
    }

    file << "\n[Productos]\n";
    for (const auto& p : inv.getProductos())
        file << "- " << p.getTipo() << ": " << p.getCantidad() << " unidades\n";

    file.close();
    cout << "Reporte exportado exitosamente como 'reporte_inventario.txt'.\n";
}
