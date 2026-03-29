#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

bool pesquisaSequencial (int arr[], int n, int valor){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			printf("\nNúmero cadastrado!\n");
			printf("\nNúmero %d encontrado na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("\nNúmero não cadastrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int numeros[4] = {9991, 9992, 9993, 9994};
	int busca = 9993;
	
	printf("Buscando número %d\n", busca);
	
	pesquisaSequencial(numeros, 4, busca);

	return 0;
}

