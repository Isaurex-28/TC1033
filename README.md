# TC1033

# Contexto
Una cafetería tiene problemas para mantener su inventario en orden, por lo que se genera una estructura de 2 clases principales.

La clase Cliente ayuda a la cafetería a mantener una lista de sus clientes frecuentes y su información importante como el medio de contacto y si tienen alguna alergia para tener precaución al preparar sus alimentos.

La clase Insumo sirve para mantener la cuenta de toda la comida y los desechables que se utilizan en la cafetería, de esta clase se heredan 4 clases que especifican las diferencias entre los Alimentos, los Polvos, el Café y los Desechables de la cafetería.

Las 2 clases se unen en una clase Cafetería que almacena tanto la lista de clientes como la de insumos, y es la responsable de crear nuevos productos y clientes.

# Diagrama de clases
<img width="4280" height="4571" alt="Diagrama de clases" src="https://github.com/user-attachments/assets/dfb25b83-2556-4113-a248-c9600663841f" />


# Funcionalidad
El programa consta de un menú principal que permite acceder a un submenú "Insumos" o un submenú "Clientes" así como salir del programa.

El menú de Insumos permite registrar/crear un nuevo insumo en el inventario, así como agregar unidades a un insumo ya existente o utilizar un insumo que esté en inventario, también permite ver el valor acumulado de los insumos en inventario y mostrar los insumos que ya están registrados y su información general, así como regresar al menú principal.

El menú de Clientes permite registrar/crear un nuevo cliente en la lista de Clientes, así como mostrar la lista con la información general de cada cliente, y regresar al menú principal.

# Consideraciones
* El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

* El atributo de tueste y el método tostar café, se basan en la Escala de Agtron, por lo que su valor default es de 95 y al tostarlo va bajando. 
<img width="800" height="350" alt="image" src="https://github.com/user-attachments/assets/45cff1d5-fc7d-4763-b62b-633c64813b75" />

# Instrucciones
compilar con: `g++ main.cpp -o main`

correr en linux: `/main.out`

correr en windows: `.\‎/main.exe`


