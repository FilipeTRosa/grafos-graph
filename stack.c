#include "stack.h"

struct desc_stack *criaDescStack(void){
	struct desc_stack *stack = (struct desc_stack*)malloc(sizeof(struct desc_stack));
	stack->top = NULL;
	stack->tamanho=0;
	return stack;
}

struct nodopilha* criaNodoStack(struct aresta * arestaPilha){
	struct nodopilha * novo = (struct nodopilha*)malloc(sizeof(struct nodopilha));
	novo->arestaPilha = arestaPilha;
	novo->prox = NULL;
	return novo;
}

void push(struct desc_stack *stack,struct nodopilha*novoElemento){
	novoElemento->prox = stack->top;
	stack->top = novoElemento;
	stack->tamanho++;
}

struct nodopilha* pop(struct desc_stack *stack){
	struct nodopilha *aux = stack->top;
	stack->top=stack->top->prox;
	stack->tamanho--;
	return aux;
}

int empty(struct desc_stack *stack){
	if(stack->top ==NULL)
		return 1;
		else
		return 0;
}

int length(struct desc_stack *stack){
	return stack->tamanho;
}

void makeNull(struct desc_stack *stack){
		while(empty(stack) == 0){
			free(pop(stack));
		}
}

struct nodopilha* top(struct desc_stack *stack){
	return stack->top;
}

void showStack(struct desc_stack *stack){
	struct nodopilha* topo = top(stack);
	printf("====Pilha de Arestas==========\n");
	while(topo !=NULL){
		printf("[ %d -> %d ] \n",topo->arestaPilha->partida,topo->arestaPilha->chegada);
		topo = topo->prox;
	}
	printf("\n");
	printf("==============\n");
}




