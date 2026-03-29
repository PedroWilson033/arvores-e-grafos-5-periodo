#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<time.h>

bool pesquisaSequencial (int arr[], int n, int valor, int *comps){
	for(int i = 0; i < n; i++){
		(*comps)++;
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

bool pesquisaBinaria(int arr[], int valor, int esq, int dir, int *compb){
	while(esq <= dir){
		int meio = (esq + dir) / 2;
		if (arr[meio] == valor){
			(*compb)++;
			printf("\n\nDado %d encontrado!\n", valor);
			printf("Dado encontrado na posição %d", meio + 1);
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
	
	printf("\n\nDado não encontrado!\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	clock_t inicio1, fim1, inicio2, fim2, inicio3, fim3;
	double tempo1, tempo2, tempo3;
	int tam = 7, comps = 0, compb = 0;

	int dados[tam] = {64, 21, 33, 70, 12, 85, 50};
	/*int dados[tam];
	for(int i = 0; i < tam; i++){
		dados[i] = tam - i;
	}
	*/
	/*
	Laço de repetição para aumentar o valores do vetor para teste de melhor visualização
	de desempenho dos algoritmos trabalhados. Basta tirar o comentário e atualizar a variável
	"tam" para o valor desejado.
	*/
	int busca = 50, esq = 0, dir = tam - 1;
	
	printf("Mostrando array: \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", dados[i]);
  	}
  	printf("\n");
  	
	
	printf("\nBuscando o dado %d na pesquisa sequencial\n", busca);
	
	inicio1 = clock();
	pesquisaSequencial(dados, tam, busca, &comps);
	printf("Número de comparações: %d\n\n", comps);
	fim1 = clock();
	tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
	printf("Tempo de execução: %f segundos\n", tempo1);
	
	inicio2 = clock();
	ordenandoDados(dados, tam);
	fim2 = clock();
	tempo2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC;
	
	printf("\nMostrando array (depois da ordenação): \n");
	for(int i = 0; i < tam; i++){
		printf("%d ", dados[i]);
	}
	

	printf("\n\nPesquisando dado %d na pesquisa binária...", busca);
	inicio3 = clock();
	pesquisaBinaria(dados, busca, esq, dir, &compb);
	printf("\nNúmero de comparações: %d\n\n", compb);
	fim3 = clock();
	tempo3 = (double)(fim3 - inicio3) / CLOCKS_PER_SEC;
	printf("\nTempo de execução: %f segundos (somente da pesquisa)\n", tempo3);
	printf("\nTempo de execução: %f segundos (somada a pesquisa com a ordenação)\n", tempo2 + tempo3);
	
	printf("\nJustificativa está no comentário ao final do código.");
	
	/* Com as análises acima pode-se notar que para pequenos conjuntos de dados
	a pesquisa sequencial tem um desempenho melhor, já que é necessário somente um processo
	que é o de comparação para achar o valor desejado, não sendo necessária a ordenação 
	dos dados, o que acelera a pesquisa, porém, para um conjunto maior de dados ela não seria 
	a ideal já que a pesquisa binária faria menos comparações e com o algoritmo de ordenação 
	correto teria um melhor desempenho. Para o caso da questão por se tratar de um vetor com poucos
	elementos a pesquisa sequencial demonstrou ser a melhor, sendo mais simples de implmentar
	e relativamente mais veloz, no entanto se a equipe desejar ter um algoritmo que comporte
	futuramente mais dados o ideal seria a pesquisa binária com o algoritmo de ordenação
	mais adequado para o serviço ou função desejada.
	*/
	
	return 0;
}



