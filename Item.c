#include "Item.h"

int I_Maior(Item A, Item B)
{
	return A.c > B.c;
}

int I_Igual(Item A, Item B)
{
	return A.c == B.c;
}

int I_Menor(Item A, Item B)
{
	return A.c < B.c;
}

int C_Maior(Chave A, Chave B)
{
	return A > B;
}

int C_Igual(Chave A, Chave B)
{
	return A == B;
}

int C_Menor(Chave A, Chave B)
{
	return A < B;
}

void I_Imprime(Item A)
{
	printf("%d\n", A.c);
}


Item ItemNulo()
{
	Item I;
	I.c = -1;
	return I;
}

Chave GetChave(Item I)
{
	return I.c;
}

