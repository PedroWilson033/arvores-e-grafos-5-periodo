#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

bool pesquisaSequencial (int arr[], int n, int valor){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			printf("ID já registrado!\n");
			printf("ID %d encontrado na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("ID não registrado, cadastro pode ser continuado!");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int ids[4] = {2001, 2002, 2003, 2004};
	int busca = 2005;
	
	printf("Buscando ID %d\n", busca);
	
	pesquisaSequencial(ids, 4, busca);
	
	return 0;
}

