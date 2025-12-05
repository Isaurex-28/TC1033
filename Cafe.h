#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;

/*
* Clase cafe que hereda de la clase Insumo
*/

class Cafe: public Insumo{
    private:
    // Atributos específicos para cafe
    string grano;
    int tueste;
    bool entero;

    public:
    /*
    * Constructor de cafe que por default deja el tipo en blanco, el 
    * tueste en 95 y entero falso
    * 
    * @param
    * @return Objeto Cafe
    */
    Cafe():Insumo(),grano(""),tueste(95),entero(false){}
    
    /*
    * Constructor de cafe
    * 
    * @param string id: ID del cafe, string name: nombre del
    * cafe, float price: costo unitario, int quantity: cantidad 
    * en el inventario, string bean: tipo de grano, int roast:
    * tueste según la escala de Agtron, bool whole: el grano es entero?
    * @return
    */    
    Cafe(string id,string name,float price,int quantity,string bean,
         int roast,bool whole):Insumo(id,name,price,quantity){
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

/*
* Funcion que cambia el estatus de grano entero
* 
* @param 
* @return
*/
void Cafe::moler(){
    // Se verifica que el cafe no este ya molido
    if (entero)
        // Se "muele" el café
        entero=false;
    else
        cout<<"El café ya está molido"<< endl;
}

/*
* Funcion que cambia el numero de tueste del grano
* 
* @param int numero: cantidad de tueste a aumentar
* @return
*/
void Cafe::tostar(int numero){
    // Se verifica que el café no esté más tostado del rango posible
    if ((numero < tueste) && (tueste-numero)>=15)
        // Se "tuesta" el cafe restando el numero del atributo
        tueste -= numero;
    else
        cout<<"El café ya está más tostado"<< endl;
}

#endif

