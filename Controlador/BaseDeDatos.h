#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
#include "Modelo/Panes.h"
#include "Modelo/Ingredientes.h"

using json = nlohmann::json;

class BaseDeDatos {
private:
    json datosJSON;
    bool jsonCargado;

public:
    BaseDeDatos();
    
    // Conectar y desconectar
    void conectar(const std::string& ruta);
    void desconectar();
    bool tieneJSON() const;
    
    // Guardar y cargar datos
    void guardarDatos(const std::string& rutaArchivo,
                      const std::vector<Ingredientes>& ingredientes,
                      const std::vector<Panes>& panes); //contiene los vectores para guardar los datos de ingredientes y de panes
    
    std::vector<Ingredientes> cargarIngredientes();
    std::vector<Panes> cargarPanes();
};

#endif
