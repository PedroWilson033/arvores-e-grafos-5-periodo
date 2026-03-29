#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<string.h>

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
			printf("\n\nNúmero %d encontrado!\n", valor);
			printf("Número encontrado na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			esq = meio + 1;
		} else {
			dir = meio - 1;
		}
	}
	
	printf("\n\nNúmero não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 10, busca, opcao, esq = 0, dir = tam - 1;
	int *arr;
	
	
	arr = (int*) malloc(10 * sizeof(int));
	
	if(arr == NULL){
		printf("Erro ao alocar memória!");
		return 1;
	}
	
	printf("\nIniciando preechimento do vetor...\n");
	for(int i = 0; i < tam; i++){
		printf("Digite o número da posição %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nNúmeros salvos com sucesso!\n");
	
	printf("\nMostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
  	}
  	
	ordenandoDados(arr, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
  	}
  	
  	printf("\nDeseja fazer busca de algum valor do array?\n");
	printf("1 para sim e 0 para não: ");
	scanf("%d", &opcao);
	
	if(opcao == 1){
		printf("\nDigite o número que deseja buscar: ");
		scanf("%d", &busca);
		
		printf("\n\nPesquisando número %d no array...", busca);
  		pesquisaBinaria(arr, busca, esq, dir);
	}
	
	printf("\n\nFinalizando o programa...");
	
	return 0;
}

