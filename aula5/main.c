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
	Expressão Regular (scan set)
	%[^\n]s permite usar espaço no scanf, normalmente espaço significa proximo parametro.
		Enquanto não for quebra de linha ele vai continuar a string.
	
	Erros comuns
		Não usar a expressão regular quando for inserir a entrada de dados com espaço
		Não usar fflush(stdin) ou espaço para limpar o buffer quando tiver trabalhando com char e string.
*/
