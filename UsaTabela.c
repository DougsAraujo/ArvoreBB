#include "TabSimb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	TabelaSimbolos T = NovaTabela();
	
	int i;
	for(i = 0; i < 5; i++)
	{
		Item A;
		A.c = rand()%10;
		I_Imprime(A);
		TS_Inserir(T, A);
	}
	printf("---------\n");

	TS_Imprimir(T);

	for(i = 0; i < 5; i++)
	{
		int r = rand()%10;
		Item A = TS_Remover(T, r);
		if( I_Igual(A, ItemNulo() ))
			printf("Elemento %d nao encontrado\n", r);
		else
			printf("Elemento %d removido\n", r);
	}

	printf("---------\n");
	TS_Imprimir(T);

	return 0;
}
