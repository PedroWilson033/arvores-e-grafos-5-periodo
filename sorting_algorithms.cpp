#include<stdio.h>
#include<time.h>
#include<locale.h>
#include<stdlib.h>

#define TAM_ARRAY 10

/*Bubble Sort faz comparações com os seus elementos 
adjacentes levando o maior elemento para a posição 
final por isso ela não precisa ser verificada novamente.
*/
void bubbleSort (int array[], int n) {
	int temp;

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

/*O Selection Sort seleciona o menor valor de todo 
o vetor não ordenado e o troca com a posição atual.
Assim a cada volta, o início do vetor fica ordenado 
com os menores números.
*/
void selectionSort (int array[], int n){
	int min_idx, temp;
	
	for(int i = 0; i < n - 1; i++){
		min_idx = i;
		for(int j = i + 1; j < n; j++){
			if(array[j] < array[min_idx]){
				min_idx = j;
			}
		}
		
		temp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = temp;
	}
}

/*O Insertion Sort percorre o vetor da esquerda 
para a direita, pegando um número por vez (a chamada: chave) 
e colocando ele na posição correta entre os elementos
que já foram visitados, empurrando os maiores para 
o lado para abrir espaço. Semelhante a uma pessoa separando
as cartas de um baralho em sua mão
*/
void insertionSort (int array[], int n){

	int j, chave;

	for(int i = 1; i < n; i++){
		chave = array[i];
		j = i - 1;
	
		while(j >= 0 && array[j] > chave){		
			array[j + 1] = array[j];
			j--;
		}
	
		array[j + 1] = chave;
	}
}

//Função usada no Quick Sort para trocar os elementos verificados
void troca(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/*Parte o vetor para que o quick sort possa realizar
as modificações necessários.
*/
int partir(int array[], int inicio, int fim){
	int pivo = array[fim];
	int i = inicio - 1;
	
	for(int j = inicio; j < fim; j++){
		if(array[j] <= pivo){
			i++;
			troca(&array[i], &array[j]);
		}
	}

	troca(&array[i + 1], &array[fim]);
	
	return i + 1;
}

/*Para o Quick Sort nós escolhemos um "pivô" e organizamos 
o vetor em dois grupos: os menores que o pivô à 
esquerda e os maiores à direita. Depois, faz a 
mesma coisa com cada grupo separadamente  até 
que todos os números estejam organizados. Tendo 
a desvantagem de ser um algoritmo altamente recursivo.
*/
void quickSort (int array[], int inicio, int fim){
	
	if(inicio < fim){
		int p = partir(array, inicio, fim);
		quickSort(array, inicio, p - 1);
		quickSort(array, p + 1, fim);
	}
		
}

//Função utilizada no Merge Sort para organizar os elementos
void merge(int array[], int inicio, int meio, int fim){
	int i, j, k;
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;

	int *esquerda = (int*) malloc(n1 * sizeof(int));
	int *direita = (int*) malloc(n2 * sizeof(int));

	for(i = 0; i < n1; i++){
		esquerda[i] = array[inicio + i];
	}
 
	for(j = 0; j < n2; j++){
		direita[j] = array[meio + 1 + j];
	}

	i = 0;
	j = 0;
	k = inicio;

	while(i< n1 && j < n2){
		if(esquerda[i] <= direita[j]){
			array[k++] = esquerda[i++];
		} else {
			array[k++] = direita[j++];
		}
	}
	
	while (i < n1) {
        array[k++] = esquerda[i++];
    }
	
	while(j < n2){
		array[k++] = direita[j++];
	}

	free(esquerda);
	free(direita);
}

/*O Merge Sort divide o vetor ao meio repetidamente 
até isolar cada número. Depois, ele vem juntando 
esses números de dois em dois, comparando e ordenando, 
até que o vetor inteiro esteja montado novamente.
*/
void mergeSort(int array[], int inicio, int fim){
	if(inicio < fim){
		int meio = inicio + (fim - inicio) / 2;
		mergeSort(array, inicio, meio);
		mergeSort(array, meio + 1, fim);
		merge(array, inicio, meio, fim);
	}
}
//Para imprimir e demostrar os vetores organizados.
void imprimirArray(int array[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
}

int main(void){
	
	setlocale(LC_ALL, "Portuguese");

	int opcao;
	clock_t t;
	int original1[TAM_ARRAY] = {47, 82, 15, 63, 94, 28, 71, 39, 56, 20};
	int original2[TAM_ARRAY] = {15, 20, 28, 39, 47, 56, 63, 71, 82, 94};
	int original3[TAM_ARRAY] = {94, 82, 71, 63, 56, 47, 39, 28, 20, 15};
	
	int array1[TAM_ARRAY];
	int array2[TAM_ARRAY];
	int array3[TAM_ARRAY];

	do {
		
		printf("A partir de agora ordenaremos os vetores: \n");
		printf("1) ");
		for(int i = 0; i < TAM_ARRAY;i++){
			array1[i] = original1[i];
			printf("%d ", array1[i]);
		}
		printf("\n2) ");
		for(int i = 0; i < TAM_ARRAY;i++){
			array2[i] = original2[i];
			printf("%d ", array2[i]);
		}
		printf("\n3) ");
		for(int i = 0; i < TAM_ARRAY;i++){
			array3[i] = original3[i];
			printf("%d ", array3[i]);
		}
		printf("\n\n");

		printf("========== Escolha a opção de ordenação ==========\n\n");
		printf("1. Bubble Sort\n");
		printf("2. Selection Sort\n");
		printf("3. Insertion Sort\n");
		printf("4. Quick Sort\n");
		printf("5. Merge Sort\n");
		printf("6. Sair\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
		
		case 1:
			printf("Vetor 1 ordenado (Bubble Sort): \n");
			t = clock();
			bubbleSort(array1, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array1, TAM_ARRAY);
			printf("\n");
			printf("Vetor 1 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 2 ordenado (Bubble Sort): \n");
			t = clock();
			bubbleSort(array2, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array2, TAM_ARRAY);
			printf("\n");
			printf("Vetor 2 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 3 ordenado (Bubble Sort): \n");
			t = clock();
			bubbleSort(array3, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array3, TAM_ARRAY);
			printf("\n");
			printf("Vetor 3 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			break;
		case 2:
			printf("Vetor 1 ordenado (Selection Sort): \n");
			t = clock();
			selectionSort(array1, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array1, TAM_ARRAY);
			printf("\n");
			printf("Vetor 1 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 2 ordenado (Selection Sort): \n");
			t = clock();
			selectionSort(array2, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array2, TAM_ARRAY);
			printf("\n");
			printf("Vetor 2 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 3 ordenado (Selection Sort): \n");
			t = clock();
			selectionSort(array3, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array3, TAM_ARRAY);
			printf("\n");
			printf("Vetor 3 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			break;

		case 3:
			printf("Vetor 1 ordenado (Insertion Sort): \n");
			t = clock();
			insertionSort(array1, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array1, TAM_ARRAY);
			printf("\n");
			printf("Vetor 1 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 2 ordenado (Insertion Sort): \n");
			t = clock();
			insertionSort(array2, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array2, TAM_ARRAY);
			printf("\n");
			printf("Vetor 2 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 3 ordenado (Insertion Sort): \n");
			t = clock();
			insertionSort(array3, TAM_ARRAY);
			t = clock() - t;
			printf("\n");
			imprimirArray(array3, TAM_ARRAY);
			printf("\n");
			printf("Vetor 3 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			break;

		case 4:
			printf("Vetor 1 ordenado (Quick Sort): \n");
			t = clock();
			quickSort(array1, 0,TAM_ARRAY - 1);
			t = clock() - t;
			printf("\n");
			imprimirArray(array1, TAM_ARRAY);
			printf("\n");
			printf("Vetor 1 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 2 ordenado (Quick Sort): \n");
			t = clock();
			quickSort(array2, 0,TAM_ARRAY - 1);
			t = clock() - t;
			printf("\n");
			imprimirArray(array2, TAM_ARRAY);
			printf("\n");
			printf("Vetor 2 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 3 ordenado (Quick Sort): \n");
			t = clock();
			quickSort(array3, 0,TAM_ARRAY - 1);
			t = clock() - t;
			printf("\n");
			imprimirArray(array3, TAM_ARRAY);
			printf("\n");
			printf("Vetor 3 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			break;

		case 5:
			printf("Vetor 1 ordenado (Merge Sort): \n");
			t = clock();
			mergeSort(array1, 0,TAM_ARRAY - 1);
			t = clock() - t;
			printf("\n");
			imprimirArray(array1, TAM_ARRAY);
			printf("\n");
			printf("Vetor 1 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 2 ordenado (Merge Sort): \n");
			t = clock();
			mergeSort(array2, 0,TAM_ARRAY - 1);
			t = clock() - t;
			printf("\n");
			imprimirArray(array2, TAM_ARRAY);
			printf("\n");
			printf("Vetor 2 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			
			printf("Vetor 3 ordenado (Merge Sort): \n");
			t = clock();
			mergeSort(array3, 0,TAM_ARRAY - 1);
			t = clock() - t;
			printf("\n");
			imprimirArray(array3, TAM_ARRAY);
			printf("\n");
			printf("Vetor 3 ordenado em: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
			printf("\n\n");
			break;

		case 6:
			printf("\nSaindo do programa...\n");
			break;

		default: 
			printf("\nOpção inválida, tente novamente!\n\n");

		}

	} while (opcao !=6);



	return 0;
}
