#include <stdio.h>

int main() {
	char nome[20];
	int idade = 0;
	float altura;
	
	printf("--------------------------------\n");
	printf("       C O N S U L T A S        \n");
	printf("--------------------------------\n");
	
	printf("Nome do Paciente: ");
	scanf("%s",&nome);
	
	fflush(stdin);
	printf("Idade do Paciente: ");
	scanf("%d",&idade);
	
	printf("Altura em metros do Paciente: ");
	scanf("%f",&altura);
	
	printf("--------------------------------\n");
	printf("Paciente %s possui %d anos e altura de %.2fm",nome, idade, altura);
	return 0;
}
