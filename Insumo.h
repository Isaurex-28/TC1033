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
    Insumo(string id,string nme,float costo, int cantidad): ID(id),nombre(nme),costoUnitario(costo),cantidadInventario(cantidad){};

    //Setters
    void setID(string);
    void setName(string);
    void setCostoUnitario(float);
    void setCantidadInventario(int);

    //Getters
    string getID();
    string getNombre();
    float getCostoUnitario();
    int getCantidadInventario();

    //Métodos
    void agregarInventario(int);
    void usarInsumo(int);
    float valorInventario();

};

//Setters
void Insumo::setID(string id){
    ID = id;
}
void Insumo::setName(string nme){
    nombre = nme;
}
void Insumo::setCostoUnitario(float costo){
    costoUnitario = costo;
}
void Insumo::setCantidadInventario(int cantidad){
    cantidadInventario = cantidad;
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
void Insumo::agregarInventario(int quantity){
    cantidadInventario += quantity;
}
void Insumo::usarInsumo(int quantity){
    cantidadInventario -= quantity;
}
float Insumo::valorInventario(){
    float valor = costoUnitario * cantidadInventario;
    return valor;
}
