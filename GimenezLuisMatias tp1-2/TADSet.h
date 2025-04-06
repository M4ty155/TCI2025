#ifndef TADSET_H
#define TADSET_H
#include "TADSTRING.H"
typedef struct nodoset{
	str dato;
	struct nodoset *sig;
}tnodoset;

typedef tnodoset *set;

set creaSet();
void loadSet(set*);
int cardinal(set);
set intersection(set, set);
void showSet(set);
set unionSet(set, set);
set dif(set, set);
int incluido(set, set);
set set_toStr(str, char);
void eliminaSet(set*);

#endif
