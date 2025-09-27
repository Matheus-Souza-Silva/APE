#include <stdio.h>

int main() {
	int opcao = 0;
	
	printf("--------------------------------\n");
	printf("      S    A    Q    U    E     \n");
	printf("--------------------------------\n");
	
	printf("Opcoes: \n1 - Saque\n2 - Saldo\n0 - Sair\n");
	printf("--------------------------------\n");
	
	do{
		printf("Digite uma opcao com o numero correspondente: ");
		scanf("%d",&opcao);
		printf("--------------------------------\n");
	}while(opcao != 0);
	
	printf("Sair escolhido");
	return 0;
}
