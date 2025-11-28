#include <iostream>
#include <string>
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

    void nuevoCafe(Cafe);
    void nuevoPolvo(Polvo);
    void nuevoAlimento(Alimento);
    void nuevoDesechable(Desechable);

    void nuevoCliente(Cliente);

    void mostrarInsumos();
    void mostrarClientes();
    
   
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


void Cafeteria::nuevoCafe(Cafe c){
    if (contadorCafe < 50){
        listaCafes[contadorCafe] = c;
        contadorCafe++;
        contadorInsumo++;
    } 
    else{
        cout << "El inventario de Cafe está lleno" << endl;
    }
}

void Cafeteria::nuevoPolvo(Polvo p){
    if (contadorPolvo < 50){
        listaPolvos[contadorPolvo] = p;
        contadorPolvo++;
        contadorInsumo++;
    } 
    else{
        cout << "El inventario de Polvo está lleno" << endl;
    }
}

void Cafeteria::nuevoAlimento(Alimento a){
    if (contadorAlimento < 50){
        listaAlimentos[contadorAlimento] = a;
        contadorAlimento++;
        contadorInsumo++;
    }
    else{
        cout << "El inventario de Alimento está lleno" << endl; 
    }
}

void Cafeteria::nuevoDesechable(Desechable d){
    if (contadorDesechable < 50){
        listaDesechables[contadorDesechable] = d;
        contadorDesechable++;
        contadorInsumo++;
    }
    else{
        cout << "El inventario de Desechable está lleno" << endl;
    }
}


void Cafeteria::nuevoCliente(Cliente c) {
    if (contadorCliente < 50) {
        listaClientes[contadorCliente] = c;
        contadorCliente++;
    } 
    else {
        cout << "La lista de clientes está llena." << endl;
    }
}
void Cafeteria::mostrarInsumos(){
    if(contadorInsumo == 0){
        cout << "No hay insumos" << endl;
        return;
    }
    cout << "Polvos" << endl;
    for(int i = 0;i<contadorPolvo;i++){
        cout << "ID: " << listaPolvos[i].getID() << endl;
        cout << "Nombre: " << listaPolvos[i].getNombre() << endl;
        cout << "Marca: " << listaPolvos[i].getMarca() << endl;
        cout << "Peso: " << listaPolvos[i].getPeso() << endl;
    }

    cout << "Cafes" << endl;
    for(int i = 0;i<contadorCafe;i++){
        cout << "ID: " << listaCafes[i].getID() << endl;
        cout << "Nombre: " << listaCafes[i].getNombre() << endl;
        cout << "Tipo: " << listaCafes[i].getGrano() << endl;
        cout << "Tueste: " << listaCafes[i].getTueste() << endl;
        cout << "Entero?: " << listaCafes[i].getEntero() << endl;
    }

    cout << "Alimentos" << endl;
    for(int i = 0;i<contadorAlimento;i++){
        cout << "ID: " << listaAlimentos[i].getID() << endl;
        cout << "Nombre: " << listaAlimentos[i].getNombre() << endl;
        cout << "Tipo: " << listaAlimentos[i].getTipo() << endl;
        cout << "Refrigeración?: " << listaAlimentos[i].getRefrigeracion() << endl;
    }

    cout << "Desechables" << endl;
    for(int i = 0;i<contadorDesechable;i++){
        cout << "ID: " << listaDesechables[i].getID() << endl;
        cout << "Nombre: " << listaDesechables[i].getNombre() << endl;
        cout << "Tipo: " << listaDesechables[i].getTipo() << endl;
        cout << "Tamanio: " << listaDesechables[i].getTamanio() << endl;
    }
}


void Cafeteria::mostrarClientes(){    
    if (contadorCliente == 0) {
        cout << "No hay clientes" << endl;
        return;
    }
    for (int i = 0; i < contadorCliente; i++){
        cout << "Cliente" << (i + 1) << ": " << endl;
        cout << "Nombre: " << listaClientes[i].getNombre() << endl;
        cout << "Correo: " << listaClientes[i].getCorreo() << endl;
        cout << "Alergias?: " << listaClientes[i].getAlergias() << endl;
    }
}