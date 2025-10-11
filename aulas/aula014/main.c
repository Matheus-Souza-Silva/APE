#include <stdio.h>

int soma(int n1, int n2); // Prototipação da Função soma
int subtracao(int n1, int n2); // Prototipação da Função subtracao
int multiplicacao(int n1, int n2); // Prototipação da Função multiplicacao
int divisao(int n1, int n2); // Prototipação da Função divisao
int mod(int n1, int n2); // Prototipação da Função mod
char le_valida_op(); // Prototipação da Funçõa le_valida_op

int main() {
	int n1 = 0, n2 = 0;
	char op;
	
	printf("--------------------------------\n");
	printf("      C A L C U L A D O R A     \n");
	printf("--------------------------------\n");
	
	printf("Insira N1: ");
	scanf("%d",&n1);
	
	printf("Insira N2: ");
	scanf("%d",&n2);
	
	op = le_valida_op(); // Chamada da funcao le_valida_op
	
	printf("--------------------------------\n");
	
	switch(op){
		case '+': 
			printf("Resultado: %d", soma(n1, n2)); // Chamada da funcao soma
		break;
		
		case '-':
			printf("Resultado: %d", subtracao(n1,n2)); // Chamada da funcao subtracao
		break;
		
		case '*':
			printf("Resultado: %d", multiplicacao(n1,n2)); // Chamada da funcao multiplicacao
		break;
		
		case '/':
			if(n2 == 0){
				printf("Operacao Invalida (Denominador = 0)");
			} else{
				printf("Resultado: %d", divisao(n1,n2)); // Chamada da funcao divisao
			}
		break;
		
		case '%':
			printf("Resultado: %d", mod(n1,n2)); // Chamada da funcao mod
		break;
	}
	
	return 0;
}

// Declaração da função soma
int soma(int n1, int n2){
	int result = 0;
	result = n1 + n2;
	return result;
}

// Declaração da função subtracao
int subtracao(int n1, int n2){
	int result = 0;
	result = n1 - n2;
	return result;
}

// Declaração da função multiplicacao
int multiplicacao(int n1, int n2){
	int result = 0;
	result = n1 * n2;
	return result;
}

// Declaração da função divisao
int divisao(int n1, int n2){
	int result = 0;
	result = n1 / n2;
	return result;
}

// Declaração da função mod
int mod(int n1, int n2){
	int result = 0;
	result = n1 % n2;
	return result;
}

// Declaração da função le_valida_op
char le_valida_op(){
	char op;
	int cont = 0;
	
	do{
		if(cont > 0){
			system("cls");
			printf("--------------------------------\n");
			printf("      C A L C U L A D O R A     \n");
			printf("--------------------------------\n");
			printf("| > Operador Invalido\n");
		}
		
		printf("Escolha a operacao (+, -, *, /, %%): ");
		scanf(" %c",&op);
		
		cont++;
	}while(op != '+' && op != '-' && op != '*' && op != '/' && op != '%');
}

/*
	-> * -> | Entrada Processamento Saida
	
	Modularização (Subprogramas)
		Variavel de escopo: Funciona somente dentro da função
	
	Existem 3 momentos trabalhando com função
		1 = Declaração
			int soma(int n1, int n2){
				int result = n1 + n2;
				return result;
			}
		2 = Prototipação
			int soma(int n1, int n2);
		3 = Chamada
			soma(5,6);
	
	----REPETICAO----
	
	For
		Trabalha muito com iterações, números, inteiros
		A variavel controladora de forma invariavel sempre vai ser inteiro
		
	While
		Maior controle no tipo da variavel
		
	do...while
		Trata da questão do grande loop
	
	----DECISAO----
	
	switch case
		Bom para situações predefinidas
		Usado muito em menus
*/
