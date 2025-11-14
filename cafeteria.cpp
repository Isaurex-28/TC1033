#include <iostream>
#include <string>
#include "Cliente.h"
#include "Desechable.h"
#include "Insumo.h"

int main(){

    Insumo cafe(1,"cafe",10.0,false);
    cafe.consume(5);
    cafe.disponible();
    cafe.consume(6);

    Desechable plato(2,"plato",3.0,20);
    plato.consume(10);
    plato.disponible();

    Cliente juan("juan","juanperez345@hotmail.com",false);
    juan.contactarCliente();



    return 0;
}
