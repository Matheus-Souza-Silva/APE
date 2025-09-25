#include <stdio.h>

int main() {
	int n1 = 0, n2 = 0;
	char op;
	
	printf("--------------------------------\n");
	printf("---------- Calculadora ---------\n");
	printf("--------------------------------\n");
	
	printf("Insira o primeiro numero: ");
	scanf("%d",&n1);
	
	fflush(stdin);
	printf("Informe OP: ");
	scanf("%c",&op);
	
	printf("Insira o segundo numero: ");
	scanf("%d",&n2);
	
	printf("--------------------------------\n");
	
	if(op == '-'){
		printf("Resultado: %d",n1 - n2);
	} else {
		if(op == '+'){
			printf("Resultado: %d",n1 + n2);
		} else {
			if(op == '*'){
				printf("Resultado: %d",n1 * n2);
			} else {
				if(op == '/'){
					printf("Resultado: %d",n1 / n2);
				} else {
					if(op == '%'){
						printf("Resultado: %d",n1 % n2);
					} else {
						printf("Operacao Invalida");
					}
				}
			}
		}
	}
	return 0;
}

/*
Estruturas de decisão
	if
	if/else
	switch/case
		switch(){
			case:
			break;
			
			case:
			break;
			
			default:
		}

Estruturas de Repetição
	for
	while
	do..while
*/
