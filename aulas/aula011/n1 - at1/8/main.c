#include <stdio.h>

int main() {
	float saldo, valor;
	
	printf("Insira o Saldo Atual: ");
	scanf("%f",&saldo);
	
	printf("Insira o Valor da Compra: ");
	scanf("%f",&valor);
	
	if(saldo >= valor){
		printf("Compra Autorizada");
	} else{
		printf("Compra Negada");
	}
	return 0;
}
