#ifndef CLIENTE_H  
#define CLIENTE_H  

#include <iostream>
#include <string>

class Cliente{
    private:
    std::string nombre;
    std::string correo;
    bool alergias;
    public:
    
    //Constructor
    Cliente():nombre(""),correo(""),alergias(false){};
    Cliente(std::string name,std::string mail, bool allergy):nombre(name), correo(mail), alergias(allergy){};

    //Setters
    void setNombre(std::string);
    void setCorreo(std::string);
    void setAlergias(bool);

    //Getters
    std::string getNombre();
    std::string getCorreo();
    bool getAlergias();
};


//Setters
void Cliente::setNombre(std::string name){
    nombre = name;
}
void Cliente::setCorreo(std::string mail){
    correo = mail;
}
void Cliente::setAlergias(bool alergy){
    alergias = alergy;
}

//Getters
std::string Cliente::getNombre(){
    return nombre;
}
std::string Cliente::getCorreo(){
    return correo;
}
bool Cliente::getAlergias(){
    return alergias;
}

#endif
