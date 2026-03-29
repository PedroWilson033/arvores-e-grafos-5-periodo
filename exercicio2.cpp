#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

bool pesquisaSequencial (int arr[], int n, int valor){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			printf("Produto encontrado!\n");
			printf("Produto %d encontrado na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("Produto não encontrado!");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int produtos[5] = {12, 25, 30, 48, 50};
	int busca = 30;
	
	printf("Buscando o produto %d\n", busca);
	
	pesquisaSequencial(produtos, 5, busca);

	return 0;
}


