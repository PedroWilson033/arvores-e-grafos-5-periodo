#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<string.h>

void trocar(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int partir(int arr[], int inicio, int fim){
	int pivo = arr[fim];
	int i = inicio - 1;
	
	for(int j = inicio; j < fim; j++){
		if(arr[j] <= pivo){
			i++;
			trocar(&arr[i], &arr[j]);
		}
	}
	
	trocar(&arr[i + 1], &arr[fim]);
	 
	return i + 1;
}

void ordenandoDados(int arr[], int inicio, int fim){
	if(inicio < fim){
		int p = partir(arr, inicio, fim);
		ordenandoDados(arr, inicio, p - 1);
		ordenandoDados(arr, p + 1, fim);
	}
}

bool pesquisaBinaria(int arr[], int valor, int esq, int dir){
	while(esq <= dir){
		int meio = (esq + dir) / 2;
		if (arr[meio] == valor){
			printf("\n\nMatrícula %d encontrada!\n", valor);
			printf("Matrícula encontrada na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			esq = meio + 1;
		} else {
			dir = meio - 1;
		}
	}
	
	printf("\n\nMatrícula não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam;
	
	printf("Digite a quantidade de matrículas que deseja cadastrar: ");
	scanf("%d", &tam);
	getchar();

	int busca, opcao, inicio = 0, fim = tam - 1;
	int *arr;
	
	arr = (int*) malloc(tam * sizeof(int));
	
	if(arr == NULL){
		printf("Erro ao alocar memória!");
		return 1;
	}
	
	printf("\nIniciando preechimento do vetor...\n");
	for(int i = 0; i < tam; i++){
		printf("Digite a matrícula da posição %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nMatrículas salvas com sucesso!\n");
	
	printf("\nMostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
  	}
  	
	ordenandoDados(arr, inicio, fim);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
  	}
  	
  	printf("\nDeseja fazer busca de algum valor do array?\n");
	printf("1 para sim e 0 para não: ");
	scanf("%d", &opcao);
	
	if(opcao == 1){
		printf("\nDigite a matrícula que deseja buscar: ");
		scanf("%d", &busca);
		
		printf("\n\nPesquisando matrícula %d no array...", busca);
  		pesquisaBinaria(arr, busca, inicio, fim);
	}
	
	printf("\n\nFinalizando o programa...");
	
	return 0;
}

