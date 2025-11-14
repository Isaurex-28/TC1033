#include <iostream>
#include <string>

class Insumo{
    private:
        int ID;
        std::string nombre;
        float cantidad;
        bool caduco;
    public:

    //Constructor
    Insumo():ID(0),nombre(""),cantidad(0.0),caduco(false){};
    Insumo(int id,std::string nme,float quantity, bool cad): ID(id),nombre(nme),cantidad(quantity),caduco(cad){};

    //Setters
    void setID(int);
    void setName(std::string);
    void setCantidad(float);
    void setCaduco(bool);

    //Getters
    int getID();
    std::string getNombre();
    float getCantidad();
    bool getCaduco();

    //Métodos
    void consume(float);
    bool disponible();

};

//Setters
void Insumo::setID(int id){
    ID = id;
}
void Insumo::setName(std::string nme){
    nombre = nme;
}
void Insumo::setCantidad(float quantity){
    cantidad = quantity;
}
void Insumo::setCaduco(bool cad){
    caduco = cad;
}
    
//Getters
int Insumo::getID(){
    return ID;
}
std::string Insumo::getNombre(){
    return nombre;
}
float Insumo:: getCantidad(){
    return cantidad;
}
bool Insumo:: getCaduco(){
    return caduco;
}

//Métodos
void Insumo::consume(float quantity){
    if (caduco){
        std::cout << nombre << " está caduco" << std::endl;
    }
    if (quantity > cantidad){
        std::cout << "No hay suficiente " << nombre << std::endl;
    }
    if(quantity <= cantidad){
        cantidad -= quantity;
        std::cout << "Se consumieron " << quantity << " " << nombre << std::endl;
    }
}
bool Insumo::disponible(){
    if ((cantidad>0)&&(!caduco)){
        return true;
    }
    else{
        return false;
    }
}