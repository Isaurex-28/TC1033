#ifndef INSUMO_H
#define INSUMO_H

#include <iostream>
#include <string>

using namespace std;

/*
 * Clase Insumo contiene los métodos genéricos para los insumos
 * y tiene 4 clases hijas que son tipos de insumo:
 * Polvo, Cafe, Alimento y Desechable
 */

class Insumo{
    protected:
        // Atributos que heredan todos los insumos
        string ID;
        string nombre;
        float costoUnitario;
        int cantidadInventario;
    public:

    /*
    * Constructor de insumo que por default deja el nombre y el ID 
    * en blanco y el costo unitario y la cantidad en inventario en 0
    * 
    * @param
    * @return Objeto Insumo
    */    
    Insumo():ID(""),nombre(""),costoUnitario(0.0),cantidadInventario(0){};
    
    /*
    * Constructor de insumo
    * 
    * @param string id: ID del insumo, string name: nombre del
    * insumo, float price: costo unitario, int quantity: cantidad 
    * en el inventario
    * @return
    */
    Insumo(string id,string name,float price, int quantity): 
    ID(id),nombre(name),costoUnitario(price),cantidadInventario(quantity){};

    void setID(string);
    void setNombre(string);
    void setCostoUnitario(float);
    void setCantidadInventario(int);

    string getID();
    string getNombre();
    float getCostoUnitario();
    int getCantidadInventario();

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

/*
* Funcion agregar insumo que agrega una cantidad a la cantidad en
* inventario de un objeto Insumo
* 
* @param int quantity: cantidad a agregar
* @return
*/
void Insumo::agregarInsumo(int quantity){
    // Se suma la cantidad al atributo
    cantidadInventario += quantity;
}

/*
* Funcion agregar insumo que resta una cantidad a la cantidad en
* inventario de un objeto Insumo
* 
* @param int quantity: cantidad a restar
* @return bool hay suficiente para usarse?
*/
bool Insumo::usarInsumo(int quantity){
    // Se verifica que haya suficiente del Insumo para usarse
    if (cantidadInventario - quantity > 0){
        // Se resta la cantidad
        cantidadInventario -= quantity;
        return true;
    }
    else
        return false;
    
}

/*
* Funcion valor inventario que devuelve el valor total de un insumo 
* multiplicando el costo unitario por la cantidad del objeto que 
* hay almacenada
* 
* @param 
* @return float: valor total del objeto en inventario
*/
float Insumo::valorInventario(){
    float valor = costoUnitario * cantidadInventario;
    return valor;
}

#endif
