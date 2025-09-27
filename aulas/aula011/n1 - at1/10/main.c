#include <stdio.h>

int main() {
	int valor = 0, bonus = 0;
	
	printf("--------------------------------\n");
	printf("    P R O D U T I V I D A D E   \n");
	printf("--------------------------------\n");
	
	printf("Insira o Valor das Vendas: ");
	scanf("%d",&valor);
	
	printf("--------------------------------\n");
	if(valor >= 10000){
		bonus = valor * 0.10;
		printf("A meta de R$ 10000 foi atingida!\n");
	} else{
		bonus = 0;
		printf("A meta de R$ 10000 nao foi atingida.");
	}
	
	printf("Valor das Vendas: R$ %d\n",valor);
	printf("Bonus de produtividade: R$ %d",bonus);
	return 0;
}
