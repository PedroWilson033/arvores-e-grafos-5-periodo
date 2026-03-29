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
			printf("\n\nLeitura %d encontrada!\n", valor);
			printf("Leitura encontrada na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			esq = meio + 1;
		} else {
			dir = meio - 1;
		}
	}
	
	printf("\n\nLeitura não encontrada!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 5;
	
	int leituras[tam] = {45, 60, 30, 80, 55};
	int busca = 55, esq = 0, dir = tam - 1;
	
	printf("Mostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", leituras[i]);
  	}
  	
	ordenandoDados(leituras, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", leituras[i]);
  	}
  	
  	printf("\n\nPesquisando leitura %d...", busca);
  	pesquisaBinaria(leituras, busca, esq, dir);
	
	return 0;
}

