#include <stdlib.h>
#include <stdio.h>


struct descritor_grafo{
	int max_vertices;
	int max_arestas;
	struct nodo *nodos;
};

struct nodo{
	int chave;
	struct nodo *prox;
	//struct nodo *adjacencias;	
	struct aresta *adjacencias;	
};

struct aresta{
	int partida;
	int chegada;
	int peso;
	struct aresta *prox;
};

struct descritor_grafo* parser(char *nomeArquivo);
struct descritor_grafo * inicializaGrafo(int tamanho);
struct nodo* criaVertice(int chave);
void insereVertice(struct descritor_grafo *grafo, int chave);
struct descritor_grafo * insereAresta(struct descritor_grafo *grafo, int chaveSaida, int chaveChegada, int peso);
struct nodo* buscaVertice(struct descritor_grafo *grafo, int chaveBusca);
struct nodo* buscaAdjacencia(struct descritor_grafo *grafo, int partida, int chegada);
int tamanhoVertices(struct descritor_grafo *grafo);
int tamanhoAdjacencias(struct descritor_grafo *grafo);
int listaAjacencias(struct nodo *vertice);
void imprimeGrafo(struct descritor_grafo *grafo);
void buscaProfundidade_DFS(struct descritor_grafo * grafo,struct nodo * nodo, int *visitados);
void buscaLargura_BFS(struct descritor_grafo * grafo,struct nodo * nodo, int *visitados);
void buscaNoGrafo(struct descritor_grafo * grafo);


//////---------------REPRESENTAÇÃO COM MATRIZ DE ADJACÊNCIA---------------------

struct descritor_grafo_matriz{
	int max_vertices;
	int max_arestas;
	int **grafoMatriz;
};


struct descritor_grafo_matriz* parserMatriz(char *nomeArquivo);
struct descritor_grafo_matriz * inicializaGrafoMatriz(int tamanho);
struct descritor_grafo_matriz * insereArestaMatriz(struct descritor_grafo_matriz *grafo, int chaveSaida, int chaveChegada, int peso);
void imprimeGrafoMatriz(struct descritor_grafo_matriz *grafoMatriz);

