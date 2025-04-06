#include "TADLIST.H"
#include "TADSTRING.H"
#include <stdlib.h>
#include <stdio.h>

list createL();
void append(list*, list);

list strToList(str cad){
	list a, aux, nvo;
	str auxs;
	auxs = concat(NULL, cad);
	a = NULL;
	while(auxs != NULL){
		if(a == NULL){
			a = createL();
			a->dato = retornaCab(&auxs);
		}
		else{
			nvo = createL();
			nvo->dato = retornaCab(&auxs);
			aux = a;
			while(aux->sig != NULL){
				aux = aux->sig;
			}
			aux->sig = nvo;
		}
	}
	return a;
}

void loadL(list *a){
	int i, n;
	list b;
	printf("ingrese cantidad de elementos de la lista: ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		printf("Ingrese frase nro %d: ", i);
		fflush(stdin);
		b = createL();
		b->dato = load();
		append(a, b);
	}
}

list createL(){
	list a;
	a = (tnodos*)malloc(sizeof(list));
	a->sig = NULL;
	return a;
}
	
void append(list *a, list b){
	list aux;
	if(*a == NULL){
		*a = b;
	}
	else{
		aux = *a;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = b;
	}
}
	
void show(list a){
	printf("{");
	while(a != NULL){
		print(a->dato);
		a = a->sig;
		if(a != NULL){
			printf(", ");
		}
	}
	printf("}\n");
}
