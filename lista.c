#include "lista.h"

typedef struct no NO;

struct no {
	item *info;
	NO *prox;
};

struct lista_ {
	NO *ini, *fim;
	int tam;
};

lista *lista_criar() {
	lista *l = (lista *)malloc(sizeof(lista));
	assert(l != NULL);
	l->ini = NULL;
	l->fim = NULL;
	l->tam = 0;
	return l;
}

bool lista_vazia(lista *l) {
	assert(l != NULL);
	return (l->tam == 0);
}

int lista_tamanho(lista *l) {
	assert(l != NULL);
	return l->tam;
}

bool lista_inserir(lista *l, item *chave) {
	NO *p = (NO *)malloc(sizeof(NO));
	p->info = chave;
	p->prox = NULL;
	
	if(lista_vazia(l)) {
		l->ini = p;
	} else {
		l->fim->prox = p;
	}	
	l->fim = p;
	l->tam++;

	if(p != NULL)
		return true;
	else 
		return false;
}

bool lista_apagar(lista **l) {
		if(l != NULL){
		NO *p = (*l)->ini;
		while (p != NULL) {
			(*l)->ini = (*l)->ini->prox;
			item_apagar(&(p->info));
			free(p);
			p = (*l)->ini;
		}
		free(*l);
		*l = NULL;
		return true;
	}

	return false;
}

void lista_imprimir(lista *l){
	assert(l != NULL);

	for(NO* aux = l->ini; aux->prox != NULL; aux = aux->prox)
		item_imprimir(aux->info);

	item_imprimir(l->fim->info);
	printf("\n");
}

item *lista_busca(lista *l, int chave){
	item* alvo;

	for(NO* aux = l->ini; aux->prox != NULL; aux = aux->prox)
		if(item_get_chave(aux->info) == chave){
			alvo = aux->info;
			break;
		}
	
	return alvo;
}

item *lista_remover(lista *l, int chave){
	NO *ant = NULL;	
	item *temp;
	for(NO* aux = l->ini; aux->prox != NULL; aux = aux->prox){
		if(item_get_chave(aux->info) == chave){
			if(aux == l->ini)
				l->ini = l->ini->prox;
			else if(aux == l->fim){
				l->fim = ant;
				ant->prox = NULL;
			}else
				ant->prox = aux->prox;

			temp = aux->info;
			free(aux);
			return(temp);
		}
		ant = aux;
	}

	return NULL;
}

bool lista_inverter(lista **l){
	NO* aux;

	if(l != NULL && !lista_vazia(*l)){
		NO *ant = NULL, *next = (*l)->ini->prox;
		(*l)->fim = (*l)->ini;

		for(aux = (*l)->ini; aux->prox != NULL; aux = next){
			next = aux->prox;
			(*l)->ini = next;
			aux->prox = ant;
			ant = aux;
		}
		
		aux->prox = ant;
		(*l)->ini = aux;

		return true;
	}else
		return false;
}