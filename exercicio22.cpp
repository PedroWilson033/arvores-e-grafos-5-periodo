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
			printf("\n\nSaldo %d encontrado!\n", valor);
			printf("Saldo encontrado na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			esq = meio + 1;
		} else {
			dir = meio - 1;
		}
	}
	
	printf("\n\nSaldo não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 5;
	
	int saldos[tam] = {1500, 2300, 800, 1200, 2000};
	int busca = 800, esq = 0, dir = tam - 1;
	
	printf("Mostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", saldos[i]);
  	}
  	
	ordenandoDados(saldos, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", saldos[i]);
  	}
  	
  	printf("\n\nPesquisando saldo %d...", busca);
  	pesquisaBinaria(saldos, busca, esq, dir);
	
	return 0;
}

