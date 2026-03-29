#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

bool pesquisaSequencial (int arr[], int n, int valor){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			printf("Temperatura encontrada!\n");
			printf("Temperatura %d encontrada na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("Temperatura não registrada!");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int temperaturas[5] = {30, 32, 28, 27, 35};
	int busca = 27;
	
	printf("Buscando temperatura %d\n", busca);
	
	pesquisaSequencial(temperaturas, 5, busca);

	return 0;
}

