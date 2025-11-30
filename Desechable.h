#ifndef DESECHABLE_H
#define DESECHABLE_H

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

class Desechable: public Insumo{
    private:
    string tipo;
    float tamanio;
    
    public:
    Desechable():Insumo(),tipo(""),tamanio(0.0){};
    Desechable(string id,string name,float price, int quantity, string type, float size): Insumo(id,name,price,quantity){
        tipo = type;
        tamanio = size;
    }
    
    void setTipo(string);
    void setTamanio(float);
    string getTipo();
    float getTamanio();
    void reciclar();
};

//Setters
void Desechable::setTipo(string type){
    tipo = type;
}
void Desechable::setTamanio(float size){
    tamanio = size;
}
    
//Getters
string Desechable::getTipo(){
    return tipo;
}
float Desechable:: getTamanio(){
    return tamanio;
}

//Métodos
void Desechable::reciclar(){
    usarInsumo(cantidadInventario);
}

#endif
