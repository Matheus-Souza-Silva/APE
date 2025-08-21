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
	Desenvolva um programa onde serão declaradas as variáveis abaixo e apresente seus valores na tela:
	
	idade (ex: 89)
	altura (ex: 1.87)
	peso (ex: 82.1234567)
	status (ex: 'a')
*/

/*
Variáveis
	Definição: Alocação de espaço em memória
	Não se cria uma variável, se declara uma variável
	- Ciclos:
		1. Declaração (Nome e Tipo) Exemplo: int idade;
		2. Atribuição de valores (Quando e a primeira atribuição da variável se chama de Inicialização) Exemplo: idade=5;
	
	- Nome (identificador)
		- Não pode ter espaço, acento e cedilha e caractere especial (com exceção do "_")
		- Não pode começar com número
		- Não pode ser uma palavra reservada
		- Convenção de código em C: Não se usa maíusculo
		- Exemplo: nome_completo
		
	- Tipo
		Obs.: Não se cria tipo, se escolhe tipo
		- int: número inteiro (-35, 5, 8, 9090)
		- char: UM caractere, é utilizado com '' ('a', 'X', 's', '@', '!')
		- float: número com ponto, ocupa metade do espaço de memória do double (-85.5678)
		- double: mais de seis casas decimais (-85.56781011)
		Especificadores dos tipos:
			- int    %d || %i
			- char   %c
			- float  %f Quando se coloca .x entre a porcentagem e o f vai dizer quantas casas decimais vai mostrar
			- double %lf
		
	- Valor
	
*/
