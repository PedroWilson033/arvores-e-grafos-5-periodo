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
			printf("\n\nNota %d encontrada!\n", valor);
			printf("Nota encontrada na posição %d", meio + 1);
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
	
	printf("\n\nNota não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 15;
	int notas[tam];
	int busca, esq = 0, dir = tam - 1, comp = 0;
	
	for(int i = 0; i < tam; i++){
		printf("Digite a nota para a posição(%d): ", i + 1);
		scanf("%d", &notas[i]);
	}
	
	printf("Mostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", notas[i]);
  	}
  	
	ordenandoDados(notas, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", notas[i]);
	}


	printf("\n\nDigite o valor da nota que deseja pesquisar: ");
	scanf("%d", &busca);
	getchar();
	
	printf("\n\nPesquisando ID %d...", busca);
	pesquisaBinaria(notas, busca, esq, dir, &comp);
	printf("\nNúmero de comparações: %d", comp);
	
	return 0;
}

