#include <stdio.h>

int main() {
	int opcao = 0;
	
	printf("--------------------------------\n");
	printf("  C   A   R   D   A   P   I   O \n");
	printf("--------------------------------\n");
	
	printf("1 - Pizza\n2 - Hambuguer\n3 - Salada\n4 - Sair\n");
	
	printf("--------------------------------\n");
	printf("Escolha uma opcao digitando o numero correspondente: ");
	scanf("%d",&opcao);
	printf("--------------------------------\n");
	
	switch(opcao){
		case 1:
			printf("Pizza escolhida");
		break;
		
		case 2:
			printf("Hambuguer escolhido");
		break;
		
		case 3:
			printf("Salada escolhida");
		break;
		
		case 4:
			printf("Sair escolhido");
		break;
		
		default:
			printf("Opcao Invalida");
	}
	return 0;
}
