#include <stdio.h>
#define TAM 20 // Mudar o valor de acordo com a questão

int main() {
	//	1) Elabore um programa onde o usuario informara 5 notas, apos receber as notas, as mesma serao apresentadas na ordem inversa a informada
	
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
	
	//	2) Desenvolva uma soluçao onde o usario informara ate 5 notas, a cada nota informada aparecera a opçao "Deseja sair? (S/N)", caso o usuario digite N o programa continuara ate atingir o limite de 5 notas.
	
//	float notas[TAM];
//	int i = 0;
//	char sair;
//	
//	printf("--------------------------------\n");
//	printf("   A  T  E   5   N  O  T  A  S  \n");
//	printf("--------------------------------\n");
//	
//	do{
//		printf("Insira a Nota %d: ",i+1);
//		scanf("%f",&notas[i]);
//		
//		if(i < TAM - 1){
//			fflush(stdin);
//			printf("Deseja sair? (S/N): ");
//			scanf("%c",&sair);
//			
//			if(sair == 'S' || sair == 's'){
//				i++;
//				break;
//			}
//
//		}
//		
//		i++;
//	}while((sair == 'N' || sair == 'n') && i < TAM);
//	
//  	printf("--------------------------------\n");
//
//	printf("Programa Finalizado");

	//	3) Apresente um programa onde o usuário informará até 10 notas, ao final deverá ser apresentado a média das notas informadas, quantas "aprovadas" (acima de 7 (inclusive)) e quantas "reprovadas".
	
//	float notas[TAM];
//	float media, soma = 0;
//	int i = 0, j = 0, aprovado = 0, reprovado = 0;
//	char sair;
//	
//	printf("--------------------------------\n");
//	printf("    M     E     D     I     A   \n");
//	printf("--------------------------------\n");
//	
//	do{
//		printf("Insira a Nota %d: ",i+1);
//		scanf("%f",&notas[i]);
//		
//		while(notas[i] < 0 || notas[i] > 10) {
//            printf("Nota invalida! Digite uma nota entre 0 e 10: ");
//            scanf("%f", &notas[i]);
//        }
//        
//        soma += notas[i];
//		
//		if(i < TAM - 1){
//			fflush(stdin);
//			printf("Deseja sair? (S/N): ");
//			scanf("%c",&sair);
//			
//			if(sair == 'S' || sair == 's'){
//				i++;
//				break;
//			}
//		}
//		
//		i++;
//	}while((sair == 'N' || sair == 'n') && i < TAM);
//	
//	printf("--------------------------------\n");
//
//	media = soma / i;
//	
//	for(j = 0; j < i; j++){
//		if(notas[j] >= 7){
//			aprovado++;
//		} else{
//			reprovado++;
//		}
//	}
//	
//  printf("Total de notas informadas: %d\n", i);
//  printf("Media das notas: %.2f\n", media);
//  printf("Aprovados (nota >= 7): %d\n", aprovado);
//  printf("Reprovados (nota < 7): %d", reprovado);
    
	//	4) Desenvolva um programa onde o usuário informará 10 valores que serão armazenados em um vetor, posteriormente leia cada elemento do vetor ao final apresente apenas a quantidade de pares e a quantidade de ímpares.
	
//	int valores[TAM], i = 0, par = 0, impar = 0;
//
//	printf("--------------------------------\n");
//	printf("   P  A  R   E   I  M  P  A  R  \n");
//	printf("--------------------------------\n");
//	
//	for(i = 0; i < TAM; i++){
//		printf("Informe o valor %d: ",i+1);
//		scanf("%d",&valores[i]);
//	}
//	
//	for(i = 0; i < TAM; i++){
//		if(valores[i] % 2 == 0){
//			par++;
//		} else{
//			impar++;
//		}
//	}
//	
//	printf("--------------------------------\n");
//	
//	printf("Quantidade de Pares: %d\nQuantidade de Impares: %d",par, impar);
	
	//	5) Crie um programa onde o usuário informará até 20 valores e armazene em um vetor, crie outros dois vetores (par e impar), faça uma varredura no vetor original, apresente ao final:
	//	
	//	quantidade de pares: 
	//	quantidade de impares: 
	//	maior valor par:
	//	menor valor par:
	//	maior valor impar:
	//	menor valor impar:
	//	media dos pares:
	//	media dos impares:
	//	quantidade de pares acima da media dos pares:
	//	quantidade de impares abaixo da media dos impares:
	//	
	//	Ao declarar os vetores utilize o tipo int e inicialize todos os elementos com 0.
	
//	int valores[TAM], par[TAM], impar[TAM];
//	int qtd_par = 0, qtd_impar = 0, i = 0;
//	int maior_par = 0, menor_par = 0;
//	int maior_impar = 0, menor_impar = 0;
//	int soma_par = 0, soma_impar = 0;
//	float media_par, media_impar;
//	char sair;
//	
//	printf("--------------------------------\n");
//	printf("    20   V  A  L  O  R  E  S    \n");
//	printf("--------------------------------\n");
//	
//	for(i = 0; i < TAM; i++){
//		valores[i] = 0;
//		par[i] = 0;
//		impar[i] = 0;
//	}
//	
//	i = 0;
//	do{
//		printf("Insira o valor %d: ",i+1);
//		scanf("%d",&valores[i]);
//		
//		if(i < TAM - 1){
//			fflush(stdin);
//			printf("Deseja sair? (S/N): ");
//			scanf("%c",&sair);
//			
//			if(sair == 'S' || sair == 's'){
//				i++;
//				break;
//			}	
//		}
//		
//		i++;
//	}while((sair == 'N' || sair == 'n') && i < TAM);
//	
//	for(i = 0; i < TAM && valores[i] != 0; i++){
//		if(valores[i] % 2 == 0){
//			par[qtd_par] = valores[i];
//			soma_par += valores[i];
//			
//			if(qtd_par == 0){
//				maior_par = menor_par = valores[i];
//			} else{
//				if(valores[i] > maior_par){
//					maior_par = valores[i];
//				}
//				
//				if(valores[i] < menor_par){
//					menor_par = valores[i];
//				}
//			}
//			
//			qtd_par++;
//		} else{
//			impar[qtd_impar] = valores[i];
//			soma_impar += valores[i];
//			
//			if(qtd_impar == 0){
//				maior_impar = menor_impar = valores[i];
//			} else{
//				if(valores[i] > maior_impar){
//					maior_impar = valores[i];
//				}
//				
//				if(valores[i] < menor_impar){
//					menor_impar = valores[i];
//				}
//			}
//			
//			qtd_impar++;
//		}
//	}
//	
//	if(qtd_par > 0){
//		media_par = (float)soma_par / qtd_par;
//	}
//	
//	if(qtd_impar > 0){
//		media_impar = (float)soma_impar / qtd_impar;
//	}
//	
//	int acima_media_par = 0, abaixo_media_impar = 0;
//	
//	for(i = 0; i < qtd_par; i++){
//		if(par[i] > media_par){
//			acima_media_par++;
//		}
//	}
//	
//	for(i = 0; i < qtd_impar; i++){
//		if(impar[i] < media_impar){
//			abaixo_media_impar++;
//		}
//	}
//	
//	printf("--------------------------------\n");
//	
//	printf("Quantidade de pares: %d\n", qtd_par);
//	printf("Quantidade de impares: %d\n", qtd_impar);
//	
//	printf("--------------------------------\n");
//	
//	if(qtd_par > 0){
//		printf("Maior valor par: %d\n", maior_par);
//		printf("Menor valor par: %d\n", menor_par);
//		printf("Media dos pares: %.2f\n", media_par);
//		printf("Quantidade de pares acima da media dos pares: %d\n", acima_media_par);
//	} else{
//		printf("Nao ha valores pares para analise\n");
//	}
//	
//	printf("--------------------------------\n");
//	
//	if(qtd_impar > 0){
//		printf("Maior valor impar: %d\n", maior_impar);
//		printf("Menor valor impar: %d\n", menor_impar);
//		printf("Media dos impares: %.2f\n", media_impar);
//		printf("Quantidade de impares abaixo da media dos impares: %d", abaixo_media_impar);
//	} else{
//		printf("Nao ha valores impares para analise");
//	}
	
	return 0;
}
