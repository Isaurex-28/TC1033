#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

class Cafe: public Insumo{
    private:
    string grano;
    int tueste;
    bool entero;

    public:
    Cafe():Insumo(),grano(""),tueste(0),entero(false){}
    Cafe(string id,string name,float costo,int cantidad,string bean,int roast,bool whole):Insumo(id,name,costo,cantidad){
        grano = bean;
        tueste = roast;
        entero = whole;
    }

    void setGrano(string);
    void setTueste(int);
    void setEntero(bool);
    string getGrano();
    int getTueste();
    bool getEntero();

    void moler();
    void tostar(int);
};

//Setters
void Cafe::setGrano(string bean){
    grano = bean;
}
void Cafe::setTueste(int roast){
    tueste = roast;
}
void Cafe::setEntero(bool whole){
    entero = whole;
}

//Getters
string Cafe::getGrano(){
    return grano;
}
int Cafe::getTueste(){
    return tueste;
}
bool Cafe::getEntero(){
    return entero;
}

//Métodos
void Cafe::moler(){
    if (entero)
        entero=false;
    else
        cout<<"El café ya está molido"<< endl;
}
void Cafe::tostar(int numero){
    if (numero > tueste)
        tueste += numero;
    else
        cout<<"El café ya está más tostado"<< endl;
}
