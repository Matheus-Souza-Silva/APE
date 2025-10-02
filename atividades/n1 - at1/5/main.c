#include <stdio.h>

int main() {
	int mesAtual = 0, mesAnterior = 0, consumo = 0;
	float fatura;
	
	printf("-------------------------------\n");
	printf(" C O N S U M O  E  F A T U R A \n");
	printf("-------------------------------\n");
	
	printf("Insira a leitura do Mes Atual (em kWh): ");
	scanf("%d",&mesAtual);
	
	printf("Insira a leitura do Mes Anterior (em kWh): ");
	scanf("%d",&mesAnterior);
	
	if(mesAtual < mesAnterior){
		printf("-------------------------------\n");
        printf("ERRO: A leitura atual nao pode ser menor que a leitura anterior!");
        return 1;
	}
	
	consumo = mesAtual - mesAnterior;
	fatura = consumo * 0.75;
	
	printf("-------------------------------\n");
	printf("Mes Atual: %dkWh\nMes Anterior: %dkWh\nConsumo Mensal: %dkWh\nTotal da Fatura: R$%.2f",mesAtual,mesAnterior,consumo,fatura);
	return 0;
}
