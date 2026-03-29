#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

bool pesquisaSequencial (int arr[], int n, int valor){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			printf("Dado encontrado!\n");
			printf("Dado %d encontrado na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("Dado não encontrado!");
	return false;
}

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
			printf("\n\nDado %d encontrado!\n", valor);
			printf("Dado encontrado na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			esq = meio + 1;
		} else {
			dir = meio - 1;
		}
	}
	
	printf("\n\nDado não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");
	
	int tam = 0, busca = 0, esq = 0, dir, opcao;
	int *dados;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	
	dir = tam - 1;
	
	dados = (int*)malloc(tam * sizeof(int));
	
	if(dados == NULL){
		printf("\nErro ao alocar memória!");
		return -1;
	}
	
	for(int i = 0; i < tam; i++){
		dados[i] = rand() % 1000;
	}
	
	printf("Mostrando array preenchido com valores aleatória de 0 a 999: \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", dados[i]);
  	}
  	printf("\n");
  	
	do{
		printf("\n----- MENU DE PESQUISA -----\n");
		printf("\n1. Pesquisa sequencial ");
		printf("\n2. Pesquisa binária ");
		printf("\n3. Sair");
		printf("\nDigite a opção desejada: ");
		scanf("%d", &opcao);
		getchar();
	
		switch(opcao){
			case 1:
				printf("\nIniciando pesquisa sequencial...\n\n");
				printf("Digite qual número deseja pesquisar: ");
				scanf("%d", &busca);
				getchar();
				
				printf("\nBuscando o dado %d na pesquisa sequencial\n", busca);
				pesquisaSequencial(dados, tam, busca);
			break;
			
			case 2:
				ordenandoDados(dados, tam);
				printf("\nMostrando array (depois da ordenação): \n");
				for(int i = 0; i < tam; i++){
					printf("%d ", dados[i]);
				}
				
				printf("\nIniciando pesquisa binária...\n\n");
				printf("Digite qual número deseja pesquisar: ");
				scanf("%d", &busca);
				getchar();
				
				printf("\n\nPesquisando dado %d na pesquisa binária...", busca);
				pesquisaBinaria(dados, busca, esq, dir);
			break;
			
			case 3:
				printf("\n\nSaindo do programa...");
			break;
			
			default:
				printf("\nOpção inválida. Tente novamente.");
			break;
		}
	} while (opcao != 3);
	

	return 0;
}



