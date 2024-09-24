#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct item_ item;

item *item_criar(int chave);
bool item_apagar(item **i);
void item_imprimir(item *i);
int item_get_chave(item *i);
bool item_set_chave(item *i, int chave);
