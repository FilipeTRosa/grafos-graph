#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "fila.h"

int main(){
	
	int opcao,chave_busca;
	struct descritor_grafo *grafo = NULL;
	struct descritor_grafo_matriz *grafoMatriz = NULL;
	struct desc_stack *minhaPilha = NULL;
	opcao = -1;
	while(opcao != 0){
		printf("escolha sua opcao:\n");
		printf("1-carrega grafo lista\n2-busca adjacencias\n3-imprime grado lista\n4-pilhaArestas\n5-carrega grafo Matriz\n6-imprime grafo matriz\n7- Busca No GRAFO\n0-SAIR\n");
		setbuf(stdin,NULL);
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
					grafo = parser("grafo.txt");
					if(grafo !=NULL)
						printf("grafo lista inicializado com sucesso\n");
					break;
			case 2:
					printf("digite a chave a ser buscada no grafo lista\n");
					setbuf(stdin,NULL);
					scanf("%d",&chave_busca);
					struct nodo* temp = buscaVertice(grafo,chave_busca);
					if(temp == NULL)
						printf("não encontrou o nodo\n");
					else
						printf("encontrou o nodo\n");
					break;
			case 3:
					imprimeGrafo(grafo);
					break;
			case 4:
					if(grafo ==NULL){
						printf("grafo lista inicializado com sucesso\n");
						break;
					}
					minhaPilha = criaDescStack();

					//grafo pronto vai acessar as arestas para criar no da pilha e inserir
					struct aresta *arestaGrafo=NULL;
					//recebe o primeiro da lista de vertices
					struct nodo *auxVertice = grafo->nodos;
					
					while(auxVertice != NULL){
					
						//percorre as adjacencias do auxvertice colocando na pilha
						arestaGrafo = auxVertice->adjacencias;
						while(arestaGrafo != NULL){
							//crio nó pilha para inserir na pilha
							struct nodopilha *noPilha = criaNodoStack(arestaGrafo);
							//insere na pilha
							push(minhaPilha,noPilha);
							arestaGrafo = arestaGrafo->prox;
						}
						auxVertice = auxVertice->prox;
					}
					
					//mostra pilha completa
					showStack(minhaPilha);
					
					break;
			case 5:
					grafoMatriz = parserMatriz("grafo.txt");
					if(grafoMatriz !=NULL)
						printf("grafo inicializado com sucesso\n");
					break;
			case 6:
					imprimeGrafoMatriz(grafoMatriz);
					break;
			case 7:
				//buscar em profundidade.
				
				buscaNoGrafo(grafo);
				
				break;
			case 0:
					exit(-1);
		}	
	}
	return 0;
}
