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
string crearInsumo(Cafeteria &c,int supplyType){
    string out;
    string id;
    string name;
    float price;
    int quantity;

    cout << endl;
    cout << "Recuerda usar '_'en vez de espacios" << endl;
    cout << "ID: "; cin >> id;
    cout << "Nombre del Insumo: "; cin >> name;
    cout << "Precio Unitario: "; cin >> price;
    cout << "Cantidad en Inventario: "; cin >> quantity;
    
    switch (supplyType){
        case 1: {
            string brand;
            float weight;
            
            cout << "Marca: "; cin >> brand;
            cout << "Peso Neto (Kg): "; cin >> weight;

            c.nuevoPolvo(id,name,price,quantity,brand,weight);
            out = "Se creo el nuevo polvo";
            break;
        }
        case 2: {
            string bean;
            int roast;
            bool whole;
            
            cout << "Tipo de Grano: "; cin >> bean;
            cout << "Tueste (Escala de Agtron): "; cin >> roast;
            cout << "El grano es entero? (Si = 1 / No = 0): "; cin >> whole;

            c.nuevoCafe(id,name,price,quantity,bean,roast,whole);
            out = "Se creo el nuevo cafe";
            break;
        }
        case 3: {
            string type;
            bool fridge;
            
            cout << "Tipo de Alimento: "; cin >> type;
            cout << "Necesita refrigerarse? (Si = 1 / No = 0): "; cin >> fridge;

            c.nuevoAlimento(id,name,price,quantity,type,fridge);
            out = "Se creo el nuevo alimento";
            break;
        }
        case 4: {
            string type;
            float size;
            
            cout << "Tipo de Desechable: "; cin >> type;
            cout << "Tamanio del Desechable"; cin >> size;

            c.nuevoDesechable(id,name,price,quantity,type,size);
            out = "Se creo el nuevo desechable";
            break;
        }
    }
    return out;
}

string crearCliente(Cafeteria &c){
    string out;
    string name;
    string mail;
    bool allergy;

    cout << endl;
    cout << "Recuerda usar '_'en vez de espacios" << endl;
    cout << "Nombre del cliente: "; cin >> name;
    cout << "Correo electronico: "; cin >> mail;
    cout << "Tiene alergias? (Si = 1 / No = 0): "; cin >> allergy;

    c.nuevoCliente(name,mail,allergy);
    out = "Se registro el nuevo cliente";
    return out;

}

string agregarInsumo(Cafeteria &c,int supplyType){
    string id;
    int quantity;
    cout << c.mostrarInsumos(supplyType+1).str() << endl;;
    cout << "ID del insumo a agregarle: "; cin >> id;
    cout << "Cantidad del insumo a agregarle: "; cin >> quantity;
    string out = c.agregarIDinsumo(supplyType,id,quantity);
    return out;

}

string usarInsumo(Cafeteria &c,int supplyType){
    string id;
    int quantity;
    string out;
    cout << c.mostrarInsumos(supplyType+1).str() << endl;
    if(c.hayInsumos(supplyType)){
        cout << "ID del insumo a utilizar: "; cin >> id;
        cout << "Cantidad del insumo a utilizar: "; cin >> quantity;
        out = c.usarIDinsumo(supplyType,id,quantity);
    }
    else{
        out = "No puedes usar insumos que no tienes";
    }
    return out;
}

void tiposInsumos(){
    cout << "1.- Polvo" << endl;
    cout << "2.- Cafe" << endl;
    cout << "3.- Alimento" << endl;
    cout << "4.- Desechable" << endl;
}



int main(){
    string cafeName;
    float cafeMoney;
    
    cout << "Bienvenido, vamos a crear tu cafeteria" << endl;
    cout << endl;
    cout << "Nombre de tu cafeteria (Recuerda usar '_' en vez de espacio): "; cin >> cafeName;
    cout << "Dinero inicial de tu cafeteria (solo el numero): "; cin >> cafeMoney;
    Cafeteria myCafe(cafeName,cafeMoney);
    cout << "Se creo tu cafeteria" << endl << endl;

    bool menu = true; 
    while (menu){

        int menuOption = 0;
        cout << "Selecciona el menu (numero): " << endl;
        cout << "1.- Insumos" << endl;
        cout << "2.- Clientes" << endl;
        cout << "3.- Salir" << endl;
        cin >> menuOption;

        if (menuOption == 1){
            bool insumoMenu = true;
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

                switch (insumoOption){
                    case 1: {
                        int supplyType = 0;
                        cout << endl;
                        cout << "Que tipo de insumo deseas crear (numero)" << endl;
                        tiposInsumos();
                        cin >> supplyType;
                        cout << crearInsumo(myCafe,supplyType) << endl;
                        break;
                    }
                    case 2: {
                        int supplyType = 0;
                        cout << endl;
                        cout << "A que tipo de insumo deseas agregarle (numero)" << endl;
                        tiposInsumos();
                        cin >> supplyType;
                        cout << agregarInsumo(myCafe,supplyType) << endl;
                        break;                        
                    }
                    case 3: {
                        int supplyType = 0;
                        cout << endl;
                        cout << "Que tipo de insumo deseas usar" << endl;
                        tiposInsumos();
                        cin >> supplyType;
                        cout << usarInsumo(myCafe,supplyType) << endl;
                        break;                        
                    }
                    case 4: {
                        int supplyType = 0;
                        cout << endl;
                        cout << "1.- Mostrar todos" << endl;
                        cout << "2.- Polvos" << endl;
                        cout << "3.- Cafes" << endl;
                        cout << "4.- Alimentos" << endl;
                        cout << "5.- Desechables" << endl;
                        cout << "6.- Insumo especifico ID" << endl;
                        cin >> supplyType;
                        if (supplyType == 6){
                            string id;
                            cout << "ID del insumo" << endl;
                            cin >> id;
                            cout << myCafe.mostrarInsumos(supplyType,id).str() << endl;;
                        }
                        else{
                            cout << myCafe.mostrarInsumos(supplyType).str() << endl;;
                        }
                        break;
                    }
                    case 5: {
                        int supplyType = 0;
                        cout << "1.- Calcular todos" << endl;
                        cout << "2.- Polvos" << endl;
                        cout << "3.- Cafes" << endl;
                        cout << "4.- Alimentos" << endl;
                        cout << "5.- Desechables" << endl;
                        cout << "6.- Insumo especifico ID" << endl;
                        cin >> supplyType;
                        if (supplyType == 6){
                            string id;
                            cout << "ID del insumo" << endl;
                            cin >> id;
                            cout << myCafe.valorInventario(supplyType,id) << endl;
                        }
                        else{
                            cout << myCafe.valorInventario(supplyType) << endl;
                        }
                        break;
                    }
                    case 6:
                        insumoMenu = false;
                        break;
                    default:
                        cout << "Opcion erronea vuelve a intentarlo" << endl; 
                }
            }
        }
        else if (menuOption == 2){
            bool clienteMenu = true;
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
                        cout << "Opcion erronea vuelve a intentarlo" << endl;       
                }
            }
        }
        else if (menuOption == 3){
            menu = false;
        }
        else{
            cout << "Opcion erronea vuelve a intentarlo" << endl;
        } 
    }
}
