#include <stdio.h>

int main() {
	int n = 0, soma = 0;
	
	printf("--------------------------------\n");
	printf("   S O M A  A C U M U L A D A   \n");
	printf("--------------------------------\n");
	
	do{
		printf("Digite um numero inteiro: ");
		scanf("%d",&n);
		
		soma += n;
		printf("Soma Acumulada: %d\n",soma);
		
		printf("--------------------------------\n");
	}while(n != 0);
	
	printf("Soma Finalizada");
	return 0;
}
