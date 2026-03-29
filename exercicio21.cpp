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

bool pesquisaBinaria(int arr[], int valor, int esq, int dir, int *comp){
	while(esq <= dir){
		int meio = (esq + dir) / 2;
		if (arr[meio] == valor){
			(*comp)++;
			printf("\n\nLog %d encontrado!\n", valor);
			printf("Log encontrado na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			(*comp)++;
			esq = meio + 1;
		} else {
			(*comp)++;
			dir = meio - 1;
		}
	}
	
	printf("\n\nLog não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 6;
	
	int logs[tam] = {1023, 1001, 1050, 1010, 1035, 1040};
	int busca = 1010, esq = 0, dir = tam - 1, comp = 0;
	
	printf("Mostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", logs[i]);
  	}
  	
	ordenandoDados(logs, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", logs[i]);
  	}
  	
  	printf("\n\nPesquisando log %d...", busca);
  	pesquisaBinaria(logs, busca, esq, dir, &comp);
	printf("\nNúmero de comparações: %d", comp);
	
	return 0;
}

