#include <stdio.h>

int main() {
	float nota1, nota2, nota3, media;
	
	printf("--------------------------------\n");
	printf("  M E D I A  D A S  P R O V A S \n");
	printf("--------------------------------\n");
	
	printf("Insira o Valor da Prova 1: ");
	scanf("%f",&nota1);
	
	printf("Insira o Valor da Prova 2: ");
	scanf("%f",&nota2);
	
	printf("Insira o Valor da Prova 3: ");
	scanf("%f",&nota3);
	
	media = (nota1 + nota2 + nota3) / 3;
	
	printf("--------------------------------\n");
	if(media >= 7){
		printf("Aluno Aprovado");
	} else{
		printf("Aluno Reprovado");
	}
	return 0;
}
