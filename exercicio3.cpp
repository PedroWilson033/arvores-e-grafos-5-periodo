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
	
	printf("Produto não encontrado, infelizmente não existe um código assim em nosso sistema!");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int produtos[4] = {5, 10, 15, 20};
	int busca = 8;
	
	printf("Buscando o número do produto %d\n", busca);
	
	pesquisaSequencial(produtos, 5, busca);

	return 0;
}

