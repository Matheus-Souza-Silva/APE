#include <stdio.h>

int le_valida_idade();
char le_valida_continuar();
void cabecalho();

int main() {
	char nome[20];
	int idade = 0;
	char continuar;
		
	do{
		cabecalho();
		
		fflush(stdin);
		printf("Informe o Nome: ");
		scanf("%[^\n]s",&nome);
		
		idade = le_valida_idade();
		
		printf("--------------------------------\n");		
		printf("Nome: %s | Idade: %d\n",nome,idade);
		printf("--------------------------------\n");
		
		continuar = le_valida_continuar();
	}while(continuar == 's');
	
	printf("--------------------------------\n");
	printf("Programa Finalizado");
	
	return 0;
}

int le_valida_idade(){
	int cont = 0;
	int idade = 0;
	int result = 0;
	
	do{
		if(cont == 0){
			printf("Informe a Idade: ");
			scanf("%d",&idade);
		} else{
			cabecalho();
			printf("Idade Invalida, necessario estar entre 1 e 130\n");
			
			printf("Informe novamente a idade: ");
			scanf("%d",&idade);
		}
		
		cont++;
	}while(idade <= 1 || idade > 130);
	
	result = idade;
	return result;
}

char le_valida_continuar(){
	char continuar;
	int cont = 0;
	
	do{
		if(cont == 0){
			printf("Deseja Continuar? (s/n): ");
			scanf(" %c",&continuar);
		} else{
			printf("Entrada Invalida, tente novamente: ");
			scanf(" %c",&continuar);
		}
		cont++;
	}while((continuar != 's' && continuar != 'S') && (continuar != 'n' && continuar != 'N'));
	
	if(continuar == 's' || continuar == 'S'){
		continuar = 's';
	}
	return continuar;
}

// Procedimento
void cabecalho(){
	system("cls");
	printf("--------------------------------\n");
	printf("     C  A  D  A  S  T  R  O     \n");
	printf("--------------------------------\n");
}

/*
 Funções
	Tem retorno
	
 Procedimento
	Não tem retorno
	
	Exemplo:
		void cabecalho(){
			printf("-----------\n");
			printf("  CADASTRO \n");
			printf("-----------\n");
		}	
*/
