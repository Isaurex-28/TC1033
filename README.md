# TC1033

# Contexto
Una cafetería tiene problemas para mantener su inventario en orden, por lo que se genera una estructura de 2 clases principales.

La clase Cliente ayuda a la cafetería a mantener una lista de sus clientes frecuentes y su información importante como el medio de contacto y si tienen alguna alergia para tener precaución al preparar sus alimentos.

La clase Insumo sirve para mantener la cuenta de toda la comida y los desechables que se utilizan en la cafetería, de esta clase se heredan 4 clases que especifican las diferencias entre los Alimentos, los Polvos, el Café y los Desechables de la cafetería.

Las 2 clases se unen en una clase Cafetería que almacena tanto la lista de clientes como la de insumos, y es la responsable de crear nuevos productos y clientes.

# Consideraciones
El atributo de tueste y el método tostar café, se basan en la Escala de Agtron, por lo que su valor default es de 95 y al tostarlo va bajando. 
<img width="800" height="350" alt="image" src="https://github.com/user-attachments/assets/45cff1d5-fc7d-4763-b62b-633c64813b75" />

# Instrucciones
compilar con: "g++ main.cpp" -o main

correr en linux: "/cafeteria.out"
correr en windows: ".\‎ /main.exe"


