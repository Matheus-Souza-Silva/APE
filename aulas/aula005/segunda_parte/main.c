#include <stdio.h>

int main() {
	double primeiro, segundo;
	
	printf("DIMIUIDORA\n");
	
	printf("Informe n1: ");
	scanf("%lf",&primeiro);
	
	printf("Informe n2: ");
	scanf("%lf",&segundo);
	
	printf("O resultado sera: %lf",primeiro-segundo);
	return 0;
}

/*
	Nova expressão aritmetica
	% - em aritmetica significa "mod", resto da divisão
		Exemplo: 17 % 5 = 2
			3 * 5 = 15
			17 - 15 = 2
		Exemplo: 15 % 5 = 0
			3 * 5 = 15
			15 - 15 = 0
	E util para descobrir multiplos e par/impar
*/
