#ifndef TADSTRING_H
#define TADSTRING_H

typedef struct nodo{
	char dato;
	struct nodo *sig; 
}tnodo;

typedef tnodo *str;

str retornaCab(str*);
str load();
str create();
void print(str);
str load2(const char*, int i);
str concat(str, str);
str beforeToken(str, char);
str listToStr(list);
int compStr(str, str);

#endif
