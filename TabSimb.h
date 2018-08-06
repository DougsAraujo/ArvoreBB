#ifndef TABELA_SIMBOLOS
#define TABELA_SIMBOLOS

#include "Item.h"

typedef struct TS* TabelaSimbolos;

TabelaSimbolos NovaTabela();
void TS_Inserir(TabelaSimbolos T, Item I);
Item TS_Buscar(TabelaSimbolos T, Chave c);
Item TS_Remover(TabelaSimbolos T, Chave c);
int TS_NumElementos(TabelaSimbolos T);
void TS_Imprimir(TabelaSimbolos T);


#endif
