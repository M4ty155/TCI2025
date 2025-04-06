#include <stdio.h>
#include "TADSET.H"
#include "TADSTRING.H"
#include <stdlib.h>


void agregaASet(set*, str);
int pertenece(str, set);
set copySet(set);
void eliminaUno(set*, str);

set set_toStr(str s1,char token){
	set nvo;
	str aux;
	nvo=NULL;
	while(s1!=NULL){
		aux=beforeToken(s1,token);
		if(aux!=NULL)
			agregaASet(&nvo,aux);
		else 
			printf("\nError: subcadena vacia");
		while(s1!=NULL&&s1->dato!=token)
			s1=s1->sig;
		if(s1!=NULL) 
			s1 = s1->sig;
	}
	return nvo;
}

int compSets(set a, set b){
	set aux1, aux2;
	int ba, c;
	ba = 0;
	c = 1;
	aux1 = a;
	aux2 = b;
	while(aux1 != NULL && ba != 1){
		if(compStr(aux1->dato, aux2->dato) == 1){
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

int incluido(set a, set b){
	int c, i;
	set aux1, aux2;
	c = -1;
	i = 0;
	aux1 = a;
	aux2 = b;
	if(cardinal(a) <= cardinal(b)){
		while(aux1 != NULL){
			while(aux2 != NULL){
				if(compStr(aux1->dato, aux2->dato) == 1){
					i++;
				}
				aux2 = aux2->sig;
			}
			aux2 = b;
			aux1 = aux1->sig;
		}
	}
	if(cardinal(a) == i){
		c = 1;
	}
	return c;
}

void eliminaSet(set *a){
	free(*a);
}

void eliminaUno(set *a, str s){
	set aux, ant;
	aux = *a;
	ant = NULL;
	while(aux->sig != NULL && compStr(aux->dato, s) != 1){
		ant = aux;
		aux = aux->sig;
	}
	if(aux->sig != NULL && ant != NULL){
		ant->sig = aux->sig;	
	}
	else if(ant == NULL){
		(*a) = (*a)->sig;
	}
}

set copySet(set a){
	set cab, aux;
	cab = NULL;
	aux = a;
	while(aux != NULL){
		agregaASet(&cab, aux->dato);
		aux = aux->sig;
	}
	return cab;
}

set dif(set a, set b){
	set aux, cab;
	cab = copySet(a);
	aux = cab;
	while(aux != NULL){
		if(pertenece(aux->dato, b) == 1){
			eliminaUno(&cab, aux->dato);
		}
		aux = aux->sig;
	}
	return cab;
}

set unionSet(set a, set b){
	set aux1, aux2, cab;
	cab = NULL;
	aux1 = a;
	aux2 = b;
	while(aux1 != NULL){
		agregaASet(&cab, aux1->dato);
		aux1 = aux1->sig;
	}
	while(aux2 != NULL){
		if(pertenece(aux2->dato, cab) != 1){
			agregaASet(&cab, aux2->dato);
		}
		aux2 = aux2->sig;
	}
	return cab;
}

int pertenece(str s, set a){
	set aux;
	int c;
	c = 0;
	aux = a;
	while(aux != NULL && compStr(aux->dato, s) < 0){
		aux = aux->sig;
	}
	if(aux != NULL){
		c = 1;
	}
	return c;
}

int cardinal(set a){
	set aux;
	int c;
	c = 0;
	aux = a;
	while(aux != NULL){
		c++;
		aux = aux->sig;
	}
	return c;
}

set intersection(set a, set b){
	set aux1, aux2, cab;
	cab = NULL;
	aux1 = a;
	aux2 = b;
	while(aux1 != NULL){
		while(aux2 != NULL){
			if(pertenece(aux1->dato, cab) != 1){
				if(pertenece(aux1->dato, aux2) == 1){
					agregaASet(&cab, aux1->dato);
				}
			}
			aux2 = aux2->sig;
		}
		aux2 = b;
		aux1 = aux1->sig;
	}
	return cab;
}

void showSet(set a){
	printf("{");
	while(a != NULL){
		print(a->dato);
		if(a != NULL){
			printf(", ");
		}
		a = a->sig;
	}
	printf("}");
}

set creaSet(){
	set a;
	a = (set)malloc(sizeof(tnodoset));
	a->sig = NULL;
	return a;
}
	
void agregaASet(set *a, str b){
	set aux1, aux2;
	aux1 = creaSet();
	aux1->dato = b;
	if(*a == NULL){
		*a = aux1;
	}
	else{
		aux2 = *a;
		while(aux2->sig != NULL){
			aux2 = aux2->sig;
		}
		aux2->sig = aux1;
	}
}
	
void loadSet(set *a){
	str aux;
	int i, n;
	printf("Ingrese cantidad de elementos del conjunto: ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		printf("Ingrese cadena nro %d: ", i);
		fflush(stdin);
		aux = create();
		aux = load();
		agregaASet(a, aux);
	}
}
