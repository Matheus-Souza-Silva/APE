#include <stdio.h>

int main() {
	char nome[20];
	int idade = 0;
	char status;
	float altura;
	char email[20];
	double salario;
	
	printf("----------------------\n");
	printf("   C A D A S T R O\n");
	printf("----------------------\n");
	
	printf("\nInsira seu nome: ");
	scanf("%s",&nome);
	
	printf("Insira sua idade: ");
	scanf("%d",&idade);
	
	printf("Insira seu status (a ou i): ");
	fflush(stdin);
	scanf(" %c",&status);
	
	printf("Insira sua altura: ");
	scanf("%f",&altura);
	
	printf("Insira seu email: ");
	scanf("%s",&email);
	
	printf("Insira seu salario (coin): ");
	scanf("%lf",&salario);
	
	printf("\n----------------------\n");
	
	printf("\nNome: %s\n",nome);
	printf("Idade: %d\n",idade);
	printf("Status: %c\n",status);
	printf("Altura: %.2f\n",altura);
	printf("E-mail: %s\n",email);
	printf("Salario: %lf\n",salario);
	return 0;
}

/*
	---Exemplos de variáveis para cada tipo--- 
		int idade
		char estados
		float altura
		double criptomoeda
	
	---String---
		char *nome* [];
		Não tem um tipo primitivo string
		
		--Especificador de string--
			%s
			
	---Observações---
	"&" usado para dizer o endereço da variável na memória
	Toda vez que trabalhar com string e char tem que ficar de olho no buffer, sempre usar fflush(stdin) para limpar o buffer ou colocar espaço antes do especificador do scanf.
*/
