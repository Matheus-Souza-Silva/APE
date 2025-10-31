#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 50

void cabecalho();

int main() {
	int i = 0, maior_idade = 0;
	
	struct Endereco{
		char logradouro[20];
		int numero;
		char cep[10];
	};
	
	struct Aluno{
		char nome[30];
		int idade;
		struct Endereco endereco[2];
		float notas[3];
	};
	
	struct Aluno aluno[TAM];
	
	for(i = 0; i < TAM; i++){
		cabecalho();
		
		printf("Entre o nome do %do aluno: ",i+1);
		scanf(" %[^\n]s",&aluno[i].nome);
		
		printf("Entre a idade do %do aluno: ",i+1);
		scanf("%d",&aluno[i].idade);
		
		if(aluno[i].idade > maior_idade){
			maior_idade = aluno[i].idade;
		}
		
		printf("Entre o logradouro (Endereco 1) do %do aluno: ",i+1);
		scanf(" %[^\n]s",&aluno[i].endereco[0].logradouro);
		
		printf("Entre o numero (Endereco 1) do %do aluno: ",i+1);
		scanf("%d",&aluno[i].endereco[0].numero);
		
		printf("Entre o CEP (Endereco 1) do %do aluno: ",i+1);
		scanf(" %s",&aluno[i].endereco[0].cep);
		
		printf("Entre o logradouro (Endereco 2) do %do aluno: ",i+1);
		scanf(" %[^\n]s",&aluno[i].endereco[1].logradouro);
		
		printf("Entre o numero (Endereco 2) do %do aluno: ",i+1);
		scanf("%d",&aluno[i].endereco[1].numero);
		
		printf("Entre o CEP (Endereco 2) do %do aluno: ",i+1);
		scanf(" %s",&aluno[i].endereco[1].cep);
		
		printf("Entre a N1 do %do aluno: ",i+1);
		scanf("%f",&aluno[i].notas[0]);
		
		printf("Entre a N2 do %do aluno: ",i+1);
		scanf("%f",&aluno[i].notas[1]);
		
		printf("Entre a N3 do %do aluno: ",i+1);
		scanf("%f",&aluno[i].notas[2]);
	}
	
	printf("--------------------------------\n");
	printf("---------MAIOR IDADE: %d--------\n",maior_idade);
	printf("--------------------------------\n");
	printf("Alunos com a maior Idade: \n");
	
	for(i = 0; i < TAM; i++){
		if(aluno[i].idade == maior_idade){
			printf("Aluno: %s\n | Idade: %d\n",aluno[i].nome,aluno[i].idade);
		}
	}
	
	return 0;
}

void cabecalho(){
	system("cls");
	printf("--------------------------------\n");
	printf("    S   T   R   U   C   T   S   \n");
	printf("--------------------------------\n");
}
