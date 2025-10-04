#include <stdio.h>
#define TAM 10

int main() {
	float notas[TAM];
	float media;
	char sair;
	int i = 0;
	
	printf("--------------------------------\n");
	printf("    M     E     D     I     A   \n");
	printf("--------------------------------\n");

	for(i = 0; i < TAM; i++){
		printf("Insira a Nota %d: ",i+1);
		scanf("%f",&notas[i]);
		media += notas[i] / TAM;
		
		fflush(stdin);
		printf("Deseja sair? (S/N): ");
		scanf("%c",&sair);
		
		if(sair == 'S'){
			printf("Programa Finalizado");
			return 1;
		}
	}
	
	printf("--------------------------------\n");
	
	printf("Media da Turma: %.2f\n",media);
	
	printf("--------------------------------\n");
	
	for(i = 0; i < TAM; i++){
		if(notas[i] >= 7){
			printf("Aluno %d | Aprovado\n",i+1);
		} else{
			printf("Aluno %d | Reprovado\n",i+1);
		}
	}
	return 0;
}



/* Desenvolva uma solução onde o usuário informará até 5 notas, a cada nota informada aparecerá a opção 
"Deseja Sair? (S/N), caso o usuário digite N o programa continuará até atingir o limite de 5 notas.*/

//#include <stdio.h>
//#define TAM 5
//
//int main() {
//	float notas[TAM];
//	int i = 0;
//	char sair;
//	
//	do{
//		printf("Insira a Nota %d: ",i+1);
//		scanf("%f",&notas[i]);
//		
//		if(i != TAM - 1){
//			fflush(stdin);
//			printf("Deseja sair? (S/N): ");
//			scanf("%c",&sair);
//		}
//		
//		i++;
//	}while(sair == 'N' && i < TAM);
//	
//  printf("--------------------------------\n");
//
//	printf("Programa Finalizado");
//	
//	for(i = 0; i < TAM; i++){
//		printf("Insira a Nota %d: ",i+1);
//		scanf("%f",&notas[i]);
//		
//		fflush(stdin);
//		printf("Deseja sair? (S/N): ");
//		scanf("%c",&sair);
//		
//		if(sair == 'S'){
//			printf("Programa Finalizado");
//			return 1;
//		}
//	}
//
//	return 0;
//}


/* Elabore um programa onde o usuário informará 5 notas, após receber 
as notas, as mesmas serão apresentadas na ordem inversa à informada! */

//#include <stdio.h>
//#define TAM 5
//
//int main() {
//	float notas[TAM];
//	int i = 0;
//	
//	printf("--------------------------------\n");
//	printf("    N     O     T     A     S   \n");
//	printf("--------------------------------\n");
//	
//	for(i = 0; i < TAM; i++){
//		printf("Informe a Nota %d: ",i+1);
//		scanf("%f",&notas[i]);
//	}
//	
//	printf("--------------------------------\n");
//	
//	for(i = TAM - 1; i >= 0; i--){
//		printf("Nota %d: %.2f\n", i+1, notas[i]);
//	}
//	return 0;
//}

/* O Vetor e uma Estrutura de Dados Composta Homogênea */
