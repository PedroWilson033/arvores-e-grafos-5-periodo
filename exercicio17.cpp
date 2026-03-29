#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

void ordenandoDados(int arr[], int n){
	int i, j, temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

bool pesquisaBinaria(int arr[], int valor, int esq, int dir){
	while(esq <= dir){
		int meio = (esq + dir) / 2;
		if (arr[meio] == valor){
			printf("\n\nFrequência cardíaca %d encontrada!\n", valor);
			printf("Frequência cardíaca encontrada na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			esq = meio + 1;
		} else {
			dir = meio - 1;
		}
	}
	
	printf("\n\nFrequência cardíaca não encontrada!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 5;
	
	int freq[tam] = {72, 80, 65, 90, 75};
	int busca = 65, esq = 0, dir = tam - 1;
	
	printf("Mostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", freq[i]);
  	}
  	
	ordenandoDados(freq, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", freq[i]);
  	}
  	
  	printf("\n\nPesquisando frequência cardíaca %d...", busca);
  	pesquisaBinaria(freq, busca, esq, dir);
	
	return 0;
}

