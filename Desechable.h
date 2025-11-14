#include <iostream>
#include <string>

class Desechable{
    private:
        int ID;
        std::string tipo;
        float tamaño;
        int cantidad;
    public:

    //Constructor
    Desechable():ID(0),tipo(""),tamaño(0.0),cantidad(0){};
    Desechable(int id,std::string type,float size, int quantity): ID(id),tipo(type),tamaño(size),cantidad(quantity){};

    //Setters
    void setID(int);
    void setTipo(std::string);
    void setTamaño(float);
    void setCantidad(int);

    //Getters
    int getID();
    std::string getTipo();
    float getTamaño();
    int getCantidad();

    //Métodos
    void consume(float);
    bool disponible();

};

//Setters
void Desechable::setID(int id){
    ID = id;
}
void Desechable::setTipo(std::string type){
    tipo = type;
}
void Desechable::setTamaño(float size){
    tamaño = size;
}
void Desechable::setCantidad(int quantity){
    cantidad = quantity;
}
    
//Getters
int Desechable::getID(){
    return ID;
}
std::string Desechable::getTipo(){
    return tipo;
}
float Desechable:: getTamaño(){
    return tamaño;
}
int Desechable:: getCantidad(){
    return cantidad;
}

//Métodos
void Desechable::consume(float quantity){

    if (quantity > cantidad){
        std::cout << "No hay suficiente " << tipo << " tamano " << tamaño << std::endl;
    }
    if(quantity <= cantidad){
        cantidad -= quantity;
        std::cout << "Se consumieron " << quantity << " " << tipo << " tamano " << tamaño << std::endl;
    }
}
bool Desechable::disponible(){
    if (cantidad>0){
        return true;
    }
    else{
        return false;
    }
}