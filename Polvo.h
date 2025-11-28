#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

class Polvo: public Insumo{
    private:
    string marca;
    float peso;

    public:
    Polvo():Insumo(),marca(""),peso(0.0){};
    Polvo(string id,string name,float costo,int cantidad,string brand,float weight):Insumo(id,name,costo,cantidad){
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