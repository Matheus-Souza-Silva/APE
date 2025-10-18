#include <stdio.h>
#include <string.h> // Biblioteca de string

int main() {
	// Vetores de Structs
	struct Aluno{
		char nome[20];
		int idade;
		float notas[2];
	};
	
	struct Aluno aluno[20]; // Vetor de aLunos
	
	// Aluno 1 [0]
	printf("Informe o Nome: ");
	scanf(" %[^\n]s",&aluno[0].nome);
	
	printf("Informe a Idade: ");
	scanf("%d",&aluno[0].idade);
	
	printf("Nome: %s\nIdade: %d\n", aluno[0].nome, aluno[0].idade);
	
	// Aluno 2 [1]
	printf("Informe o Nome: ");
	scanf(" %[^\n]s",&aluno[1].nome);
	
	printf("Informe a Idade: ");
	scanf("%d",&aluno[1].idade);
	
	printf("Nome: %s\nIdade: %d\n", aluno[1].nome, aluno[1].idade);
	
	printf("Aluno 1 - %s - %d\nAluno 2 - %s - %d",aluno[0].nome, aluno[0].idade, aluno[1].nome, aluno[1].idade);
	
	// Struct de Struct
	struct End{
		char endereco[30];
		int numero;
		char complemento[20];
		char cep[10];
	};
	
	struct Aluno{
		char nome[20];
		int idade;
		struct End end;
	};
	
	struct Aluno aluno;
	aluno.idade = 15;
	aluno.end.numero = 100;
	
	printf("Informe o CEP do Estudante: ");
	scanf(" %s",&aluno.end.cep);
	
	printf("O CEP informado foi: %s\n",aluno.end.cep);
	int idade[3];
	int i = 0;
	
	for(i = 0; i < 3; i++) {
		idade[i] = 120;
	}
	
	for(i = 0; i < 3; i++) {
		printf("Idade: %d\n", idade[i]);
	}

	// Struct
	struct Produto{
		char desc[20];
		float valor;
	};

	struct Produto produto1, produto2;
	
	strcpy(produto1.desc, "Margarina Boa");
	produto1.valor = 15.4;
	
	strcpy(produto2.desc, "Outra Margarina Boa");
	produto2.valor = 23.6;

	printf("--------------------------------\n");
	
	printf("Nome do Produto 1: %s | Valor do Produto 1: %.2f\n",produto1.desc, produto1.valor);
	printf("Nome do Produto 2: %s | Valor do Produto 2: %.2f",produto2.desc, produto2.valor);
	
	struct Aluno{
		char nome[20];
		int idade;
	};
	
	struct Aluno aluno;
	
	strcpy(aluno.nome, "Diego"); // Atribuição de String
	aluno.idade = 15;

	printf("Idade (aluno): %d | Nome (aluno): %s",aluno.idade, aluno.nome);

	printf("--------------------------------\n");
	printf("Informe a Idade do aluno: ");
	scanf("%d",&aluno.idade);

	fflush(stdin);
	printf("Informe o Nome do aluno: ");
	scanf("%[^\n]s",&aluno.nome);
	printf("--------------------------------\n");

	printf("Idade (aluno): %d | Nome (aluno): %s",aluno.idade, aluno.nome);
	return 0;
}

/* 
---
	Diferença entre Funções e Procedimentos
		Função - Tem retorno
		Procedimento - Não tem retorno
		
	# Estrutura de Dados Composta Heterogênea
		
		Structs
		
			Estrutura
				struct Aluno{
					char nome[20]; - Variável Membro
					int idade; - Variável Membro | Não inicializar tipo inteiro com 0 quando está dentro da estrutura, porque a estrutura so serve para declarar as variáveis
				}; - Pode-se declarar a variavel do tipo Aluno entre } e ;
				
				struct Aluno aluno; - E uma boa prática declarar uma variavel do tipo struct em outra linha
				
				aluno.idade = 15; // Declaração da idade na variável aluno
				
				printf("Idade: %d", aluno.idade);
				
				scanf("%d",&aluno.idade);
				
				printf("Idade: %d", aluno.idade);
---
*/
