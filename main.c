#include <stdio.h>
#include "TADSTRING.H"
#include "TADLIST.H"
#include "TADSET.H"

int main(int argc, char *argv[]) {
	str a, b, c, d, e, f;
	set set1, set2, set3, set4, set5, set6;
	list l, li;
	char t;
	int i;
	set1 = NULL;
	set2 = NULL;
	set3 = NULL;
	set4 = NULL;
	set5 = NULL;
	set6 = NULL;
	e = NULL;
	l = NULL;
	li = NULL;
	f = NULL;
	loadSet(&set1);
	loadSet(&set2);
	showSet(set1);
	printf("\n");
	showSet(set2);
	printf("\n");
	set3 = intersection(set1, set2);
	showSet(set3);
	printf("\n");
	set4 = dif(set1, set2);
	showSet(set4);
	printf("\n");
	set5 = unionSet(set1, set2);
	showSet(set5);
	printf("\n");
	i = incluido(set1, set2);
	printf("%d", i);
	printf("\n");
	loadL(&l);
	printf("Lista generada: ");
	show(l);
	printf("Ingrese primera frase: ");
	a = load();
	printf("Ingrese segunda frase: ");
	b = load();
	printf("primera frase: ");
	print(a);
	printf("\n");
	printf("segunda frase: ");
	print(b);
	printf("\n");
	printf("frases concatenadas: ");
	c = concat(a, b);
	print(c);
	printf("\n");
	printf("Ingrese token: ");
	scanf("%c", &t);
	d = beforeToken(a, t);
	printf("frase antes del token: ");
	print(d);
	printf("\n");
	e = load2("Palabra", 0);
	printf("frase cargada: ");
	print(e);
	printf("\n");
	set6 = set_toStr(e, 'a');
	showSet(set6);
	printf("\n");
	f = listToStr(l);
	printf("Lista pasada a string: ");
	print(f);
	printf("\n");
	printf("String pasado a lista: ");
	li = strToList(a);
	show(li);
	return 0;
}
