#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"



struct nodopilha{
	struct aresta *arestaPilha;
	struct nodopilha *prox;
};

struct desc_stack{
	struct nodopilha *top;
	int tamanho;
};

struct desc_stack *criaDescStack(void);
struct nodopilha* criaNodoStack(struct aresta *arestaPilha);
void push(struct desc_stack *stack,struct nodopilha*novoElemento);
struct nodopilha* pop(struct desc_stack *stack);
int empty(struct desc_stack *stack);
int length(struct desc_stack *stack);
void makeNull(struct desc_stack *stack);
struct nodopilha* top(struct desc_stack *stack);
void showStack(struct desc_stack *stack);
