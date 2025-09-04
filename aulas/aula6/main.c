#include <stdio.h>

int main() {
	int n1 = 0, n2 = 0;
	
	printf("===COMPARADOR===\n");
	
	printf("N1: ");
	scanf("%d",&n1);
	
	printf("N2: ");
	scanf("%d",&n2);
	
	if(n1 == n2){
		printf("\nIguais!\n");
	} else {
		if(n1 > n2){
			if(n1 % 2 == 0){
				printf("\nN1 Par!\n");
			} else {
				printf("\nN1 Impar!\n");
			}
		} else {
			if(n2 % 2 == 0) {
				printf("\nN2 Par!\n");
			} else {
				printf("\nN2 Impar!\n");
			}
		}
	}
	
	return 0;
}
/*
Operadores
	Aritmeticos
		+ - * / %
	Atribuição
		=
	Comparação
		== != > < >= <=
		Exemplos:
			a = 5
			b = 7
				a > b false
				a < b true
				a == b false
				a != b true
				a >= b false
				a <= b true
			a = 5
			b = 5
				a > b = false
				a < b = false
				a == b = true
				a != b = false
				a >= b = true
				a <= b = true
	Lógicos
		&& || !
Tabela Verdade
	&& (AND) As duas afirmações precisam ser verdadeiras para a saída ser verdadeira
		V V = V
		V F = F
		F V = F
		F F = F
	
	|| (OR) Pelo menos uma afirmação precisa ser verdadeira para a saída ser verdadeira
		V V = V
		V F = V
		F V = V 
		F F = F
	
	! (NOT) Qualquer que seja a saída ele vai inverter (V -> F || F -> V)
		!(V V = V) = F
		!(V F = V) = F
		!(F V = V) = F
		!(F F = F) = V
Observações
	Pense nas funções com chaves {} como blocos (main, if, else etc)
		Se coloca dentro dos blocos qualquer instrução válida
*/
