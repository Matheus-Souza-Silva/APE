#include <stdio.h>

int main() {
	char nome [20], sobrenome [20], nome_completo [20];
	
	printf("Informe o nome: ");
	scanf("%s",&nome);
	
	printf("Informe o sobrenome: ");
	scanf("%s",&sobrenome);
	
	printf("Nome Informado: %s %s\n",nome,sobrenome);
	printf("---------------------------\n");
	
	fflush(stdin);
	printf("Informe nome completo: ");
	scanf("%[^\n]s",&nome_completo);
	
	printf("Nome Completo informado: %s",nome_completo);
	return 0;
}

/*
	Express�o Regular (scan set)
	%[^\n]s permite usar espa�o no scanf, normalmente espa�o significa proximo parametro.
		Enquanto n�o for quebra de linha ele vai continuar a string.
	
	Erros comuns
		N�o usar a express�o regular quando for inserir a entrada de dados com espa�o
		N�o usar fflush(stdin) ou espa�o para limpar o buffer quando tiver trabalhando com char e string.
*/
