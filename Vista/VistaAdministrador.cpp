#include "VistaAdministrador.h"

void VistaAdministrador::mostrarMenuAdministrador() {
    std::cout << "\n--- Menú Administrador ---\n";
    std::cout << "1. Generar Reporte de Inventario\n";
    std::cout << "2. Exportar Reporte a TXT\n";
    std::cout << "3. Ver Resumen General\n";
    std::cout << "4. Salir\n";
}

void VistaAdministrador::mostrarReporteInventario(const std::map<Ingredientes, double>& inventario) const {
    std::cout << "\n[VistaAdministrador] Mostrando reporte de inventario...\n";
    for (const auto& item : inventario) {
        std::cout << "Ingrediente: " << item.first.getNombre() << " Unidad de medida: " << item.first.getUnidadMedida() << ", Cantidad: " << item.second << "\n";
    }
}

void VistaAdministrador::mostrarReporteStock(const std::vector<Panes>& stock) {
    std::cout << "\n[VistaAdministrador] Mostrando reporte de stock de productos...\n";
    for (const auto& item : stock) {
        std::cout << "Nombre del pan: " << item.getNombre() << " Cantidad: " << item.getStock() << "\n";
    }
}

void VistaAdministrador::advertenciaExportacion() {
    std::cout << "\n¡Advertencia! Recuerde guardar los cambios antes de exportar el reporte.\n";
}

int VistaAdministrador::obtenerOpcionMenu() {
    int opcion;
    std::cout << "\nSeleccione una opción: ";
    std::cin >> opcion;
    return opcion;
}

void VistaAdministrador::mostrarResumenGeneral() {
    std::cout << "\n[VistaAdministrador] Mostrando resumen general del sistema...\n";
    
}

void VistaAdministrador::mostrarReporteGeneral() {
    std::cout << "\n[VistaAdministrador] Mostrando reporte general completo...\n";
}
