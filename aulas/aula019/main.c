#include <stdio.h>
#include <string.h>
#include <ctype.h>

le_valida_opcao_menu(int n1);
int le_valida_opcao_7(int n1);
int le_valida_crudl(int n1);
char le_valida_continuar(char continuar, int cont);

int main() {
	int opcao = 0, opcao_7 = 0;
	int opcao_crudl = 0, cont = 0;
	char continuar;
	
	struct Uf{
		char nome[30];
		char sigla[2];
	};
	
	struct Cidade{
		char nome[30];
		struct Uf uf;
	};
	
	struct Marca{
		char nome[30];
	};
	
	struct Fornecedor{
		char nome[30];
		struct Cidade cidade;
	};
	
	struct Categoria{
		char nome[30];
	};
	
	struct Produto{
		char nome[30];
		float valor;
		struct Marca marca;
		struct Categoria categoria;
		struct Fornecedor fornecedor;
	};
	
	struct Uf uf[5];
	struct Cidade cidade[5];
	struct Marca marca[5];
	struct Fornecedor fornecedor[5];
	struct Categoria categoria[5];
	struct Produto produto[5];
	
	do{
		opcao = le_valida_opcao_menu(opcao);
		
		switch(opcao){
			case 1:
				system("cls");
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						cont = 0;
						do{
							system("cls");
							printf("Nome da Categoria (Maximo de 5): ");
							scanf(" %[^\n]s",&categoria[cont].nome);
							cont++;
							
							continuar = le_valida_continuar(continuar, cont);
						} while(cont < 5 && continuar == 's');
					break;
					
					case 2:
						system("cls");
						if(categoria)
						for(cont = 0; cont < 5;cont++){
							printf("%s",categoria[cont].nome);
						}
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					case 5:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 2:
				system("cls");
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						
					break;
					
					case 2:
						
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					case 5:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 3:
				system("cls");
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						
					break;
					
					case 2:
						
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					case 5:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 4:
				system("cls");
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						
					break;
					
					case 2:
						
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					case 5:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 5:
				system("cls");
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						
					break;
					
					case 2:
						
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					case 5:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 6:
				system("cls");
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						
					break;
					
					case 2:
						
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					case 5:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 7:
				system("cls");
				opcao_7 = le_valida_opcao_7(opcao_7);
				switch(opcao_7){
					case 1:
						
					break;
					
					case 2:
						
					break;
					
					case 3:
						
					break;
					
					case 4:
						
					break;
					
					default:
						system("cls");
						printf("Opcao invalida, tente novamente:\n");
						getch();
				}
			break;
			
			case 8:
				system("cls");
				printf("Programa Finalizado");
			break;
			
			default:
				system("cls");
				printf("Opcao invalida, tente novamente:\n");
				getch();
		}
	}while(opcao >= 1 && opcao < 8);
	
	return 0;
}

int le_valida_opcao_menu(int n1){
	int opcao = 0;
	
	system("cls");
	printf("(1) Manter Categoria\n(2) Manter Fornecedor\n(3) Manter Produto\n(4) Manter Marca\n(5) Manter UF\n(6) Manter Cidade\n(7) Relatorios\n(8) Sair\n");
	scanf("%d",&opcao);
	return opcao;
}

int le_valida_opcao_7(int n1){
	int opcao_7 = 0;
	
	printf("(1) Quantidade de Produtos de Determinada marca em uma cidade\n(2) Quantidade de cidades cadastradas\n(3) Quais UFs apresentam os com o maior valor\n(4) Os fornecedores de determinada cidade\n");
	scanf("%d",&opcao_7);
	
	return opcao_7;
}

int le_valida_crudl(int n1){
	int opcao_crudl = 0;
	printf("(1) Criar\n(2) Ler\n(3) Atualizar\n(4) Excluir\n(5) Listar\n");
	scanf("%d",&opcao_crudl);
	
	return opcao_crudl;
}

char le_valida_continuar(char continuar, int cont){
	int cont1 = 0;

	do{
		if(cont1 > 0 && cont < 5){
			printf("Opcao invalida, tente novamente: ");
			scanf(" %c",&continuar);
		} else if(cont < 5){
			printf("Deseja Continuar?: ");
			scanf(" %c",&continuar);
		}
		cont1++;
	}while(continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
	
	if(continuar == 's' || continuar == 'S'){
		continuar = 's';
	}
	
	return continuar;
}
