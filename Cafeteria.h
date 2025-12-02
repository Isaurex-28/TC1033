#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <iostream>
#include <string>
#include <sstream>

#include "Insumo.h"
#include "Cafe.h"
#include "Polvo.h"
#include "Alimento.h"
#include "Desechable.h"
#include "Cliente.h"

using namespace std;

class Cafeteria {
private:
    string nombre;
    float dinero;
    int contadorInsumo = 0;
    
    Cafe listaCafes[50];
    int contadorCafe = 0; 
    Polvo listaPolvos[50];
    int contadorPolvo = 0;
    Alimento listaAlimentos[50];
    int contadorAlimento = 0;
    Desechable listaDesechables[50];
    int contadorDesechable = 0;

    Cliente listaClientes[50];
    int contadorCliente = 0;

public:
    Cafeteria():nombre(""),dinero(0.0){}
    Cafeteria(string name,float money) {
        nombre = name;
        dinero = money;
    }

    void setNombre(string);
    string getNombre();
    float getDinero();

    void nuevoPolvo(string,string,float,int,string,float);
    void nuevoCafe(string,string,float,int,string,int,bool);
    void nuevoAlimento(string,string,float,int,string,bool);
    void nuevoDesechable(string,string,float,int,string,float);
    void nuevoCliente(string,string,bool);

    bool hayInsumos(int);

    stringstream mostrarPolvos();
    stringstream mostrarCafes();
    stringstream mostrarAlimentos();
    stringstream mostrarDesechables();
    stringstream mostrarInsumos(int,string);
    stringstream mostrarClientes();

    string usarIDinsumo(int,string,int);
    string agregarIDinsumo(int,string,int);

    double valorPolvos();
    double valorCafes();
    double valorAlimentos();
    double valorDesechables();
    double valorInventario(int,string);

    
   
};

void Cafeteria::setNombre(string name){
    nombre = name;
}
string Cafeteria::getNombre(){
    return nombre;
}
float Cafeteria::getDinero(){
    return dinero;
}

void Cafeteria::nuevoPolvo(string id,string name,float price,int quantity,string brand,float weight){
    if (contadorPolvo < 50){
        listaPolvos[contadorPolvo] = Polvo(id,name,price,quantity,brand,weight);
        contadorPolvo++;
        contadorInsumo++;
    } 
    else{
        cout << "El inventario de Polvo está lleno" << endl;
    }
}
void Cafeteria::nuevoCafe(string id,string name,float price,int quantity,string bean,int roast,bool whole){
    if (contadorCafe < 50){
        listaCafes[contadorCafe] = Cafe(id,name,price,quantity,bean,roast,whole);
        contadorCafe++;
        contadorInsumo++;
    } 
    else{
        cout << "El inventario de Cafe está lleno" << endl;
    }
}
void Cafeteria::nuevoAlimento(string id,string name,float price,int quantity,string type,bool fridge){
    if (contadorAlimento < 50){
        listaAlimentos[contadorAlimento] = Alimento(id,name,price,quantity,type,fridge);
        contadorAlimento++;
        contadorInsumo++;
    }
    else{
        cout << "El inventario de Alimento está lleno" << endl; 
    }
}
void Cafeteria::nuevoDesechable(string id,string name,float price,int quantity,string type,float size){
    if (contadorDesechable < 50){
        listaDesechables[contadorDesechable] = Desechable(id,name,price,quantity,type,size);
        contadorDesechable++;
        contadorInsumo++;
    }
    else{
        cout << "El inventario de Desechable está lleno" << endl;
    }
}
void Cafeteria::nuevoCliente(string name,string mail,bool allergy){
    if (contadorCliente < 50) {
        listaClientes[contadorCliente] = Cliente(name,mail,allergy);
        contadorCliente++;
    }
}

stringstream Cafeteria::mostrarPolvos(){
    stringstream aux;
    if(contadorPolvo == 0){
        aux << endl;
        aux << "No hay polvos" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Polvos" << endl;
        for(int i = 0;i<contadorPolvo;i++){
            aux << endl;
            aux << "ID: " << listaPolvos[i].getID() << endl;
            aux << "Nombre: " << listaPolvos[i].getNombre() << endl;
            aux << "Marca: " << listaPolvos[i].getMarca() << endl;
            aux << "Peso: " << listaPolvos[i].getPeso() << endl;
            aux << "Cantidad en Inventario: " << listaPolvos[i].getCantidadInventario() << endl;
        }
    }
    return aux;
}
stringstream Cafeteria::mostrarCafes(){
    stringstream aux;
    if(contadorCafe == 0){
        aux << endl;
        aux << "No hay cafes" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Cafes" << endl;
        for(int i = 0;i<contadorCafe;i++){
            aux << endl;
            aux << "ID: " << listaCafes[i].getID() << endl;
            aux << "Nombre: " << listaCafes[i].getNombre() << endl;
            aux << "Tipo: " << listaCafes[i].getGrano() << endl;
            aux << "Tueste: " << listaCafes[i].getTueste() << endl;
            if (listaCafes[i].getEntero())
                aux << "Entero?: " << "Si" << endl;
            else
                aux << "Entero?: " << "No" << endl;
            aux << "Cantidad en Inventario: " << listaCafes[i].getCantidadInventario() << endl;
        }
    }
    return aux;
}
stringstream Cafeteria::mostrarAlimentos(){
    stringstream aux;
    if(contadorAlimento == 0){
        aux << endl;
        aux << "No hay alimentos" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Alimentos" << endl;
        for(int i = 0;i<contadorAlimento;i++){
            aux << endl;
            aux << "ID: " << listaAlimentos[i].getID() << endl;
            aux << "Nombre: " << listaAlimentos[i].getNombre() << endl;
            aux << "Tipo: " << listaAlimentos[i].getTipo() << endl;
            if (listaAlimentos[i].getRefrigeracion())
                aux << "Refrigeracion?: " << "Si" << endl;
            else
                aux << "Refrigeracion?: " << "No" << endl;
            aux << "Cantidad en Inventario: " << listaAlimentos[i].getCantidadInventario() << endl;
        }
    }
    return aux;
}
stringstream Cafeteria::mostrarDesechables(){
    stringstream aux;
    if(contadorDesechable == 0){
        aux << endl;
        aux << "No hay desechables" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Desechables" << endl;
        for(int i = 0;i<contadorDesechable;i++){
            aux << endl;
            aux << "ID: " << listaDesechables[i].getID() << endl;
            aux << "Nombre: " << listaDesechables[i].getNombre() << endl;
            aux << "Tipo: " << listaDesechables[i].getTipo() << endl;
            aux << "Tamanio: " << listaDesechables[i].getTamanio() << endl;
            aux << "Cantidad en Inventario: " << listaDesechables[i].getCantidadInventario() << endl;
        }
    }
    return aux;
}
stringstream Cafeteria::mostrarInsumos(int supplyType,string id = ""){
    stringstream aux;
    switch (supplyType){
        case 1:
            aux << mostrarPolvos().str();
            aux << mostrarCafes().str();
            aux << mostrarAlimentos().str();
            aux << mostrarDesechables().str();
            break;
        case 2:
            aux << mostrarPolvos().str();
            break;
        case 3:
            aux << mostrarCafes().str();
            break;
        case 4:
            aux << mostrarAlimentos().str();
            break;
        case 5:
            aux << mostrarDesechables().str();
            break;
        case 6:{
            for (int i = 0; i < contadorPolvo; i++){
                if (id == listaPolvos[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaPolvos[i].getID() << endl;
                    aux << "Nombre: " << listaPolvos[i].getNombre() << endl;
                    aux << "Marca: " << listaPolvos[i].getMarca() << endl;
                    aux << "Peso: " << listaPolvos[i].getPeso() << endl;
                    aux << "Cantidad en Inventario: " << listaPolvos[i].getCantidadInventario() << endl;
                }
            }
            for (int i = 0; i < contadorCafe; i++){
                if (id == listaCafes[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaCafes[i].getID() << endl;
                    aux << "Nombre: " << listaCafes[i].getNombre() << endl;
                    aux << "Tipo: " << listaCafes[i].getGrano() << endl;
                    aux << "Tueste: " << listaCafes[i].getTueste() << endl;
                    if (listaCafes[i].getEntero())
                        aux << "Entero?: " << "Si" << endl;
                    else
                        aux << "Entero?: " << "No" << endl;
                    aux << "Cantidad en Inventario: " << listaCafes[i].getCantidadInventario() << endl;
                }
            }
            for (int i = 0; i < contadorAlimento; i++){
                if (id == listaAlimentos[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaAlimentos[i].getID() << endl;
                    aux << "Nombre: " << listaAlimentos[i].getNombre() << endl;
                    aux << "Tipo: " << listaAlimentos[i].getTipo() << endl;
                    if (listaAlimentos[i].getRefrigeracion())
                        aux << "Refrigeracion?: " << "Si" << endl;
                    else
                        aux << "Refrigeracion?: " << "No" << endl;
                    aux << "Cantidad en Inventario: " << listaAlimentos[i].getCantidadInventario() << endl;
                }
            }
            for (int i = 0; i < contadorDesechable; i++){
                if (id == listaDesechables[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaDesechables[i].getID() << endl;
                    aux << "Nombre: " << listaDesechables[i].getNombre() << endl;
                    aux << "Tipo: " << listaDesechables[i].getTipo() << endl;
                    aux << "Tamanio: " << listaDesechables[i].getTamanio() << endl;
                    aux << "Cantidad en Inventario: " << listaDesechables[i].getCantidadInventario() << endl;
                }
            }
        }  
    }
    return aux;
}
stringstream Cafeteria::mostrarClientes(){    
    stringstream aux;
    if (contadorCliente == 0) {
        aux << "No hay clientes" << endl;
    }
    else {
        aux << endl;
        aux << endl;
        aux << "Clientes" << endl;
        for (int i = 0; i < contadorCliente; i++){
            aux << endl;
            aux << "Cliente " << (i + 1) << ": " << endl;
            aux << "Nombre: " << listaClientes[i].getNombre() << endl;
            aux << "Correo: " << listaClientes[i].getCorreo() << endl;
            if (listaClientes[i].getAlergias())
                aux << "Alergias?: " << "Si" << endl;
            else
                aux << "Alergias?: " << "No" << endl; 

        }
    }
    return aux;
}

bool Cafeteria::hayInsumos(int supplyType){
    switch(supplyType){
        case 1: 
            return contadorPolvo > 0;
        case 2: 
            return contadorCafe > 0;
        case 3: 
            return contadorAlimento > 0;
        case 4: 
            return contadorDesechable > 0;
        default:
            return false;
    }
}

string Cafeteria::usarIDinsumo(int supplyType,string id,int quantity){
    string out;
    switch(supplyType){
        case 1: {
            for(int i = 0;i < contadorPolvo;i++){
                if (id == listaPolvos[i].getID()){
                    if (listaPolvos[i].usarInsumo(quantity))
                        out = "Polvo utilizado";
                    else
                        out = "No hay suficiente del polvo";
                }
            }
            break;
        }
        case 2: {
            for(int i = 0;i < contadorCafe;i++){
                if (id == listaCafes[i].getID()){
                    if (listaCafes[i].usarInsumo(quantity))
                        out = "Cafe utilizado";
                    else
                        out = "No hay suficiente del cafe";
                }
            }
            break; 
        }
        case 3: {
            for(int i = 0;i < contadorAlimento;i++){
                if (id == listaAlimentos[i].getID()){
                    if (listaAlimentos[i].usarInsumo(quantity))
                        out = "Alimento utilizado";
                    else
                        out = "No hay suficiente del alimento";
                }
            }
            break;            
        }
        case 4: {
            for(int i = 0;i < contadorDesechable;i++){
                if (id == listaDesechables[i].getID()){
                    if (listaDesechables[i].usarInsumo(quantity))
                        out = "Desechable utilizado";
                    else
                        out = "No hay suficiente del desechable";
                }
            }
            break;
        }
        default: {
            out = "No se encontró el ID ingresado";
        }
    }
    return out;
}
string Cafeteria::agregarIDinsumo(int supplyType,string id,int quantity){
    string out;
    switch(supplyType){
        case 1: {
            for(int i = 0;i < contadorPolvo;i++){
                if (id == listaPolvos[i].getID()){
                    listaPolvos[i].agregarInsumo(quantity);
                    out = "Polvo agregado";
                }
            }
            break;
        }
        case 2: {
            for(int i = 0;i < contadorCafe;i++){
                if (id == listaCafes[i].getID()){
                    listaCafes[i].agregarInsumo(quantity);
                    out = "Cafe agregado";
                }
            }
            break; 
        }
        case 3: {
            for(int i = 0;i < contadorAlimento;i++){
                if (id == listaAlimentos[i].getID()){
                    listaAlimentos[i].agregarInsumo(quantity);
                    out = "Alimento agregado";
                }
            }
            break;            
        }
        case 4: {
            for(int i = 0;i < contadorDesechable;i++){
                if (id == listaDesechables[i].getID()){
                    listaDesechables[i].agregarInsumo(quantity);
                    out = "Desechable agregado";
                }
            }
            break;
        }
        default: {
            out = "No se encontró el ID ingresado";
        }
    }
    return out;
}

double  Cafeteria::valorPolvos(){
    double polvo = 0;
    for (int i = 0; i < contadorPolvo; i++){
        polvo += listaPolvos[i].valorInventario();
    }
    return polvo;
}
double  Cafeteria::valorCafes(){
    double cafe = 0;
    for (int i = 0; i < contadorCafe; i++){
        cafe += listaCafes[i].valorInventario();
    }
    return cafe;
}
double Cafeteria::valorAlimentos(){
    double alimento = 0;
    for (int i = 0; i < contadorAlimento; i++){
        alimento += listaAlimentos[i].valorInventario();
    }
    return alimento;
}
double Cafeteria::valorDesechables(){
    double desechable = 0;
    for (int i = 0; i < contadorDesechable; i++){
        desechable += listaDesechables[i].valorInventario();
    }
    return desechable;
}
double Cafeteria::valorInventario(int supplyType,string id = ""){
    double especial = 0;
    switch (supplyType){
        case 1:
            return valorPolvos() + valorCafes() + valorAlimentos() + valorDesechables();
        case 2:
            return valorPolvos();
        case 3:
            return valorCafes();
        case 4:
            return valorAlimentos();
        case 5:
            return valorDesechables();
        case 6:{
            for (int i = 0; i < contadorPolvo; i++){
                if (id == listaPolvos[i].getID()){
                    return listaPolvos[i].valorInventario();
                }
            }
            for (int i = 0; i < contadorCafe; i++){
                if (id == listaCafes[i].getID()){
                    return listaCafes[i].valorInventario();
                }            
            }
            for (int i = 0; i < contadorAlimento; i++){
                if (id == listaAlimentos[i].getID()){
                    return listaAlimentos[i].valorInventario();
                }
            }
            for (int i = 0; i < contadorDesechable; i++){
                if (id == listaDesechables[i].getID()){
                    return listaDesechables[i].valorInventario();
                }
            }
        }  
    }
    return 0.0;
}

#endif
