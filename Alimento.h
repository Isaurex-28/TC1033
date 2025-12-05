#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

/*
* Clase alimento que hereda de la clase Insumo
*/
class Alimento: public Insumo{
    private:
    // Atributos específicos para alimento
    string tipo;
    bool refrigeracion;
    
    public:
    /*
    * Constructor de alimento que por default deja el tipo en blanco
    * y la refrigeracion verdadera
    * 
    * @param
    * @return Objeto Cafeteria
    */
    Alimento():Insumo(),tipo(""),refrigeracion(true){}
    

    /*
    * Constructor de alimento
    * 
    * @param string id: ID del alimento, string name: nombre del
    * alimento, float price: costo unitario, int quantity: cantidad 
    * en el inventario, string type: tipo de alimento, bool fridge:
    * requiere refrigeracion?
    * @return
    */
    Alimento(string id, string name, float price, int quantity, string type, 
             bool fridge):Insumo(id,name,price,quantity){
        tipo = type;
        refrigeracion = fridge;
    }
    
    void setTipo(string);
    void setRefrigeracion(bool);
    string getTipo();
    bool getRefrigeracion();
};

//Setters 
void Alimento::setTipo(string type){
    tipo = type;
}
void Alimento::setRefrigeracion(bool fridge){
    refrigeracion = fridge;
}

//Getters
string Alimento::getTipo(){
    return tipo;
}
bool Alimento::getRefrigeracion(){
    return refrigeracion;
}

#endif
