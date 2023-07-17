#index
index:
		#COMPILANDO GRAFO DO JULIO
		gcc fila.c -c -g
		gcc stack.c -c -g
		gcc grafo.c -c -g
		gcc main.c grafo.o stack.o fila.o -o grafo -g
clean:
		#APAGANDO OS ARQUIVOS EXECUTAVEL E OBJETO
		rm grafo
		rm *.o

