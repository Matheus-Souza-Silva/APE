#include <stdio.h>

int main() {
	float prova1, prova2, prova3, media;
	char aluno[15];
	
	prova1 = 0.823;
	prova2 = 0.645;
	prova3 = 0.952;

	media = (prova1 + prova2 + prova3) / 3;
	
	printf("Insira o nome do aluno: ");
	scanf("%s",&aluno);
	
	printf("\nAluno: %s\n==============\nMatematica: %.3f\nHistoria: %.3f\nPortugues: %.3f\nMedia: %.3f",aluno, prova1, prova2, prova3, media);
	return 0;
}
