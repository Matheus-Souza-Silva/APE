#include <stdio.h>

int main() {
	char nome[20];
	int idade = 0;
	float altura;
	
	printf("Nome do Paciente: ");
	scanf("%s",&nome);
	
	fflush(stdin);
	printf("Idade do Paciente: ");
	scanf("%d",&idade);
	
	printf("Altura em metros do Paciente: ");
	scanf("%f",&altura);
	
	printf("\nPaciente %s possui %d anos e altura de %.2fm",nome, idade, altura);
	return 0;
}
