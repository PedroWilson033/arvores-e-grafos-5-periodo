#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

void pesquisaSequencial (int arr[], int n, int valor, int *qtdAcessos){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			(*qtdAcessos)++;
		}
	}
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int numeros[6] = {1, 2, 3, 2, 4, 2};
	int busca = 2, qtdAcessos = 0;
	
	printf("Buscando número %d\n", busca);
	
	pesquisaSequencial(numeros, 6, busca, &qtdAcessos);
	
	if(qtdAcessos > 0){
		printf("ID %d acessou o sistema!\n", busca);
		printf("Quantidade de acessos: %d", qtdAcessos);
	} else {
		printf("ID %d não acessou o sistema!\n", busca);
	}

	return 0;
}

