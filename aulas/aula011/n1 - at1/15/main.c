#include <stdio.h>

int main() {
	int codigo = 0, soma = 0;
	
	printf("--------------------------------\n");
	printf("       P  A  C  O  T  E  S      \n");
	printf("--------------------------------\n");
	
	while(codigo != -1){
		printf("Insira a quantidade de pacotes: ");
		scanf("%d",&codigo);
		
		if(codigo == -1){
			printf("Quantidade Total de Pacotes Registrados: %d\n",soma);
		} else{
			soma += codigo;
			printf("Quantidade Total de Pacotes Registrados: %d\n",soma);
		}
		
		printf("--------------------------------\n");
	}
	printf("Fim da Entrada de Pacotes");
	return 0;
}
