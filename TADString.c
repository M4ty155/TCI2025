#include <stdio.h>
#include <stdlib.h>
#include "TADSTRING.H"
#include "TADLIST.H"

str create();
void muestraNodo(str);
void agregarUno(str*, char);
str retornaCab(str*);

int compStr(str a, str b){
	str aux1, aux2;
	int ba, c;
	ba = 0;
	c = 1;
	aux1 = a;
	aux2 = b;
	while(aux1 != NULL && ba != 1){
		if(aux1->dato == aux2->dato){
			aux1 = aux1->sig;
			aux2 = aux2->sig;
		}
		else{
			ba = 1;
		}
	}
	if((aux1 != NULL && aux2 == NULL) || (aux1 == NULL && aux2 != NULL) || ba != 0){
		c = -1;
	}
	return c;
}

str retornaCab(str*a){
	str b;
	b = create();
	b->dato = (*a)->dato;
	(*a) = (*a)->sig;
	return b;
}

void agregarUno(str *lista, char c){
	str aux, nuevo;
	if(*lista != NULL){
		aux = *lista;
		nuevo = create();
		nuevo->dato = c;
		while(aux->sig != NULL)
			aux = aux->sig;
		aux->sig = nuevo;
	}
	else{
		*lista = create();
		(*lista)->dato = c;
	}
}

str listToStr(list a){
	str b;
	b = NULL;
	while(a != NULL){
		b = concat(b, a->dato);
		a = a->sig;
	}
	return b;
}

str beforeToken(str a, char c){
	str aux, cab;
	aux = concat(NULL, a);
	cab = aux;
	while(aux->dato != c && aux->sig != NULL){
		aux = aux->sig;
	}
	if(aux->dato == c){
		aux->sig = NULL;
	}
	return cab;
}

str concat(str s1,str s2){
	str aux;
	aux = NULL;
	while(s1!=NULL){
		agregarUno(&aux,s1->dato);
		s1=s1->sig;
	}
	while(s2!=NULL){
		agregarUno(&aux,s2->dato);
		s2=s2->sig;
	}
	return aux;
}
	

str load2(const char *cad, int i){
	char c;
	str nodo;
	nodo = NULL;
	c = cad[i];
	if(c != '\0' && c != EOF){
		nodo = create();
		nodo->dato = cad[i];
		nodo->sig = load2(cad,i+1);
	}
	return nodo;
}

str load(){
	char c;
	str nodo;
	c = getchar();
	nodo = NULL;
	if(c!='\n'&&c!=EOF){
		nodo=create();
		nodo->dato=c;
		nodo->sig=load();
	}
	return nodo;
}

void print(str a){
	printf("{");
	while(a != NULL){
		muestraNodo(a);
		a = a->sig;
	}
	printf("}");
}

void muestraNodo(str a){
	printf("%c", a->dato);
}

str create(){
	str a;
	a = (str)malloc(sizeof(tnodo));
	a->sig = NULL;
	return a;
}
