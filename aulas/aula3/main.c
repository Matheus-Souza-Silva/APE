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
	Operador (=) serve para atribui��o/receber
	O termo certo do "=" em vari�vel e receber. Por exemplo: "idade = 10" idade recebe 10
	
	Operador (==) serve para comparar valores
	
	scanf("",)
		S�o dois parametros que ser�o colocados.
		O primeiro ser� o especificador da variavel 
		E o segundo a localiza�ao da vari�vel na mem�ria
*/
