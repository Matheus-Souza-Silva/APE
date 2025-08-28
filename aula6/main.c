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
	Atribui��o
		=
	Compara��o
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
	L�gicos
		&& || !
Tabela Verdade
	&& (AND) As duas afirma��es precisam ser verdadeiras para a sa�da ser verdadeira
		V V = V
		V F = F
		F V = F
		F F = F
	
	|| (OR) Pelo menos uma afirma��o precisa ser verdadeira para a sa�da ser verdadeira
		V V = V
		V F = V
		F V = V 
		F F = F
	
	! (NOT) Qualquer que seja a sa�da ele vai inverter (V -> F || F -> V)
		!(V V = V) = F
		!(V F = V) = F
		!(F V = V) = F
		!(F F = F) = V
Observa��es
	Pense nas fun��es com chaves {} como blocos (main, if, else etc)
		Se coloca dentro dos blocos qualquer instru��o v�lida
*/
