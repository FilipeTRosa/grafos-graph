#index
index:
		#COMPILANDO GRAFO DO JULIO
		gcc stack.c -c -g
		gcc grafo.c -c -g
		gcc main.c grafo.o stack.o -o grafo -g
clean:
		#APAGANDO OS ARQUIVOS EXECUTAVEL E OBJETO
		rm grafo
		rm *.o

