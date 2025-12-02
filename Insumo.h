#ifndef INSUMO_H
#define INSUMO_H

#include <iostream>
#include <string>

using namespace std;

class Insumo{
    protected:
        string ID;
        string nombre;
        float costoUnitario;
        int cantidadInventario;
    public:

    //Constructor
    Insumo():ID(""),nombre(""),costoUnitario(0.0),cantidadInventario(0){};
    Insumo(string id,string name,float price, int quantity): ID(id),nombre(name),costoUnitario(price),cantidadInventario(quantity){};

    //Setters
    void setID(string);
    void setNombre(string);
    void setCostoUnitario(float);
    void setCantidadInventario(int);

    //Getters
    string getID();
    string getNombre();
    float getCostoUnitario();
    int getCantidadInventario();

    //Métodos
    void agregarInsumo(int);
    bool usarInsumo(int);
    float valorInventario();

};

//Setters
void Insumo::setID(string id){
    ID = id;
}
void Insumo::setNombre(string name){
    nombre = name;
}
void Insumo::setCostoUnitario(float price){
    costoUnitario = price;
}
void Insumo::setCantidadInventario(int quantity){
    cantidadInventario = quantity;
}
    
//Getters
string Insumo::getID(){
    return ID;
}
string Insumo::getNombre(){
    return nombre;
}
float Insumo:: getCostoUnitario(){
    return costoUnitario;
}
int Insumo:: getCantidadInventario(){
    return cantidadInventario;
}

//Métodos
void Insumo::agregarInsumo(int quantity){
    cantidadInventario += quantity;
}
bool Insumo::usarInsumo(int quantity){
    if (cantidadInventario - quantity > 0){
        cantidadInventario -= quantity;
        return true;
    }
    else
        return false;
    
}
float Insumo::valorInventario(){
    float valor = costoUnitario * cantidadInventario;
    return valor;
}

#endif
