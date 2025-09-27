#include <stdio.h>

int main() {
	float bruto, liquido;
	int meses = 0;
	
	printf("--------------------------------\n");
	printf("       E M P R E S T I M O      \n");
	printf("--------------------------------\n");
	
	printf("Insira o valor do Emprestimo: ");
	scanf("%f",&bruto);
	
	printf("Insira a quantidade de meses: ");
	scanf("%d",&meses);
	
	if(bruto <= 0){
		printf("ERRO: O valor do emprestimo deve ser positivo\n");
		return 1;
	}
	
	if(meses <= 0){
		printf("ERRO: A quantidade de meses deve ser positivo\n");
		return 1;
	}
	
	liquido = bruto / (1 + 0.05 * meses);
	
	printf("--------------------------------\n");
	printf("Valor Bruto: R$%.2f\nValor Liquido: R$%.2f\nTaxa de Juros ao mes: 5%\nMeses: %d",bruto,liquido,meses);
	return 0;
}
