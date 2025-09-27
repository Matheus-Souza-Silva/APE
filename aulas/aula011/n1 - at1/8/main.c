#include <stdio.h>

int main() {
	float saldo, valor;
	
	printf("--------------------------------\n");
	printf("    S A L D O  E  C O M P R A   \n");
	printf("--------------------------------\n");
	
	printf("Insira o Saldo Atual: ");
	scanf("%f",&saldo);
	
	printf("Insira o Valor da Compra: ");
	scanf("%f",&valor);
	
	printf("--------------------------------\n");
	if(saldo >= valor){
		printf("Compra Autorizada");
	} else{
		printf("Compra Negada");
	}
	return 0;
}
