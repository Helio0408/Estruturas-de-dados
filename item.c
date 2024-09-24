#include "item.h"

struct item_ {
	int valor;
};

item *item_criar(int chave) {
	item *p = (item *)malloc(sizeof(item));
	if(p != NULL) {
		p->valor = chave;
		return p;
	}
	return NULL;
}

bool item_set_chave(item *i, int chave) {
	if(i != NULL) {
		i->valor = chave;
		return true;
	}
	return false;
}

int item_get_chave(item *i) {
	if(i != NULL)
		return i->valor;
	
	exit(1); 
}

bool item_apagar(item **i) {
	if(i != NULL) {
		free(*i);
		*i = NULL;
		return true;
	}

	return false;
}

void item_imprimir(item *i){
	if(i != NULL)
		printf("[%d]; ", item_get_chave(i));
}