#ifndef DESECHABLE_H
#define DESECHABLE_H

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

/*
* Clase desechable que hereda de la clase Insumo
*/

class Desechable: public Insumo{
    private:
    // Atributos específicos para desechable
    string tipo;
    float tamanio;
    
    public:
    /*
    * Constructor de desechable que por default deja el tipo en blanco
    * y la tamaño en 0
    * 
    * @param
    * @return Objeto Desechable
    */
    Desechable():Insumo(),tipo(""),tamanio(0.0){};
    
    /*
    * Constructor de desechable
    * 
    * @param string id: ID del desechable, string name: nombre del
    * desechable, float price: costo unitario, int quantity: cantidad 
    * en el inventario, string type: tipo de desechable, float size:
    * tamaño del desechable
    * @return
    */
    Desechable(string id,string name,float price, int quantity, string type, 
               float size): Insumo(id,name,price,quantity){
        tipo = type;
        tamanio = size;
    }
    
    void setTipo(string);
    void setTamanio(float);
    string getTipo();
    float getTamanio();
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
#endif
