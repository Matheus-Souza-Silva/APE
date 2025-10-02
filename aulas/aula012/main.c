#include <stdio.h>
#define TAM 8

int main() {
	float notas[TAM];
	float media;
	int i = 0;
	
	printf("--------------------------------\n");
	printf("    M     E     D     I     A   \n");
	printf("--------------------------------\n");
	
	for(i = 0; i < TAM; i++){
		printf("Informe o valor da Nota %d: ",i+1);
		scanf("%f",&notas[i]);
	}
	
	printf("--------------------------------\n");
	
	for(i = 0; i < TAM; i++){
		printf("Nota %d: %.2f\n",i+1,notas[i]);
		media += notas[i] / TAM;
	}
	
	printf("--------------------------------\n");
	
	printf("Media das Notas: %.2f",media);
	return 0;
}

//	notas[0] = 7.54;
//	notas[1] = 2.64;
//	notas[2] = 8.46;
//	notas[3] = 3.58;
//	notas[4] = 6.23;
	
//	printf("Informe o valor para a nota 5: ");
//	scanf("%f",&notas[4]);
	
//	printf("Nota 1: %.2f\n",notas[0]);
//	printf("Nota 2: %.2f\n",notas[1]);
//	printf("Nota 3: %.2f\n",notas[2]);
//	printf("Nota 4: %.2f\n",notas[3]);
//	printf("Nota 5: %.2f\n",notas[4]);

// --------------------------------------------

//#include <stdio.h>
//
//int main() {
//	float n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, media;
//	
//	printf("--------------------------------\n");
//	printf("    M     E     D     I     A   \n");
//	printf("--------------------------------\n");
//	
//	printf("Entre a nota N1: ");
//	scanf("%f",&n1);
//	
//	printf("Entre a nota N2: ");
//	scanf("%f",&n2);
//	
//	printf("Entre a nota N3: ");
//	scanf("%f",&n3);
//	
//	printf("Entre a nota N4: ");
//	scanf("%f",&n4);
//	
//	printf("Entre a nota N5: ");
//	scanf("%f",&n5);
//	
//	printf("Entre a nota N6: ");
//	scanf("%f",&n6);
//	
//	printf("Entre a nota N7: ");
//	scanf("%f",&n7);
//	
//	printf("Entre a nota N8: ");
//	scanf("%f",&n8);
//	
//	printf("Entre a nota N9: ");
//	scanf("%f",&n9);
//	
//	printf("Entre a nota N10: ");
//	scanf("%f",&n10);
//	
//	media = (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10) / 10;
//	
//	printf("--------------------------------\n");
//	printf("A media das notas e %.2f",media);
//	return 0;
//}
