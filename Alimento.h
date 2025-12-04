#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;
/* Clase Alimento que hereda de Insumo,
* tiene 2 atributos y hereda todos los métodos
* de Insumo.
*/

class Alimento: public Insumo{
    private:
    string tipo;
    bool refrigeracion;
    
    public:
    Alimento():Insumo(),tipo(""),refrigeracion(true){}
    Alimento(string id, string name, float price, int quantity, string type, bool fridge):Insumo(id,name,price,quantity){
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

