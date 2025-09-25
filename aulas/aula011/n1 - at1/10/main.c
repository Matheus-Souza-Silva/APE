#include <stdio.h>

int main() {
	int valor = 0, bonus = 0;
	
	printf("Insira o Valor das Vendas: ");
	scanf("%d",&valor);
	
	if(valor >= 10000){
		bonus = valor * 0.10;
		printf("Bonus de Produtividade: %d",bonus);
	} else{
		bonus = 0;
		printf("Bonus de Produtividade: %d",bonus);
	}
	return 0;
}
