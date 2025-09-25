#include <stdio.h>

int main() {
	float nota1, nota2, nota3, media;
	
	printf("Insira o Valor da Nota 1: ");
	scanf("%f",&nota1);
	
	printf("Insira o Valor da Nota 2: ");
	scanf("%f",&nota2);
	
	printf("Insira o Valor da Nota 3: ");
	scanf("%f",&nota3);
	
	media = (nota1 + nota2 + nota3) / 3;
	
	if(media >= 7){
		printf("Aluno Aprovado");
	} else{
		printf("Aluno Reprovado");
	}
	return 0;
}
