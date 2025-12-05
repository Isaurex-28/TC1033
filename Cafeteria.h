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

/*
* Clase principal del programa que se encarga de manejar directamente
* el inventario de los insumos y los clientes, así como operar las 
* funciones que se llaman desde el main
*/


class Cafeteria {
private:
    // Atributos de la cafetería
    string nombre;
    float dinero;
    int contadorInsumo = 0;
    
    /*
    * Se crean listas para cada tipo de insumo así como contadores para
    * poder crear nuevos insumos sin sobreescribir lo que se tiene
    */

    Cafe listaCafes[50];
    int contadorCafe = 0; 
    Polvo listaPolvos[50];
    int contadorPolvo = 0;
    Alimento listaAlimentos[50];
    int contadorAlimento = 0;
    Desechable listaDesechables[50];
    int contadorDesechable = 0;

    // Lista y contador de clientes
    Cliente listaClientes[50];
    int contadorCliente = 0;

public:
    /*
    * Constructor de cafetería que por default deja el nombre en blanco
    * y dinero vacío
    * 
    * @param
    * @return Objeto Cafeteria
    */
    Cafeteria():nombre(""),dinero(0.0){}
    
    /*
    * Constructor de cafetería
    * 
    * @param string name: nombre de la cafetería, float money: dinero
    * inicial de la cafetería
    * @return
    */
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

// Setters y Getters (no se incluye setDinero por seguridad)
void Cafeteria::setNombre(string name){
    nombre = name;
}
string Cafeteria::getNombre(){
    return nombre;
}
float Cafeteria::getDinero(){
    return dinero;
}

/*
* Funcion para crear un polvo nuevo 
* 
* @param string id: ID del insumo, string name: nombre del insumo,
* float price: costo unitario, int quantity: cantidad en inventario,
* string brand: marca del polvo, float weight: peso del empaque
* @return
*/
void Cafeteria::nuevoPolvo(string id,string name,float price,
                            int quantity,string brand,float weight){
    // Se verifica si todavía hay espacio en el inventario de polvos
    if (contadorPolvo < 50){
        // Se crea un nuevo Polvo en la lista
        listaPolvos[contadorPolvo] = Polvo(id,name,price,
                                        quantity,brand,weight);
        // Se aumentan los contadores de Polvo e Insumo
        contadorPolvo++;
        contadorInsumo++;
    } 
    else{
        // Si el inventario está lleno se deja saber al usuario
        cout << "El inventario de Polvo está lleno" << endl;
    }
}

/*
* Funcion para crear un cafe nuevo 
* 
* @param string id: ID del insumo, string name: nombre del insumo,
* float price: costo unitario, int quantity: cantidad en inventario,
* string bean: tipo de grano, int roast: tueste del grano, 
* bool whole: el grano es entero?
* @return
*/
void Cafeteria::nuevoCafe(string id,string name,float price,int quantity,
                                        string bean,int roast,bool whole){
    // Se verifica si todavía hay espacio en el inventario de Cafes
    if (contadorCafe < 50){
        // Se crea un nuevo Cafe en la lista
        listaCafes[contadorCafe] = Cafe(id,name,price,quantity,
                                                        bean,roast,whole);
        // Se aumentan los contadores de Cafe e Insumo
        contadorCafe++;
        contadorInsumo++;
    } 
    else{
        // Si el inventario está lleno se deja saber al usuario
        cout << "El inventario de Cafe está lleno" << endl;
    }
}

/*
* Funcion para crear un alimento nuevo 
* 
* @param string id: ID del insumo, string name: nombre del insumo,
* float price: costo unitario, int quantity: cantidad en inventario,
* string type: tipo de alimento, bool fridge: requiere refrigeración?
* @return
*/
void Cafeteria::nuevoAlimento(string id,string name,float price,
                                        int quantity,string type,bool fridge){
    // Se verifica si todavía hay espacio en el inventario de Alimentos
    if (contadorAlimento < 50){
        // Se crea un nuevo Alimento en la lista
        listaAlimentos[contadorAlimento] = Alimento(id,name,price,
                                                        quantity,type,fridge);
        // Se aumentan los contadores de Alimento e Insumo
        contadorAlimento++;
        contadorInsumo++;
    }
    else{
        // Si el inventario está lleno se deja saber al usuario
        cout << "El inventario de Alimento está lleno" << endl; 
    }
}

/*
* Funcion para crear un desechable nuevo 
* 
* @param string id: ID del insumo, string name: nombre del insumo,
* float price: costo unitario, int quantity: cantidad en inventario,
* string type: tipo de desechable, float size: tamaño del desechable
* @return
*/
void Cafeteria::nuevoDesechable(string id,string name,float price,
                                        int quantity,string type,float size){
    // Se verifica si todavía hay espacio en el iventario de Desechables
    if (contadorDesechable < 50){
        // Se crea un nuevo Desechable en la lista
        listaDesechables[contadorDesechable] = Desechable(id,name,price,
                                                        quantity,type,size);
        // Se aumentan los contadores de Desechable e Insumo
        contadorDesechable++;
        contadorInsumo++;
    }
    else{
        // Si el inventario está lleno se deja saber al usuario
        cout << "El inventario de Desechable está lleno" << endl;
    }
}

/*
* Funcion para crear un cliente nuevo 
* 
* @param string name: nombre del cliente, 
* string mail: correo electrónico del cliente,
* bool allergy: tiene alergias?
* @return
*/
void Cafeteria::nuevoCliente(string name,string mail,bool allergy){
    // Se verifica si todavía hay espacio en la lista de Clientes
    if (contadorCliente < 50) {
        // Se crea un nuevo cliente en la lista
        listaClientes[contadorCliente] = Cliente(name,mail,allergy);
        contadorCliente++;
    }
    else{
        // Si la lista está llena se deja saber al usuario
        cout << "La lista de clientes está llena" << endl;
    }
}

/*
* Función que verifica si hay insumos de cierto tipo
*
* @param int supplyType: tipo de insumo (se declara en el main)
* @return bool: hay de ese tipo de insumo en inventario?
*/
bool Cafeteria::hayInsumos(int supplyType){
    // Si los contadores son menores o iguales a 0 se regresa false
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

/*
* Función para mostrar los atributos de los objetos Polvo
*
* @param
* @return stringstream con los atributos de los Polvos
*/
stringstream Cafeteria::mostrarPolvos(){
    // Se declara un stringstream para guardar los atributos
    stringstream aux;
    // Se verifica si hay polvos en inventario
    if(contadorPolvo == 0){
        aux << endl;
        aux << "No hay polvos" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Polvos" << endl;
        // Para cada polvo se guardan sus atributos en aux
        for(int i = 0;i<contadorPolvo;i++){
            aux << endl;
            aux << "ID: " << listaPolvos[i].getID() << endl;
            aux << "Nombre: " << listaPolvos[i].getNombre() << endl;
            aux << "Marca: " << listaPolvos[i].getMarca() << endl;
            aux << "Peso: " << listaPolvos[i].getPeso() << endl;
            aux << "Cantidad en Inventario: " 
                << listaPolvos[i].getCantidadInventario() << endl;
        }
    }
    // Se regresa aux con todos los atributos de todos los polvos
    return aux;
}

/*
* Función para mostrar los atributos de los objetos Cafe
*
* @param
* @return stringstream con los atributos de los Cafes
*/
stringstream Cafeteria::mostrarCafes(){
    // Se declara un stringstream para guardar los atributos
    stringstream aux;
    // Se verifica si hay cafes en inventario
    if(contadorCafe == 0){
        aux << endl;
        aux << "No hay cafes" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Cafes" << endl;
        // Para cada cafe se guardan sus atributos en aux
        for(int i = 0;i<contadorCafe;i++){
            aux << endl;
            aux << "ID: " << listaCafes[i].getID() << endl;
            aux << "Nombre: " << listaCafes[i].getNombre() << endl;
            aux << "Tipo: " << listaCafes[i].getGrano() << endl;
            aux << "Tueste: " << listaCafes[i].getTueste() << endl;
            // Se guardan los 0 y 1 de bool como Si y No
            if (listaCafes[i].getEntero())
                aux << "Entero?: " << "Si" << endl;
            else
                aux << "Entero?: " << "No" << endl;
            aux << "Cantidad en Inventario: " 
                << listaCafes[i].getCantidadInventario() << endl;
        }
    }
    // Se regresa aux con todos los atributos de todos los cafes
    return aux;
}

/*
* Función para mostrar los atributos de los objetos Alimento
*
* @param
* @return stringstream con los atributos de los Alimentos
*/
stringstream Cafeteria::mostrarAlimentos(){
    // Se declara un stringstream para guardar los atributos
    stringstream aux;
    // Se verifica si hay alimentos en inventario
    if(contadorAlimento == 0){
        aux << endl;
        aux << "No hay alimentos" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Alimentos" << endl;
        // Para cada alimento se guardan sus atributos en aux
        for(int i = 0;i<contadorAlimento;i++){
            aux << endl;
            aux << "ID: " << listaAlimentos[i].getID() << endl;
            aux << "Nombre: " << listaAlimentos[i].getNombre() << endl;
            aux << "Tipo: " << listaAlimentos[i].getTipo() << endl;
            // Se guardan los 0 y 1 de bool como Si y NO
            if (listaAlimentos[i].getRefrigeracion())
                aux << "Refrigeracion?: " << "Si" << endl;
            else
                aux << "Refrigeracion?: " << "No" << endl;
            aux << "Cantidad en Inventario: " 
                << listaAlimentos[i].getCantidadInventario() << endl;
        }
    }
    // Se regresa aux con todos los atributos de todos los alimentos
    return aux;
}

/*
* Función para mostrar los atributos de los objetos Desechable
*
* @param
* @return stringstream con los atributos de los Desechables
*/
stringstream Cafeteria::mostrarDesechables(){
    // Se declara un stringstream para guardar los atributos
    stringstream aux;
    // Se verifica si hay desechables en inventario
    if(contadorDesechable == 0){
        aux << endl;
        aux << "No hay desechables" << endl;
    }
    else{
        aux << endl;
        aux << endl;
        aux << "Desechables" << endl;
        // Para cada desechable se guardan sus atributos en aux
        for(int i = 0;i<contadorDesechable;i++){
            aux << endl;
            aux << "ID: " << listaDesechables[i].getID() << endl;
            aux << "Nombre: " << listaDesechables[i].getNombre() << endl;
            aux << "Tipo: " << listaDesechables[i].getTipo() << endl;
            aux << "Tamanio: " << listaDesechables[i].getTamanio() << endl;
            aux << "Cantidad en Inventario: " 
                << listaDesechables[i].getCantidadInventario() << endl;
        }
    }
    // Se regresa aux con todos los atributos de todos los desechables
    return aux;
}

/*
* Función para mostrar los atributos todos los insumos, de un tipo de
* insumo o de un objeto específicado desde el main
* 
* @param int supplyType: tipo de Insumo a mostrar, 
* (en caso de específicar un objeto) string id: ID del objeto a mostrar
* @return stringstream con los atributos del/los insumo(s) solicitado(s) 
*/
stringstream Cafeteria::mostrarInsumos(int supplyType,string id = ""){
    // Se declara un stringstream para guardar los atributos
    stringstream aux;
    switch (supplyType){
        case 1:
            // Se guardan los atributos de todos los Insumos en aux
            aux << mostrarPolvos().str();
            aux << mostrarCafes().str();
            aux << mostrarAlimentos().str();
            aux << mostrarDesechables().str();
            break;
        case 2:
            // Se guardan los atributos de los Povos en aux
            aux << mostrarPolvos().str();
            break;
        case 3:
            // Se guardan los atributos de los Cafes en aux
            aux << mostrarCafes().str();
            break;
        case 4:
            // Se guardan los atributos de los Alimentos en aux
            aux << mostrarAlimentos().str();
            break;
        case 5:
            // Se guardan los atributos de los Desechables en aux
            aux << mostrarDesechables().str();
            break;
        case 6:{
            /* 
            * Se busca en todos los Polvos un ID que coincida
            * se guardan sus atributos en aux
            */
            for (int i = 0; i < contadorPolvo; i++){
                if (id == listaPolvos[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaPolvos[i].getID() << endl;
                    aux << "Nombre: " << listaPolvos[i].getNombre() << endl;
                    aux << "Marca: " << listaPolvos[i].getMarca() << endl;
                    aux << "Peso: " << listaPolvos[i].getPeso() << endl;
                    aux << "Cantidad en Inventario: " 
                        << listaPolvos[i].getCantidadInventario() << endl;
                }
            }
            /* 
            * Se busca en todos los Cafes un ID que coincida
            * se guardan sus atributos en aux
            */
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
                    aux << "Cantidad en Inventario: " 
                        << listaCafes[i].getCantidadInventario() << endl;
                }
            }
            /* 
            * Se busca en todos los Alimentos un ID que coincida
            * se guardan sus atributos en aux
            */
            for (int i = 0; i < contadorAlimento; i++){
                if (id == listaAlimentos[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaAlimentos[i].getID() << endl;
                    aux << "Nombre: " 
                        << listaAlimentos[i].getNombre() << endl;
                    aux << "Tipo: " << listaAlimentos[i].getTipo() << endl;
                    if (listaAlimentos[i].getRefrigeracion())
                        aux << "Refrigeracion?: " << "Si" << endl;
                    else
                        aux << "Refrigeracion?: " << "No" << endl;
                    aux << "Cantidad en Inventario: " 
                        << listaAlimentos[i].getCantidadInventario() << endl;
                }
            }
            /* 
            * Se busca en todos los Desechables un ID que coincida
            * se guardan sus atributos en aux
            */
            for (int i = 0; i < contadorDesechable; i++){
                if (id == listaDesechables[i].getID()){
                    aux << endl;
                    aux << "ID: " << listaDesechables[i].getID() << endl;
                    aux << "Nombre: " 
                        << listaDesechables[i].getNombre() << endl;
                    aux << "Tipo: " << listaDesechables[i].getTipo() << endl;
                    aux << "Tamanio: " 
                        << listaDesechables[i].getTamanio() << endl;
                    aux << "Cantidad en Inventario: " 
                        << listaDesechables[i].getCantidadInventario() << endl;
                }
            }
        }  
    }
    /*
    * Se regresa aux con la información almacenada segun el usuario 
    * requirio
    */
    return aux;
}

/*
* Función para mostrar los atributos de los objetos Cliente
*
* @param
* @return stringstream con los atributos de los Clientes
*/
stringstream Cafeteria::mostrarClientes(){    
    // Se declara un stringstream para guardar los atributos
    stringstream aux;
    // Se verifica que haya clientes registrados
    if (contadorCliente == 0) {
        aux << "No hay clientes" << endl;
    }
    else {
        aux << endl;
        aux << endl;
        aux << "Clientes" << endl;
        // Para cada cliente se guardan sus atributos en aux
        for (int i = 0; i < contadorCliente; i++){
            aux << endl;
            aux << "Cliente " << (i + 1) << ": " << endl;
            aux << "Nombre: " << listaClientes[i].getNombre() << endl;
            aux << "Correo: " << listaClientes[i].getCorreo() << endl;
            // Se guardan los 0 y 1 de bool como Si y No
            if (listaClientes[i].getAlergias())
                aux << "Alergias?: " << "Si" << endl;
            else
                aux << "Alergias?: " << "No" << endl; 

        }
    }
    // Se regresa aux con todos los atributos de todos los clientes
    return aux;
}


/*
* Función para utilizar un insumo según sea requerido por el usuario
* desde el main
*
* @param int supplyType: tipo de insumo, string id: ID del insumo
* int quantity: cantidad a utilizar
* @return string con el estatus de la operación
*/
string Cafeteria::usarIDinsumo(int supplyType,string id,int quantity){
    // Se declara un string para regresar el estatus de la operación
    string out;
    // Switch que busca en los arreglos según el tipo de insumo
    switch(supplyType){
        case 1: {
            /*
            * Se busca en todos los polvos un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorPolvo;i++){
                if (id == listaPolvos[i].getID()){
                    // Se verifica que haya suficiente del Polvo
                    if (listaPolvos[i].usarInsumo(quantity))
                        // Se utiliza la cantidad de ese Polvo
                        out = "Polvo utilizado";
                    else
                        out = "No hay suficiente del polvo";
                }
            }
            break;
        }
        case 2: {
            /*
            * Se busca en todos los cafes un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorCafe;i++){
                if (id == listaCafes[i].getID()){
                    // Se verifica que haya suficiente del Cafe
                    if (listaCafes[i].usarInsumo(quantity))
                        // Se utiliza la cantidad de ese Cafe
                        out = "Cafe utilizado";
                    else
                        out = "No hay suficiente del cafe";
                }
            }
            break; 
        }
        case 3: {
            /*
            * Se busca en todos los alimentos un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorAlimento;i++){
                if (id == listaAlimentos[i].getID()){
                    // Se verifica que haya suficiente del Alimento
                    if (listaAlimentos[i].usarInsumo(quantity))
                        // Se utiliza la cantidad de ese Alimento
                        out = "Alimento utilizado";
                    else
                        out = "No hay suficiente del alimento";
                }
            }
            break;            
        }
        case 4: {
            /*
            * Se busca en todos los desechables un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorDesechable;i++){
                // Se verifica que haya suficiente del Desechable
                if (id == listaDesechables[i].getID()){
                    // Se utiliza la cantidad de ese Desechable
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
    // Se regresa el estatus de la operación
    return out;
}

/*
* Función para agregar a un insumo según sea requerido por el usuario
* desde el main
*
* @param int supplyType: tipo de Insumo, string id: ID del insumo
* int quantity: cantidad a agregar
* @return string con el estatus de la operación
*/
string Cafeteria::agregarIDinsumo(int supplyType,string id,int quantity){
    // Se declara un string para regresar el estatus de la operación
    string out;
    // Switch que busca en los arreglos según el tipo de insumo
    switch(supplyType){
        case 1: {
            /*
            * Se busca en todos los polvos un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorPolvo;i++){
                if (id == listaPolvos[i].getID()){
                    // Se agrega la cantidad de ese Polvo
                    listaPolvos[i].agregarInsumo(quantity);
                    out = "Polvo agregado";
                }
            }
            break;
        }
        case 2: {
            /*
            * Se busca en todos los cafes un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorCafe;i++){
                if (id == listaCafes[i].getID()){
                    // Se agrega la cantidad de ese Cafe
                    listaCafes[i].agregarInsumo(quantity);
                    out = "Cafe agregado";
                }
            }
            break; 
        }
        case 3: {
            /*
            * Se busca en todos los alimentos un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorAlimento;i++){
                if (id == listaAlimentos[i].getID()){
                    // Se agrega la cantidad de ese Alimento
                    listaAlimentos[i].agregarInsumo(quantity);
                    out = "Alimento agregado";
                }
            }
            break;            
        }
        case 4: {
            /*
            * Se busca en todos los desechables un ID que coincida con 
            * requerido
            */
            for(int i = 0;i < contadorDesechable;i++){
                if (id == listaDesechables[i].getID()){
                    // Se agrega la cantidad de ese Desechable
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
    // Se regresa el estatus de la operacion
    return out;
}

/*
* Función para regresar el valor total de los Polvos en inventario
*
* @param 
* @return double con el valor total de Polvos
*/
double  Cafeteria::valorPolvos(){
    // Se declara una variable donde almacenar los valores
    double polvo = 0;
    // Para cada polvo, se suma su valor a la variable polvo
    for (int i = 0; i < contadorPolvo; i++){
        polvo += listaPolvos[i].valorInventario();
    }
    // Se regresa el valor de los polvos
    return polvo;
}

/*
* Función para regresar el valor total de los Cafes en inventario
*
* @param 
* @return double con el valor total de Cafes
*/
double  Cafeteria::valorCafes(){
    // Se declara una variable donde almacenar los valores
    double cafe = 0;
    // Para cada cafe, se suma su valor a la variable cafe
    for (int i = 0; i < contadorCafe; i++){
        cafe += listaCafes[i].valorInventario();
    }
    // Se regresa el valor de los cafes
    return cafe;
}

/*
* Función para regresar el valor total de los Alimentos en inventario
*
* @param 
* @return double con el valor total de Alimentos
*/
double Cafeteria::valorAlimentos(){
    // Se declara una variable donde almacenar los valores
    double alimento = 0;
    // Para cada alimento, se suma su valor a la variable alimento
    for (int i = 0; i < contadorAlimento; i++){
        alimento += listaAlimentos[i].valorInventario();
    }
    // Se regresa el valor de los alimentos
    return alimento;
}

/*
* Función para regresar el valor total de los Desechables en inventario
*
* @param 
* @return double con el valor total de Desechables
*/
double Cafeteria::valorDesechables(){
    // Se declara una variable donde almacenar los valores
    double desechable = 0;
    // Para cada desechable, se suma su valor a la variable desechable
    for (int i = 0; i < contadorDesechable; i++){
        desechable += listaDesechables[i].valorInventario();
    }
    // Se regresa el valor de los desechables
    return desechable;
}

/*
* Función para regresar el valor de un tipo de insumo,
* el valor total del inventario o el valor de un objeto específico
*
* @param int supplyType: tipo de Insumo 
* (en caso de específicar un objeto) string id: ID del objeto
* @return double con el valor total de lo solicitado por el usuario
*/
double Cafeteria::valorInventario(int supplyType,string id = ""){
    // Se declara una variable donde almacenar los valores
    double especial = 0;
    // Switch para obtener el valor segun el tipo de insumo
    switch (supplyType){
        case 1:
            // Se regresa la suma de los valores de todos los Insumos
            return valorPolvos() + valorCafes() + valorAlimentos() 
                   + valorDesechables();
        case 2:
            // Se regresa la suma del valor de todos los Polvos
            return valorPolvos();
        case 3:
            // Se regresa la suma del valor de todos los Cafes
            return valorCafes();
        case 4:
            // Se regresa la suma del valor de todos los Alimentos
            return valorAlimentos();
        case 5:
            // Se regresa la suma del valor de todos los Desechables
            return valorDesechables();
        case 6:{
            /*
            * Se busca en todos los polvos un ID que coincida con 
            * requerido
            */
            for (int i = 0; i < contadorPolvo; i++){
                if (id == listaPolvos[i].getID()){
                    // Se regresa el valor del Polvo 
                    return listaPolvos[i].valorInventario();
                }
            }
            /*
            * Se busca en todos los cafes un ID que coincida con 
            * requerido
            */
            for (int i = 0; i < contadorCafe; i++){
                if (id == listaCafes[i].getID()){
                    // Se regresa el valor del Cafe
                    return listaCafes[i].valorInventario();
                }            
            }
            /*
            * Se busca en todos los alimentos un ID que coincida con 
            * requerido
            */
            for (int i = 0; i < contadorAlimento; i++){
                if (id == listaAlimentos[i].getID()){
                    // Se regresa el valor del Alimento
                    return listaAlimentos[i].valorInventario();
                }
            }
            /*
            * Se busca en todos los desechables un ID que coincida con 
            * requerido
            */
            for (int i = 0; i < contadorDesechable; i++){
                if (id == listaDesechables[i].getID()){
                    // Se regresa el valor del Desechable
                    return listaDesechables[i].valorInventario();
                }
            }
        }  
    }
    // En caso de no encontrar la opcion se regresa 0
    return 0.0;
}

#endif

