#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<time.h>

bool pesquisaSequencial (int arr[], int n, int valor, int *comps){
	for(int i = 0; i < n; i++){
		(*comps)++;
		if(arr[i] == valor){
			printf("\nNúmero encontrado!\n");
			printf("\nNúmero %d encontrado na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("\nNúmero não encontrado!");
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

bool pesquisaBinaria(int arr[], int valor, int esq, int dir, int *compb){
	while(esq <= dir){
		int meio = (esq + dir) / 2;
		if (arr[meio] == valor){
			(*compb)++;
			printf("\n\nNúmero %d encontrado!\n", valor);
			printf("\nNúmero encontrado na posição %d", meio + 1);
			return true;
		} 
		if(arr[meio] < valor){
			(*compb)++;
			esq = meio + 1;
		} else {
			(*compb)++;
			dir = meio - 1;
		}
	}
	
	printf("\n\nNúmero não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	clock_t inicio1, fim1, inicio2, fim2, inicio3, fim3;
	double tempo1, tempo2, tempo3;
	int tam = 20, arr[tam], comps = 0, compb = 0;
	int busca, esq = 0, dir = tam - 1, opcao;
	
	for(int i = 0; i < tam; i++){
		printf("\nDigite o número para a posição %d: ", i + 1);
		scanf("%d", &arr[i]);
		getchar();
	}
	
	printf("\nMostrando array (original): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
  	}
  	printf("\n");
  	
  	inicio1 = clock();
	ordenandoDados(arr, tam);
	fim1 = clock();
	tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
	
	printf("\n\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
	}
	printf("\nTempo de execução: %f segundos para a ordenação.\n", tempo1);

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
				
				comps = 0;
				
				printf("\n\nPesquisando número %d na pesquisa sequencial...", busca);
				
				inicio2 = clock();
				pesquisaSequencial(arr, tam, busca, &comps);
				fim2 = clock();
				
				printf("\nNúmero de comparações: %d\n\n", comps);
				tempo2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC;
				printf("\nTempo de execução: %f segundos\n", tempo2);
			break;
			
			case 2:
				printf("\nIniciando pesquisa binária...\n\n");
				printf("Digite qual número deseja pesquisar: ");
				scanf("%d", &busca);
				getchar();
				
				compb = 0;
				
				printf("\n\nPesquisando número %d na pesquisa binária...", busca);
				
				inicio3 = clock();
				pesquisaBinaria(arr, busca, esq, dir, &compb);
				fim3 = clock();
				
				printf("\nNúmero de comparações: %d\n\n", compb);
				tempo3 = (double)(fim3 - inicio3) / CLOCKS_PER_SEC;
				printf("\nTempo de execução: %f segundos\n", tempo3);
							
				pesquisaBinaria(arr, busca, esq, dir, &compb);
			break;
			
			case 3:
				printf("\n\nSaindo do programa...");
			break;
			
			default:
				printf("\nOpção inválida. Tente novamente.");
			break;
		}
		if(opcao != 3){
				if(tempo2 < tempo3 && tempo2 != -1 && tempo3 != -1){
				printf("\nTempo de execução (Pesquisa sequencial): %f segundos\n", tempo2);
				printf("\nTempo de execução (Pesquisa binária): %f segundos\n", tempo3);
				
				if(comps < compb){
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa sequencial mais eficiente com menor tempo e menor número de comparações");
				} else if(comps == compb){
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa sequencial mais eficiente com menor tempo e mesmo número de comparações da binária");
				} else {
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa sequencial com menor tempo porém a pesquisa binária fez um menor número de comparações");
				}
			} else if(tempo2 == tempo3 && tempo2 != -1 && tempo3 != -1){
				printf("\nTempo de execução (Pesquisa sequencial): %f segundos\n", tempo2);
				printf("\nTempo de execução (Pesquisa binária): %f segundos\n", tempo3);
				
				if(comps < compb){
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa sequencial e binária com o mesmo tempo de execução porém a sequencial teve menor número de comparações.");
				} else if(comps == compb){
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa sequencial e binária com o mesmo tempo de execução e mesmo número de comparações");
				} else {
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa sequencial e binária com o mesmo tempo de execução porém a pesquisa binária fez um menor número de comparações");
				}
			} else if(tempo3 < tempo2 && tempo2 != -1 && tempo3 != -1){
				printf("\nTempo de execução (Pesquisa sequencial): %f segundos\n", tempo2);
				printf("\nTempo de execução (Pesquisa binária): %f segundos\n", tempo3);
				
				if(comps < compb){
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa binária com menor tempo de execução porém a sequencial teve menor número de comparações.");
				} else if(comps == compb){
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa binária com menor tempo de execução e mesmo número de comparações da sequencial");
				} else {
					printf("\nNúmero de comparações (Pesquisa sequencial): %d\n\n", comps);
					printf("\nNúmero de comparações (Pesquisa Binária): %d\n\n", compb);
					printf("\Resultado: Pesquisa binária com menor tempo de execução e fez um menor número de comparações");
				}
			}
		}
	
	} while (opcao != 3);
	
	return 0;
}



