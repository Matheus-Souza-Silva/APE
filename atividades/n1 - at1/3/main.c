#include <stdio.h>

int main() {
	float prova1, prova2, prova3;
	char aluno[20];
	
	prova1 = 0.823;
	prova2 = 0.645;
	prova3 = 0.952;
	
	printf("--------------------------------\n");
	printf("          N  O  T  A  S         \n");
	printf("--------------------------------\n");
	
	printf("Insira o nome do aluno: ");
	scanf("%s",&aluno);
	
	printf("--------------------------------\n");
	printf("Aluno: %s\nMatematica: %.3f\nHistoria: %.3f\nPortugues: %.3f\nMedia: %.3f",aluno, prova1, prova2, prova3, (prova1 + prova2 + prova3) / 3);
	return 0;
}
