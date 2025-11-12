#include "BaseDeDatos.h"
#include <filesystem>

BaseDeDatos::BaseDeDatos() {}

void BaseDeDatos::conectar(const std::string& ruta) {
    rutaBD = ruta;
    datos.clear();

    namespace fs = std::filesystem;
    fs::path p(ruta);

    if (!fs::exists(p)) {
        std::cerr << "Ruta no existe: " << ruta << std::endl;
        return;
    }

    if (fs::is_directory(p)) {
        for (const auto& ent : fs::directory_iterator(p)) {
            if (ent.is_regular_file() && ent.path().extension() == ".txt") {
                cargarDatos(ent.path(), ent.path().filename().string());
            }
        }
    } else if (fs::is_regular_file(p) && p.extension() == ".txt") {
        cargarDatos(p, p.filename().string());
    } else {
        std::cerr << "Ruta no es un .txt ni un directorio: " << ruta << std::endl;
    }
}

void BaseDeDatos::desconectar() {
    datos.clear();
}

void BaseDeDatos::cargarDatos(const std::filesystem::path& ruta, const std::string& nombreArchivo) {
    std::ifstream archivo(ruta);
    std::string linea;
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir: " << ruta << std::endl;
        return;
    }
    while (std::getline(archivo, linea)) {
        datos[nombreArchivo].push_back(linea);
    }
}

const std::map<std::string, std::vector<std::string>>& BaseDeDatos::obtenerDatos() const {
    return datos;
}

std::vector<std::string> BaseDeDatos::obtenerLineas(const std::string& nombreArchivo) const {
    auto it = datos.find(nombreArchivo);
    if (it != datos.end()) return it->second;
    return {};
}
