#include <stdio.h>

int main() {
	int mesAtual = 0, mesAnterior = 0;
	float consumo, fatura;
	
	printf("-------------------------------\n");
	printf(" C o n s u m o  e  F a t u r a\n");
	printf("-------------------------------\n");
	
	printf("Insira o Mes Atual: ");
	scanf("%d",&mesAtual);
	
	printf("Insira o Mes Anterior: ");
	scanf("%d",&mesAnterior);
	
	consumo = mesAtual - mesAnterior;
	fatura = consumo * 0.75;
	
	printf("\nMes Atual: %dkWh\nMes Anterior: %dkWh\nConsumo Mensal: %.2fkWh\nTotal da Fatura: R$%.2f",mesAtual,mesAnterior,consumo,fatura);
	return 0;
}
