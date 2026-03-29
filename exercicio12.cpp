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
			printf("\n\nID %d encontrado/existente!\n", valor);
			printf("ID encontrado na posição %d", meio + 1);
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
	
	printf("\n\nID não encontrado/cadastrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int tam = 5, comp = 0;
	
	int posicoes[tam] = {500, 200, 800, 300, 100};
	int busca = 300, esq = 0, dir = tam - 1;
	
	printf("Mostrando array (antes da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", posicoes[i]);
  	}
  	
	ordenandoDados(posicoes, tam);
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", posicoes[i]);
	}
	
	printf("\n\nPesquisando pontuação %d no ranking...", busca);
	pesquisaBinaria(posicoes, busca, esq, dir, &comp);
	printf("\nTotal de comparações: %d", comp);
	
	return 0;
}

