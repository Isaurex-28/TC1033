#ifndef CLIENTE_H  
#define CLIENTE_H  

#include <iostream>
#include <string>

using namespace std;

class Cliente{
    private:
    string nombre;
    string correo;
    bool alergias;
    public:
    
    //Constructor
    Cliente():nombre(""),correo(""),alergias(false){};
    Cliente(string name,string mail, bool allergy):nombre(name), correo(mail), alergias(allergy){};

    //Setters
    void setNombre(string);
    void setCorreo(string);
    void setAlergias(bool);

    //Getters
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
