#ifndef TADLIST_H
#define TADLIST_H
#include "TADSTRING.H"
typedef struct nodos{
	str dato;
	struct nodos *sig;
}tnodos;

typedef tnodos *list;

void show(list);
void loadL(list*);
list strToList(str);

#endif
