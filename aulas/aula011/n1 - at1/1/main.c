#include <stdio.h>

int main() {
	char medicamento[30];
	int codigo = 0;
	float valor;
	
	printf("Entre o nome do medicamento: ");
	scanf("%s",&medicamento);
	
	fflush(stdin);
	printf("Entre o codigo numerico: ");
	scanf("%d",&codigo);
	
	printf("Entre o valor unitario: ");
	scanf("%f",&valor);
	
	printf("\nMedicamento: %s\nCodigo: %d\nValor Unitario: %.2f",medicamento, codigo, valor);
	return 0;
}
