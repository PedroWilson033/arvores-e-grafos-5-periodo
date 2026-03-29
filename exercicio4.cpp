#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<stdbool.h>
#include<string.h>

bool pesquisaSequencial (char arr[][10], int n, char valor[]){
	for(int i = 0; i < n; i++){
		if(strcmp(arr[i], valor) == 0){
			printf("Convidado encontrado/a! Está autorizado/a a entrar no evento\n");
			printf("Convidado/a %s encontrado/a na posição %d\n", valor, i+1);
			return true;
		}
	}
	
	printf("Convidado não encontrado! Não está autorizado/a a entrar no evento\n");
	return false;
}

int main(){
	setlocale (LC_ALL, "Portuguese");

	char convidados[4][10] = {"Ana", "Bruno", "Carlos", "Diana"};
	char busca[10] = "Diana";
	
	printf("Buscando o convidado/a %s\n", busca);
	
	pesquisaSequencial(convidados, 4, busca);

	return 0;
}

