#include <stdio.h>

int main() {
	int idade = 0;
	float altura;
	
	printf ("Informe sua altura: ");
	scanf("%f",&altura);
	
	printf ("Informa sua idade: ");
	scanf("%d",&idade);
	
	printf ("Sua altura: %.2f\nSua idade: %d",altura,idade);
	return 0;
}

/*
	Operador (=) serve para atribuição/receber
	O termo certo do "=" em variável e receber. Por exemplo: "idade = 10" idade recebe 10
	
	Operador (==) serve para comparar valores
	
	scanf("",)
		São dois parametros que serão colocados.
		O primeiro será o especificador da variavel 
		E o segundo a localizaçao da variável na memória
*/
