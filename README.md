# TCI2025
TP 1, 2, 3
TAD STR {
 str create() // Asigna memoria al nodo y lo inicializa en NULL
 void agregaUno(str*, char) // Agrega un caracter por cola a la cadena
 void muestraNodo(str) // Muestra un caracter de la cadena
 str retornaCab(str*) // Convierte cada caracter de una cadena en una cadena independiente
 str load() // Carga la cadena por terminal
 str load2(const char*, int) // Carga una cadena predefinida por el usuario
 str concat(str, str) // concatena dos cadenas
 void print(str) // Muestra la cadena completa
 str beforeToken(str, char) // retorna una cadena nueva creada a partir de los elementos antes del token ingresado
 str listToStr(list) // Convierte una lista en una cadena
 int compStr(str, str) // Compara dos cadenas y retorna 1 si son iguales o -1 si no lo son
}
TAD LIST {
 list createL() // Asigna memoria al nodo y lo inicializa en NULL
 list loadL() // Carga la lista
 void append(list*, list) // Agrega por cola otra lista
 void show(list) // Muestra todos los elementos de la lista
 list strToList(str) // Convierte todos los elementos de una cadena en una lista
}
TAD SET {
 set creaSet() // Asigna memoria al nodo y lo inicializa en NULL
 void loadSet(set*) // Carga el conjunto
 int cardinal(set) // Retorna el cardinal del conjunto (cantidad de elementos del conjunto) 
 set intersection(set, set) // Retorna un nuevo conjunto a partir de la interseccion de otros dos
 void showSet(set) // Muestra todos los elementos del conjunto
 set unionSet(set, set) // Retorna un nuevo conjunto a partir de la union de otros dos
 set dif(set, set) // Retorna un nuevo conjunto a partir de la diferencia entre dos conjuntos
 int incluido(set, set) // Verifica si un subconjunto A esta incluido en otro conjunto B, retorna 1 si esta incluido y -1 si no
 set set_toStr(str, char) // Convierte los elementos de una cadena en un conjunto
 void eliminaSet(set*) // Elimina el conjunto y libera la memoria
 void agregaASet(set*, str) // Agrega por cola los elementos al conjunto
 int pertenece(str, set) // Verifica si una cadena pertenece al conjunto, retorna 1 si pertenece y -1 si no
 set copySet(set) // Copia un conjunto en otro
 void eliminaUno(set*, str) // Elimina un elemento del conjunto
 }
