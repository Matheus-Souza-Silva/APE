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
	
	switch(op){
		case '+':
			printf("Resultado: %d",n1 + n2);
		break;
		
		case '-':
			printf("Resultado: %d",n1 - n2);
		break;
		
		case '*':
			printf("Resultado: %d",n1 * n2);
		break;
		
		case '/':
			if(n2 == 0){
				printf("Invalido");
			} else {
				printf("Resultado: %d",n1 / n2);
			}
		break;
		
		case '%':
			printf("Resultado: %d",n1 % n2);
		break;
		
		default:
			printf("Operacao Invalida");
	}
	return 0;
}

/*
Quando se usa switch/case?
	Quando se tem situações pre definidas
*/
