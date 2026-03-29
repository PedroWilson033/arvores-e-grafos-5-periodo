#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

bool pesquisaSequencial (int arr[], int n, int valor, int comp){
	for(int i = 0; i < n; i++){
		comp++;
		if(arr[i] == valor){
			printf("Matrícula encontrada! Aluno presente\n");
			printf("Matrícula %d encontrada na posição %d\n", valor, i+1);
			printf("Número de comparações: %d", comp);
			return true;
		}
	}
	
	printf("Matrícula não encontrada! Aluno ausente");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int matriculas[5] = {101, 102, 103, 104, 105};
	int busca = 103, comp = 0;
	
	printf("Buscando o número da matrícula %d\n", busca);
	
	pesquisaSequencial(matriculas, 5, busca, comp);

	return 0;
}

