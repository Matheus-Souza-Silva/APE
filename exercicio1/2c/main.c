#include <stdio.h>

int main() {
	int n1, n2, adicao, subtracao, multiplicacao, divisao, mod;
	printf("==================\n");
	printf("    CALCULATUDO   \n");
	printf("==================\n");
	
	printf("N1: ");
	scanf("%d",&n1);
	
	printf("N2: ");
	scanf("%d",&n2);
	
	adicao = n1 + n2;
	subtracao = n1 - n2;
	multiplicacao = n1 * n2;
	divisao = n1 / n2;
	mod = n1 % n2;
	
	printf("ADICAO: %d\nSUBTRACAO: %d\nMULTIPLICACAO: %d\nDIVISAO: %d\nMOD: %d",adicao,subtracao,multiplicacao,divisao,mod);
	return 0;
}
