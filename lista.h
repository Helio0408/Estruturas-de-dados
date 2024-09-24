#define inicial 0
#define ERRO -32000
#define ORDENADA 0

#include "item.h"

typedef struct lista_ lista;

lista *lista_criar(void);
bool lista_inserir(lista *lista, item *chave);
item *lista_remover(lista *lista, int chave);
bool lista_apagar(lista **lista);
item *lista_busca(lista *lista, int chave);
int lista_tamanho(lista *lista);
bool lista_vazia(lista *lista);
void lista_imprimir(lista *lista);

bool lista_inverter(lista **lista);