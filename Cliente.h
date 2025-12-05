#ifndef CLIENTE_H  
#define CLIENTE_H  

#include <iostream>
#include <string>

using namespace std;

/*
* Clase cliente que actuará como otro de los componentes de la
* cafetería
*/

class Cliente{
    private:
    // Atributos de los clientes
    string nombre;
    string correo;
    bool alergias;
    public:
    
    /*
    * Constructor de cliente que por default deja el nombre y el correo
    * en blanco, y las alergias en falso.
    * 
    * @param
    * @return Objeto Cliente
    */
    Cliente():nombre(""),correo(""),alergias(false){};
    
    /*
    * Constructor de cliente
    * 
    * @param string string name: nombre del cliente, string mail:
    * correo electrónico, bool allergy tiene alergias?
    * @return
    */    
    Cliente(string name,string mail, bool allergy):
        nombre(name), correo(mail), alergias(allergy){};

    void setNombre(string);
    void setCorreo(string);
    void setAlergias(bool);

    string getNombre();
    string getCorreo();
    bool getAlergias();
};


//Setters
void Cliente::setNombre(string name){
    nombre = name;
}
void Cliente::setCorreo(string mail){
    correo = mail;
}
void Cliente::setAlergias(bool alergy){
    alergias = alergy;
}

//Getters
string Cliente::getNombre(){
    return nombre;
}
 string Cliente::getCorreo(){
    return correo;
}
bool Cliente::getAlergias(){
    return alergias;
}

#endif

