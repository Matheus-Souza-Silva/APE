#include <stdio.h>

int main() {
	float emprestimo, liquido;
	int meses = 0;
	
	printf("Insira Emprestimo: ");
	scanf("%f",&emprestimo);
	
	printf("Insira a quantidade de meses: ");
	scanf("%d",&meses);
	
	liquido = emprestimo + (emprestimo * meses * 0.05);
	
	printf("\nEmprestimo: R$%.2f\nMeses: %d\nValor Liquido: R$%.2f",emprestimo,meses,liquido);
	return 0;
}
