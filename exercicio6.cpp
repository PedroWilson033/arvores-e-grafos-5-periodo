#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

void pesquisaSequencial (int arr[], int n, int valor, int qtdVendas){
	for(int i = 0; i < n; i++){
		if(arr[i] == valor){
			qtdVendas++;
			printf("Número de vendas de %d reais encontrado na posição %d\n", valor, i+1);
		}
	}
	
	printf("Quantidade de vendas de 200: %d", qtdVendas);
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	int vendas[5] = {100, 200, 150, 300, 200};
	int busca = 200, qtdVendas = 0;
	
	printf("Buscando vendas que atingiram o valor de %d\n", busca);
	
	pesquisaSequencial(vendas, 5, busca, qtdVendas);

	return 0;
}

