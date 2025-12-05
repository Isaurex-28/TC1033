#include <iostream>
#include <string>
#include <sstream>

//Inclusión de las clases
#include "Insumo.h"
#include "Polvo.h"
#include "Cafe.h"
#include "Alimento.h"
#include "Desechable.h"
#include "Cliente.h"
#include "Cafeteria.h"

using namespace std;

//Funciones para operar en el main

/*
* Función Tipos de Insumos que imprime los 4 tipos de Insumo
* en pantalla.
*/
void tiposInsumos(){
    cout << "1.- Polvo" << endl;
    cout << "2.- Cafe" << endl;
    cout << "3.- Alimento" << endl;
    cout << "4.- Desechable" << endl;
}

/*
* Función Crear Insumo que pide la información al usuario y manda
* a llamar las funciones de la clase cafetería.
*/
string crearInsumo(Cafeteria &c){
    // Se crean las variables que serán inputs del usuario
    string out;
    string id;
    string name;
    float price;
    int quantity;
    bool verification = true;
    int supplyType = 0;                        

    // Se imprimen los tipos de insumos
    cout << endl;
    cout << "Que tipo de insumo deseas crear (numero)" << endl;
    tiposInsumos();
    
    // Bucle que corre hasta que el usuario ingrese una respuesta correcta
    while (verification){
        cin >> supplyType;
        cin.ignore();
        // Condicional que verifica que la respuesta esté dentro de rango
        if (supplyType>=1 && supplyType<=4){
            // Se piden los atributos generales de Insumo
            cout << endl;
            cout << "ID: "; getline(cin, id);
            cout << "Nombre del Insumo: "; getline(cin, name);
            cout << "Precio Unitario: "; cin >> price;
            cout << "Cantidad en Inventario: "; cin >> quantity;
            verification = false;
        }
        else{
            cout << "Opcion no valida vuele a intentarlo" << endl;
        }
    }

    // Switch que pide los atributos específicos de cada tipo de Insumo
    switch (supplyType){
    
        case 1: {
            string brand;
            float weight;
            
            cin.ignore();
            cout << "Marca: "; getline(cin, brand);
            cout << "Peso Neto (Kg): "; cin >> weight;

            c.nuevoPolvo(id,name,price,quantity,brand,weight);
            out = "Se creo el nuevo polvo";
            break;
        }
        case 2: {
            string bean;
            int roast;
            bool whole;
            
            cin.ignore();
            cout << "Tipo de Grano: "; getline(cin, bean);
            cout << "Tueste (Escala de Agtron): "; cin >> roast;
            cout << "El grano es entero? (Si = 1 / No = 0): "; cin >> whole;

            c.nuevoCafe(id,name,price,quantity,bean,roast,whole);
            out = "Se creo el nuevo cafe";
            break;
        }
        case 3: {
            string type;
            bool fridge;
            
            cin.ignore();
            cout << "Tipo de Alimento: "; getline(cin, type);
            cout << "Necesita refrigerarse? (Si = 1 / No = 0): "; 
            cin >> fridge;

            c.nuevoAlimento(id,name,price,quantity,type,fridge);
            out = "Se creo el nuevo alimento";
            break;
        }
        case 4: {
            string type;
            float size;
            
            cin.ignore();
            cout << "Tipo de Desechable: "; getline(cin, type);
            cout << "Tamanio del Desechable"; cin >> size;

            c.nuevoDesechable(id,name,price,quantity,type,size);
            out = "Se creo el nuevo desechable";
            break;
        }
    }
    return out;
}

/*
* Función Crear Cliente que pide la información al usuario y manda
* a llamar la funcion de la clase cafetería.
*/
string crearCliente(Cafeteria &c){

    // Se defienen las variables para el constructor
    string out;
    string name;
    string mail;
    bool allergy;

    // Se preguntan al usuario los atributos del cliente
    cout << endl;
    cout << "Nombre del cliente: "; getline(cin, name);
    cout << "Correo electronico: "; getline(cin, mail);
    cout << "Tiene alergias? (Si = 1 / No = 0): "; cin >> allergy;

    //Se manda a llamar la función a cafeterìa
    c.nuevoCliente(name,mail,allergy);
    out = "Se registro el nuevo cliente";
    return out;

}

/*
* Función Agregar Insumo que pide la información al usuario y manda
* a llamar las funciones de la clase cafetería.
*/
string agregarInsumo(Cafeteria &c){
    // Se definen las variables para el constructor
    string id;
    int quantity;
    int supplyType = 0;
    bool verification = true;

    cout << "Tipo de insumo que deseas agregarle (numero)" << endl;
    tiposInsumos();

    // Bucle que se repite hasta que la opción del usuario sea correcta
    while (verification){
        cin >> supplyType;
        cin.ignore();
        // Condicional que verifica el rango correcto
        if (supplyType>=1 && supplyType<=4){    
            cout << c.mostrarInsumos(supplyType+1).str() << endl;;
            cout << "ID del insumo a agregarle: "; getline(cin, id);
            cout << "Cantidad del insumo a agregarle: "; cin >> quantity;
            verification = false;
        }
        else{
            cout << "Opcion no valida vuele a intentarlo" << endl;
        }
    }
    // Se manda a llamar a la funcion de cafetería
    string out = c.agregarIDinsumo(supplyType,id,quantity);
    return out;

}

string usarInsumo(Cafeteria &c){
    // Se definen las variables para el constructor
    string id;
    int quantity;
    string out;
    int supplyType = 0;
    bool verification = true;

    cout << endl;
    cout << "Que tipo de insumo deseas usar" << endl;
    tiposInsumos();

    // Bucle que se repite hasta que la opción del usuario sea correcta
    while (verification){
        cin >> supplyType;
        cin.ignore();
        // Condicional que verifica el rango correcto
        if (supplyType>=1 && supplyType<=4){    
            cout << c.mostrarInsumos(supplyType+1).str() << endl;
            if(c.hayInsumos(supplyType)){
                cout << "ID del insumo a utilizar: "; getline(cin, id);
                cout << "Cantidad del insumo a utilizar: "; cin >> quantity;
                // Se manda a llamar la funcion de cafetería
                out = c.usarIDinsumo(supplyType,id,quantity);
            }
            else{
                out = "No puedes usar insumos que no tienes";
            }
            verification = false;
        }
        else{
            cout << "Opcion no valida vuele a intentarlo" << endl;
        }
    }

    return out;
}



int main(){
    // Definición de variables necesarias para crear la cafetería
    string cafeName;
    float cafeMoney;
    
    // Se ingresan los datos necesarios para crear la cafetería
    cout << endl;
    cout << "Bienvenido, vamos a crear tu cafeteria" << endl;
    cout << endl;
    cout << "Nombre de tu cafeteria: "; getline(cin, cafeName);
    cout << "Dinero inicial de tu cafeteria (solo el numero): "; 
    cin >> cafeMoney;
    // Constructor de cafetería
    Cafeteria myCafe(cafeName,cafeMoney);
    cout << "Se creo tu cafeteria" << endl << endl;

    /* 
    * Variable booleana para que el programa corra hasta que el usuario
    * decide salir
    */
    bool menu = true; 
    
    // Bucle para el menú
    while (menu){

        int menuOption = 0;
        cout << "Selecciona el menu (numero): " << endl;
        cout << "1.- Insumos" << endl;
        cout << "2.- Clientes" << endl;
        cout << "3.- Salir" << endl;
        cin >> menuOption;

        if (menuOption == 1){
            bool insumoMenu = true;
            /* Bucle para permanecer en el menú de Insumos hasta que el
            * usuario desee regresar al menú principal
            */
            while (insumoMenu){
                int insumoOption = 0;
                cout << endl;
                cout << "Insumos" << endl;
                cout << "Selecciona la accion a realizar (numero)" << endl;
                cout << "1.- Crear Insumo" << endl;
                cout << "2.- Agregar Insumo" << endl;
                cout << "3.- Usar Insumo" << endl;
                cout << "4.- Mostrar Insumos" << endl;
                cout << "5.- Calcular Valor de Insumos en Inventario" << endl;
                cout << "6.- Regresar al menu principal" << endl;
                cin >> insumoOption;
                /* Switch que realiza las acciones del menú de Insumos
                * según lo que el usuario desea hacer
                */
                switch (insumoOption){
                    case 1: {
                        cout << endl;
                        cout << crearInsumo(myCafe) << endl;
                        break;
                    }
                    case 2: {
                        cout << endl;
                        cout << agregarInsumo(myCafe) << endl;
                        break;                        
                    }
                    case 3: {
                        cout << usarInsumo(myCafe) << endl;
                        break;                        
                    }
                    case 4: {
                        int supplyType = 0;
                        bool verification = true;
                        cout << endl;
                        cout << "1.- Mostrar todos" << endl;
                        cout << "2.- Polvos" << endl;
                        cout << "3.- Cafes" << endl;
                        cout << "4.- Alimentos" << endl;
                        cout << "5.- Desechables" << endl;
                        cout << "6.- Insumo especifico ID" << endl;                            
                        
                        while (verification){
                            cin >> supplyType;
                            string id;
                            if (supplyType>=1 && supplyType <=6){
                                if (supplyType == 6){
                                    cout << "ID del insumo" << endl;
                                    cin.ignore();
                                    cin >> id;
                                    cout << 
                                    myCafe.mostrarInsumos(supplyType,id).str() 
                                << endl;
                                }
                                else{
                                    cout << 
                                    myCafe.mostrarInsumos(supplyType).str() 
                                    << endl;
                                }
                                verification = false;
                            }
                            else{
                                cout << "Opcion no valida vuelve a intentarlo"
                                << endl;
                            }
                        }
                        break;
                    }
                    case 5: {
                        int supplyType = 0;
                        bool verification = true;
                        cout << "1.- Calcular todos" << endl;
                        cout << "2.- Polvos" << endl;
                        cout << "3.- Cafes" << endl;
                        cout << "4.- Alimentos" << endl;
                        cout << "5.- Desechables" << endl;
                        cout << "6.- Insumo especifico ID" << endl;
                        
                        while (verification){
                            cin >> supplyType;
                            if(supplyType>=1 && supplyType<=6){
                                if (supplyType == 6){
                                    string id;
                                    cout << "ID del insumo" << endl;
                                    cin >> id;
                                    cout << "Valor: ";
                                    cout << 
                                    myCafe.valorInventario(supplyType,id)
                                    << endl;
                                }
                                else{
                                    cout << "Valor: ";
                                    cout << myCafe.valorInventario(supplyType) 
                                    << endl;
                                }
                                verification = false;
                            }
                            else{
                                cout << "Opciion no valida vuelve a intentarlo"
                                << endl;
                            }
                        }
                        break;
                    }
                    case 6:
                        insumoMenu = false;
                        break;
                    default:
                        cout << "Opcion no valida vuelve a intentarlo" << endl; 
                }
            }
        }
        else if (menuOption == 2){
            bool clienteMenu = true;
            /* Bucle para permanecer en el menú de Clientes hasta que el
            * usuario desee regresar al menú principal
            */
            while (clienteMenu){
                int clienteOption = 0;
                cout << endl;
                cout << "Clientes" << endl;
                cout << "Selecciona la accion a realizar (numero)" << endl;
                cout << "1.- Registrar Cliente" << endl;
                cout << "2.- Mostrar Clientes" << endl;
                cout << "3.- Regresar al menu principal" << endl;
                cin >> clienteOption;

                switch (clienteOption){
                    case 1: {
                        cout << crearCliente(myCafe) << endl;
                        break;
                    }
                    case 2: {
                        cout << myCafe.mostrarClientes().str() << endl;
                        break;
                    }
                    case 3: {}
                        clienteMenu = false;
                        break;
                    default:
                        cout << "Opcion no valida vuelve a intentarlo" << endl;       
                }
            }
        }
        // Se rompe el cilclo while y se termina el programa
        else if (menuOption == 3){
            menu = false;
        }
        else{
            cout << "Opcion no valida vuelve a intentarlo" << endl;
        } 
    }
}
