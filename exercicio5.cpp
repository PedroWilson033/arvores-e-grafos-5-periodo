#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

bool pesquisaSequencial (int arr[], int n, int valor){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			printf("Alguém atingiu a nota máxima!\n");
			printf("Nota %d encontrada na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("Infelizmente, nenhum aluno tirou nota máxima!");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int notas[5] = {7, 8, 5, 9, 6};
	int busca = 10;
	
	printf("Buscando o nota máxima %d\n", busca);
	
	pesquisaSequencial(notas, 5, busca);

	return 0;
}

