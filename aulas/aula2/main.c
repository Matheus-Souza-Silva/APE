#include <stdio.h>

int main() {
	int idade = 0;
	idade = 89;
	
	float altura = 0;
	altura = 1.87;
	
	double peso = 0;
	peso = 82.1234567;
	
	char status = 'a';
	status = 'S';
	
	double imc = 0;
	imc = peso / (altura * altura);
	
	printf ("Idade: %d\n",idade);
	printf ("Altura: %.2f\n",altura);
	printf ("Peso: %lf\n",peso);
	printf ("Status: %c\n",status);
	printf ("IMC: %lf",imc);
	
	return 0;
}
/*
   --- Atividade ---
	Desenvolva um programa onde ser�o declaradas as vari�veis abaixo e apresente seus valores na tela:
	
	idade (ex: 89)
	altura (ex: 1.87)
	peso (ex: 82.1234567)
	status (ex: 'a')
*/

/*
Vari�veis
	Defini��o: Aloca��o de espa�o em mem�ria
	N�o se cria uma vari�vel, se declara uma vari�vel
	- Ciclos:
		1. Declara��o (Nome e Tipo) Exemplo: int idade;
		2. Atribui��o de valores (Quando e a primeira atribui��o da vari�vel se chama de Inicializa��o) Exemplo: idade=5;
	
	- Nome (identificador)
		- N�o pode ter espa�o, acento e cedilha e caractere especial (com exce��o do "_")
		- N�o pode come�ar com n�mero
		- N�o pode ser uma palavra reservada
		- Conven��o de c�digo em C: N�o se usa ma�usculo
		- Exemplo: nome_completo
		
	- Tipo
		Obs.: N�o se cria tipo, se escolhe tipo
		- int: n�mero inteiro (-35, 5, 8, 9090)
		- char: UM caractere, � utilizado com '' ('a', 'X', 's', '@', '!')
		- float: n�mero com ponto, ocupa metade do espa�o de mem�ria do double (-85.5678)
		- double: mais de seis casas decimais (-85.56781011)
		Especificadores dos tipos:
			- int    %d || %i
			- char   %c
			- float  %f Quando se coloca .x entre a porcentagem e o f vai dizer quantas casas decimais vai mostrar
			- double %lf
		
	- Valor
	
*/
