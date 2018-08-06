#ifndef ITEM
#define ITEM

#include <stdio.h>

typedef int Chave;

typedef struct
{
	//Nome, Idade, CPF, Matrícula

	Chave c;
} Item;

int I_Maior(Item A, Item B);
int I_Igual(Item A, Item B);
int I_Menor(Item A, Item B);

int C_Maior(Chave A, Chave B);
int C_Igual(Chave A, Chave B);
int C_Menor(Chave A, Chave B);

void I_Imprime(Item A);


Item ItemNulo();

Chave GetChave(Item I);

#endif
