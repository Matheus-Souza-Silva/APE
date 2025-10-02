#include <stdio.h>

int main() {
	int idade = 0, soma_idades = 0, i;
	float media;
	
	printf("--------------------------------\n");
	printf("      I   D   A   D   E   S     \n");
	printf("--------------------------------\n");
	printf("Digite as idades de 30 pessoas\n");
	printf("--------------------------------\n");
	
	for(i = 1;i <= 30;i++){
		printf("Idade da Pessoa %d: ",i);
		scanf("%d",&idade);
		if(idade < 0){
			printf("--------------------------------\n");
			printf("Idade Invalida");
			return 1;
		}
		soma_idades += idade;
	}
	
	media = soma_idades / 30;
	
	printf("--------------------------------\n");
	printf("Soma total das idades: %d\nMedia geral das idades: %.2f",soma_idades,media);
	return 0;
}
