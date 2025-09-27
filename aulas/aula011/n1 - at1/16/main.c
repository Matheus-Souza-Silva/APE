#include <stdio.h>

int main() {
	int senha = 0;
	
	printf("--------------------------------\n");
	printf("      S    E    N    H    A     \n");
	printf("--------------------------------\n");
	
	while(senha != 12345){
		printf("Digite a senha: ");
		scanf("%d",&senha);
	}
	printf("--------------------------------\n");
	printf("Senha Correta!");
	return 0;
}
