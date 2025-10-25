#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char nome[30];
	char sobrenome[30];
	int i = 0;
	
	printf("--------------------------------\n");
	printf("      Don't Worry Airlines      \n");
	printf("--------------------------------\n");
	
	printf("Insira o seu Nome Completo: ");
	scanf("%[^\n]s",&nome);
	
	for(i = 0;i < strlen(nome);i++){
		if(nome[i] == ' '){
			int j = 0;
			for(j = i+1; j < strlen(nome)-i; j++){
				strcat(sobrenome,nome[i]);
			}
		}
	}
	
	nome[0] = toupper(nome[0]);
	
	printf("+-------------------------+\n");
	printf("|       %s/%s     |\n",sobrenome,nome);
	printf("|       Boa Viagem!       |\n");
	printf("+-------------------------+");
	return 0;
}
