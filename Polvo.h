#ifndef POLVO_H
#define POLVO_H

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

/*
* Clase polvo que hereda de la clase Insumo
*/

class Polvo: public Insumo{
    private:
    // Atributos específicos para polvo
    string marca;
    float peso;

    public:
    /*
    * Constructor de polvo que por default deja la marca en blanco y el 
    * peso en 0
    * 
    * @param
    * @return Objeto Polvo
    */
    Polvo():Insumo(),marca(""),peso(0.0){};
    
    /*
    * Constructor de polvo
    * 
    * @param string id: ID del polvo, string name: nombre del
    * polvo, float price: costo unitario, int quantity: cantidad 
    * en el inventario, string brand: marca, float weight:
    * peso del empaque
    * @return
    */
    Polvo(string id,string name,float price,int quantity,string brand,
          float weight):Insumo(id,name,price,quantity){
        marca = brand;
        peso = weight;
    };

    void setMarca(string);
    void setPeso(float);
    string getMarca();
    float getPeso();
};

//Setters
void Polvo::setMarca(string brand){
    marca = brand;
}
void Polvo::setPeso(float weight){
    peso = weight;
}

//Getters
string Polvo::getMarca(){
    return marca;
}
float Polvo::getPeso(){
    return peso;
}

#endif
