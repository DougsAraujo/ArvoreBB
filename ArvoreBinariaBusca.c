#include "TabSimb.h"
#include <stdlib.h>

struct No
{
	Item I;
	struct No *esquerda;
	struct No *direita;
};

struct TS//Árvore binária de busca
{
	struct No *raiz;
};

//Cria uma árvore vazia e retorna para o usuário
TabelaSimbolos NovaTabela()
{
	TabelaSimbolos T = malloc(sizeof(struct TS));
	T->raiz = NULL;
	return T;
}
/*
void Deleta(struct No *raiz)
{
	if(raiz == NULL) return;

	Deleta(raiz->esquerda);	
	Deleta(raiz->direita);
	free(raiz);
}
*/
struct No* NovoNo(Item I, struct No *esq, struct No *dir)
{
	struct No* novo = malloc(sizeof(struct No));
	novo->I = I;
	novo->esquerda = esq;
	novo->direita = dir;
	return novo;
}

/*Busca recursiva*/
Item TS_Buscar_Interno(struct No *raiz, Chave c)
{
	if(raiz == NULL) return ItemNulo();

	if( C_Igual( GetChave(raiz->I), c ) )
		return raiz->I;

	if( C_Maior( GetChave(raiz->I), c ) )
		return TS_Buscar_Interno(raiz->esquerda, c);
	else
		return TS_Buscar_Interno(raiz->direita, c);
}

Item TS_Buscar(TabelaSimbolos T, Chave c)
{
	return TS_Buscar_Interno(T->raiz, c);
}

/*
Inserção recursiva

Verfica se o filho da raiz é null antes de chamar recursivamente
será necessário fazer um teste para verificar se a árvore em si é vazia, antes de chamar ester procedimento
*/
void TS_Inserir_Interno1(struct No *raiz, Item I)
{
	if(I_Maior(I, raiz->I))
		if(raiz->direita == NULL)
			raiz->direita = NovoNo(I, NULL, NULL);
		else
			TS_Inserir_Interno1(raiz->direita, I);
	else
		if(raiz->esquerda == NULL)
			raiz->esquerda = NovoNo(I, NULL, NULL);
		else
			TS_Inserir_Interno1(raiz->esquerda, I);
}

/*
Inserção recursiva 2
Insere um elemento e retorna a nova árvore após a inserção
*/
struct No* TS_Inserir_Interno2(struct No *raiz, Item I)
{
	if(raiz == NULL)
		raiz = NovoNo(I, NULL, NULL);
	else if(I_Maior(I, raiz->I))
		raiz->direita = TS_Inserir_Interno2(raiz->direita, I);
	else
		raiz->esquerda = TS_Inserir_Interno2(raiz->esquerda, I);
	return raiz;
}

/*
Inserção recursiva 3
Passa os apontadores por referência
*/
void TS_Inserir_Interno3(struct No **raiz, Item I)
{
	if(*raiz == NULL)
		*raiz = NovoNo(I, NULL, NULL);
	else if(I_Maior(I, (*raiz)->I))
		TS_Inserir_Interno3(&((*raiz)->direita), I);
	else
		TS_Inserir_Interno3(&((*raiz)->esquerda), I);
}

/*
Inserção não recursiva
*/
void TS_Inserir_Interno4(struct No *raiz, Item I)
{
	struct No *anda = raiz;
	int inseriu = 0;

	while( !inseriu )
	{
		if(I_Maior(I, anda->I))
		{
			if(anda->direita == NULL)
			{
				anda->direita = NovoNo(I, NULL, NULL);
				inseriu = 1;
			}
			else
			{
				anda = anda->direita;
			}
		}
		else
		{
			if(anda->esquerda == NULL)
			{
				anda->esquerda = NovoNo(I, NULL, NULL);
				inseriu = 1;
			}
			else
			{
				anda = anda->esquerda;
			}
		}
	}
}

void TS_Inserir(TabelaSimbolos T, Item I)
{
	//Usar com o Insere_Interno1 ou Insere_Interno 4
//	if(T->raiz == NULL)
//		T->raiz = NovoNo(I, NULL, NULL);
//	else
//		TS_Inserir_Interno1(T->raiz, I);

	//Usar com o Insere_Interno2
	T->raiz = TS_Inserir_Interno2(T->raiz, I);

	//Usar com o Insere_Interno3
//	TS_Inserir_Interno3(&(T->raiz), I);
}

struct No* TS_Remover_Interno(struct No *raiz, Chave c)
{
	if(raiz == NULL) return NULL;

	if( C_Igual( c, GetChave(raiz->I ) ) )
	{
		//Elemento foi encontrado
		if(raiz->direita == NULL && raiz->esquerda == NULL)
		{
			//Não tem filhos
			free(raiz);
			return NULL;
		}		
		else if(raiz->direita != NULL && raiz->esquerda == NULL)
		{
			//Tem filho à direita
			struct No *RD = raiz->direita;
			free(raiz);
			return RD;
		}
		else if(raiz->direita == NULL && raiz->esquerda != NULL)
		{
			//Tem filho à esquerda
			struct No *RE = raiz->esquerda;
			free(raiz);
			return RE;
		}
		else
		{
			//Encontra o maior à esquerda
			struct No *maiorEsquerda = raiz->esquerda;
			while(maiorEsquerda->direita != NULL)
				maiorEsquerda = maiorEsquerda->direita;

			//Troca o conteúdo
			Item aux = maiorEsquerda->I;
			maiorEsquerda->I = raiz->I;
			raiz->I = aux;			

			raiz->esquerda = TS_Remover_Interno(raiz->esquerda, c);
			return raiz;
		}
	}
	if( C_Maior( c, GetChave(raiz->I ) ) )
	{
		raiz->direita = TS_Remover_Interno(raiz->direita, c);
		return raiz;
	}
	else
	{
		raiz->esquerda = TS_Remover_Interno(raiz->esquerda, c);
		return raiz;
	}
} 



Item TS_Remover(TabelaSimbolos T, Chave c)
{
	Item I = TS_Buscar_Interno(T->raiz, c);
	TS_Remover_Interno(T->raiz, c);
	return I;
}


/*
int TS_NumElementos(TabelaSimbolos T);*/

void TS_Imprimir_Interno(struct No *raiz)
{
	if(raiz == NULL) return;

	TS_Imprimir_Interno(raiz->esquerda);	
	I_Imprime(raiz->I);
	TS_Imprimir_Interno(raiz->direita);
}


void TS_Imprimir(TabelaSimbolos T)
{
	TS_Imprimir_Interno(T->raiz);
}

