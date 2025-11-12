#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nombre;
    string tipo;
public:
    Usuario(string n = "", string t = "");
    virtual void mostrarMenu() = 0;
    virtual ~Usuario() = default;
};

#endif
