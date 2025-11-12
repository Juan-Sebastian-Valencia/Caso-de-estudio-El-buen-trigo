#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <filesystem>

class BaseDeDatos {
private:
    std::string rutaBD;
    std::map<std::string, std::vector<std::string>> datos;

    void cargarDatos(const std::filesystem::path& ruta, const std::string& nombreArchivo);

public:
    BaseDeDatos();
    // conectar puede recibir una carpeta (lee todos los .txt) o un solo archivo .txt
    void conectar(const std::string& ruta);
    void desconectar();

    const std::map<std::string, std::vector<std::string>>& obtenerDatos() const;
    std::vector<std::string> obtenerLineas(const std::string& nombreArchivo) const;
};

#endif
