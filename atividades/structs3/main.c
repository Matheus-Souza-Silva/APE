#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

int le_valida_opcao_menu(int n1);
int le_valida_opcao_7(int n1);
int le_valida_crudl(int n1);
char le_valida_continuar(char continuar, int cont);
int le_valida_atualizar(int opcao_crudl);
int le_valida_alternativa(int i);

int main() {
	int opcao = 0, opcao_7 = 0, qtd_cidade = 0, qtd_uf = 0, qtd_marca = 0, qtd_fornecedor = 0;
	int opcao_crudl = 0, cont = 0, i = 0;
	char continuar, espaco;
	
	struct Uf{
		char nome[30];
		char sigla[3];
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
	
	struct Uf uf[TAM] = {0};
	struct Cidade cidade[TAM] = {0};
	struct Marca marca[TAM] = {0};
	struct Fornecedor fornecedor[TAM] = {0};
	struct Categoria categoria[TAM] = {0};
	struct Produto produto[TAM] = {0};
	
	do{
		opcao = le_valida_opcao_menu(opcao);

		switch(opcao){
			case 1:
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						cont = 0;
						do{
							system("cls");
							printf("Nome da Categoria (Maximo de %d): ",TAM);
							scanf(" %[^\n]s",&categoria[cont].nome);
							
							categoria[cont].nome[0] = toupper(categoria[cont].nome[0]);
							if(strchr(categoria[cont].nome, ' ')){
								for(i = 0; i < strlen(categoria[cont].nome); i++){
									if(categoria[cont].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								categoria[cont].nome[espaco] = toupper(categoria[cont].nome[espaco]);
							}
							
							cont++;
							continuar = le_valida_continuar(continuar, cont);
							
						} while(cont < 5 && continuar == 's');
					break;
					
					case 2:
						system("cls");
						
						printf("     Nome\n");
						for(i = 0; i < TAM; i++){
							if(categoria[i].nome[0] == '\0'){
								printf("Entrada Vazia\n");
							} else{
								printf("%s\n",categoria[i].nome);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						system("cls");
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(categoria[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s\n",i + 1, categoria[i].nome);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								printf("Entre o novo Nome da Categoria (%s): ",categoria[0].nome);
								scanf(" %[^\n]s",&categoria[0].nome);
							break;
							
							case 2:
								system("cls");
								printf("Entre o novo Nome da Categoria (%s): ",categoria[1].nome);
								scanf(" %[^\n]s",&categoria[1].nome);
							break;
							
							case 3:
								system("cls");
								printf("Entre o novo Nome da Categoria (%s): ",categoria[2].nome);
								scanf(" %[^\n]s",&categoria[2].nome);
							break;
							
							case 4:
								system("cls");
								printf("Entre o novo Nome da Categoria (%s): ",categoria[3].nome);
								scanf(" %[^\n]s",&categoria[3].nome);
							break;
							
							case 5:
								system("cls");
								printf("Entre o novo Nome da Categoria (%s): ",categoria[4].nome);
								scanf(" %[^\n]s",&categoria[4].nome);
							break;
							
							case 6:
								
							break;
						}
					break;
					
					case 4:
						system("cls");
						printf("Escolha qual dado excluir\n");
						for(i = 0; i < TAM; i++){
							if(categoria[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s\n",i + 1, categoria[i].nome);
							}
						}
						printf("(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								strcpy(categoria[0].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 2:
								system("cls");
								strcpy(categoria[1].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 3:
								system("cls");
								strcpy(categoria[2].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 4:
								system("cls");
								strcpy(categoria[3].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 5:
								system("cls");
								strcpy(categoria[4].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 6:
								
							break;
						}
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
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(strlen(cidade[0].nome) == 0){
							system("cls");
							printf("Impossivel de adicionar um fornecedor sem primeiramente adicionar uma cidade.");
							getch();
						} else{
							cont = 0;
							do{
								system("cls");
								printf("Nome do Fornecedor (Maximo de %d): ",TAM);
								scanf(" %[^\n]s",&fornecedor[cont].nome);
								
								printf("\nEscolha uma das cidades\n");
								for(i = 0; i < qtd_cidade; i++){
									printf("(%d) %s | %s | %s",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(fornecedor[cont].cidade.nome, cidade[opcao_crudl].nome);
								strcpy(fornecedor[cont].cidade.uf.nome, cidade[opcao_crudl].uf.nome);
								strcpy(fornecedor[cont].cidade.uf.sigla, cidade[opcao_crudl].uf.sigla);		
								
								cont++;
								qtd_fornecedor++;
								continuar = le_valida_continuar(continuar, cont);
								
							} while(cont < 5 && continuar == 's');
						}
					break;
					
					case 2:
						system("cls");
						
						printf("  Fornecedor  |     Cidade    |       UF      |     Sigla\n");
						for(i = 0; i < TAM; i++){
							if(fornecedor[i].cidade.uf.nome[0] == '\0' ){
								printf("Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia\n");
							} else{
								printf("%s | %s | %s | %s\n",fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						system("cls");
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(fornecedor[i].cidade.uf.nome[0] == '\0' ){
								printf("(%d) Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s | %s | %s | %s\n",i + 1, fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
							}
						}
						printf("(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								printf("Entre o novo Nome do Fornecedor (%s): ",fornecedor[0].nome);
								scanf(" %[^\n]s",&fornecedor[0].nome);
								printf("\nEscolha uma das cidades\n");
								for(i = 0; i < qtd_cidade; i++){
									printf("(%d) %s | %s | %s",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(fornecedor[0].cidade.nome, cidade[opcao_crudl].nome);
								strcpy(fornecedor[0].cidade.uf.nome, cidade[opcao_crudl].uf.nome);
								strcpy(fornecedor[0].cidade.uf.sigla, cidade[opcao_crudl].uf.sigla);
							break;
							
							case 2:
								system("cls");
								printf("Entre o novo Nome do Fornecedor (%s): ",fornecedor[1].nome);
								scanf(" %[^\n]s",&fornecedor[1].nome);
								printf("\nEscolha uma das cidades\n");
								for(i = 0; i < qtd_cidade; i++){
									printf("(%d) %s | %s | %s",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
								}

								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(fornecedor[1].cidade.nome, cidade[opcao_crudl].nome);
								strcpy(fornecedor[1].cidade.uf.nome, cidade[opcao_crudl].uf.nome);
								strcpy(fornecedor[1].cidade.uf.sigla, cidade[opcao_crudl].uf.sigla);
							break;
							
							case 3:
								system("cls");
								printf("Entre o novo Nome do Fornecedor (%s): ",fornecedor[2].nome);
								scanf(" %[^\n]s",&fornecedor[2].nome);
								printf("\nEscolha uma das cidades\n");
								for(i = 0; i < qtd_cidade; i++){
									printf("(%d) %s | %s | %s",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
								}

								opcao_crudl = le_valida_alternativa(i);

								strcpy(fornecedor[2].cidade.nome, cidade[opcao_crudl].nome);
								strcpy(fornecedor[2].cidade.uf.nome, cidade[opcao_crudl].uf.nome);
								strcpy(fornecedor[2].cidade.uf.sigla, cidade[opcao_crudl].uf.sigla);
							break;
							
							case 4:
								system("cls");
								printf("Entre o novo Nome do Fornecedor (%s): ",fornecedor[3].nome);
								scanf(" %[^\n]s",&fornecedor[3].nome);
								printf("\nEscolha uma das cidades\n");
								for(i = 0; i < qtd_cidade; i++){
									printf("(%d) %s | %s | %s",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
								}

								opcao_crudl = le_valida_alternativa(i);

								strcpy(fornecedor[3].cidade.nome, cidade[opcao_crudl].nome);
								strcpy(fornecedor[3].cidade.uf.nome, cidade[opcao_crudl].uf.nome);
								strcpy(fornecedor[3].cidade.uf.sigla, cidade[opcao_crudl].uf.sigla);
							break;
							
							case 5:
								system("cls");
								printf("Entre o novo Nome do Fornecedor (%s): ",fornecedor[4].nome);
								scanf(" %[^\n]s",&fornecedor[4].nome);
								printf("\nEscolha uma das cidades\n");
								for(i = 0; i < qtd_cidade; i++){
									printf("(%d) %s | %s | %s",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
								}

								opcao_crudl = le_valida_alternativa(i);

								strcpy(fornecedor[4].cidade.nome, cidade[opcao_crudl].nome);
								strcpy(fornecedor[4].cidade.uf.nome, cidade[opcao_crudl].uf.nome);
								strcpy(fornecedor[4].cidade.uf.sigla, cidade[opcao_crudl].uf.sigla);
							break;
							
							case 6:
								
							break;
						}
					break;
					
					case 4:
						system("cls");
						printf("Escolha qual dado Excluir\n");
						for(i = 0; i < TAM; i++){
							if(fornecedor[i].cidade.uf.nome[0] != '\0' ){
								printf("(%d) %s | %s | %s | %s\n",i + 1, fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								strcpy(fornecedor[0].nome, "\0");
								strcpy(fornecedor[0].cidade.nome, "\0");
								strcpy(fornecedor[0].cidade.uf.nome, "\0");
								strcpy(fornecedor[0].cidade.uf.sigla, "\0");
								printf("Dados Excluido");
								getch();
							break;
							
							case 2:
								system("cls");
								strcpy(fornecedor[1].nome, "\0");
								strcpy(fornecedor[1].cidade.nome, "\0");
								strcpy(fornecedor[1].cidade.uf.nome, "\0");
								strcpy(fornecedor[1].cidade.uf.sigla, "\0");
								printf("Dados Excluido");
								getch();
							break;
							
							case 3:
								system("cls");
								strcpy(fornecedor[2].nome, "\0");
								strcpy(fornecedor[2].cidade.nome, "\0");
								strcpy(fornecedor[2].cidade.uf.nome, "\0");
								strcpy(fornecedor[2].cidade.uf.sigla, "\0");
								printf("Dados Excluido");
								getch();
							break;
							
							case 4:
								system("cls");
								strcpy(fornecedor[3].nome, "\0");
								strcpy(fornecedor[3].cidade.nome, "\0");
								strcpy(fornecedor[3].cidade.uf.nome, "\0");
								strcpy(fornecedor[3].cidade.uf.sigla, "\0");
								printf("Dados Excluido");
								getch();
							break;
							
							case 5:
								system("cls");
								strcpy(fornecedor[4].nome, "\0");
								strcpy(fornecedor[4].cidade.nome, "\0");
								strcpy(fornecedor[4].cidade.uf.nome, "\0");
								strcpy(fornecedor[4].cidade.uf.sigla, "\0");
								printf("Dados Excluido");
								getch();
							break;
							
							case 6:
								
							break;
						}
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
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(strlen(categoria[0].nome) == 0 && strlen(fornecedor[0].nome) == 0 && strlen(marca[0].nome) == 0){
							system("cls");
							printf("Impossivel de adicionar um produto sem primeiramente adicionar uma Categoria, Fornecedor e Marca.");
							getch();
						} else{
							cont = 0;
							do{
								system("cls");
								printf("Nome do Produto (Maximo de %d): ",TAM);
								scanf(" %[^\n]s",&produto[cont].nome);
								
								printf("Valor do Produto: ");
								scanf("%f",&produto[cont].valor);
								
								printf("\nEscolha um dos Fornecedores\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s | %s | %s\n",i + 1, fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(produto[cont].fornecedor.nome, fornecedor[opcao_crudl - 1].nome);
								strcpy(produto[cont].fornecedor.cidade.nome, fornecedor[opcao_crudl - 1].cidade.nome);
								strcpy(produto[cont].fornecedor.cidade.uf.nome, fornecedor[opcao_crudl - 1].cidade.uf.nome);
								strcpy(produto[cont].fornecedor.cidade.uf.sigla, fornecedor[opcao_crudl - 1].cidade.uf.sigla);
								
								printf("\nEscolha uma das Categorias\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s\n",i + 1, categoria[i].nome);
								}
								
								opcao_crudl = le_valida_alternativa(i);

								strcpy(produto[cont].categoria.nome, categoria[opcao_crudl - 1].nome);

								printf("\nEscolha uma das Marcas\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s\n",i + 1, marca[i].nome);
								}

								opcao_crudl = le_valida_alternativa(i);

								strcpy(produto[cont].marca.nome, marca[opcao_crudl - 1].nome);

								cont++;
								continuar = le_valida_continuar(continuar, cont);
							} while(cont < 5 && continuar == 's');
						}
					break;
					
					case 2:
						system("cls");
						printf("  Produto  |   Valor   |   Fornecedor   |     Cidade    |       UF      |     Sigla  |   Categoria   |    Marca   \n");
						for(i = 0; i < TAM; i++){
							if(produto[i].nome[0] == '\0'){
								printf("Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia \n");
							} else{
								printf("  %s  |  %.2f  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  \n", produto[i].nome, produto[i].valor, produto[i].fornecedor.nome, produto[i].fornecedor.cidade.nome, produto[i].fornecedor.cidade.uf.nome, produto[i].fornecedor.cidade.uf.sigla, produto[i].categoria.nome, produto[i].marca.nome);
							}
						}
					break;
					
					case 3:
						system("cls");
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(produto[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia \n", i + 1);
							} else{
								printf("(%d)  %s  |  %.2f  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  \n", i + 1, produto[i].nome, produto[i].valor, produto[i].fornecedor.nome, produto[i].fornecedor.cidade.nome, produto[i].fornecedor.cidade.uf.nome, produto[i].fornecedor.cidade.uf.sigla, produto[i].categoria.nome, produto[i].marca.nome);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								strcpy(categoria[0].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 2:
								system("cls");
								strcpy(categoria[1].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 3:
								system("cls");
								strcpy(categoria[2].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 4:
								system("cls");
								strcpy(categoria[3].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 5:
								system("cls");
								strcpy(categoria[4].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 6:
								
							break;
						}
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
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						cont = 0;
						do{
							system("cls");
							printf("Nome da Marca (Maximo de %d): ",TAM);
							scanf(" %[^\n]s",&marca[cont].nome);
							
							cont++;
							qtd_marca++;
							continuar = le_valida_continuar(continuar, cont);
							
						} while(cont < 5 && continuar == 's');
					break;
					
					case 2:
						system("cls");
						
						printf("     Nome\n");
						for(i = 0; i < TAM; i++){
							if(marca[i].nome[0] == '\0'){
								printf("Entrada Vazia\n",marca[i].nome);
							} else{
								printf("%s\n",marca[i].nome);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						system("cls");
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(marca[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s\n",i + 1, marca[i].nome);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								printf("Entre o novo Nome da Marca (%s): ",marca[0].nome);
								scanf(" %[^\n]s",&marca[0].nome);
							break;
							
							case 2:
								system("cls");
								printf("Entre o novo Nome da Marca (%s): ",marca[1].nome);
								scanf(" %[^\n]s",&marca[1].nome);
							break;
							
							case 3:
								system("cls");
								printf("Entre o novo Nome da Marca (%s): ",marca[2].nome);
								scanf(" %[^\n]s",&marca[2].nome);
							break;
							
							case 4:
								system("cls");
								printf("Entre o novo Nome da Marca (%s): ",marca[3].nome);
								scanf(" %[^\n]s",&marca[3].nome);
							break;
							
							case 5:
								system("cls");
								printf("Entre o novo Nome da Marca (%s): ",marca[4].nome);
								scanf(" %[^\n]s",&marca[4].nome);
							break;
							
							case 6:
								
							break;
						}
					break;
					
					case 4:
						system("cls");
						printf("Escolha qual dado Excluir\n");
						for(i = 0; i < TAM; i++){
							if(marca[i].nome[0] != '\0'){
								printf("(%d) %s\n",i + 1, marca[i].nome);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl - 1);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								strcpy(marca[0].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 2:
								system("cls");
								strcpy(marca[1].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 3:
								system("cls");
								strcpy(marca[2].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 4:
								system("cls");
								strcpy(marca[3].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 5:
								system("cls");
								strcpy(marca[4].nome, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 6:
								
							break;
						}
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
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						cont = 0;
						do{
							system("cls");
							printf("Nome da UF (Maximo de %d): ",TAM);
							scanf(" %[^\n]s",&uf[cont].nome);
							
							uf[cont].nome[0] = toupper(uf[cont].nome[0]);
							if(strchr(uf[cont].nome, ' ')){
								for(i = 0; i < strlen(uf[cont].nome); i++){
									if(uf[cont].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								uf[cont].nome[espaco] = toupper(uf[cont].nome[espaco]);
							}
							
							printf("Sigla da UF (Maximo de %d): ",TAM);
							scanf(" %s",&uf[cont].sigla);
							uf[cont].sigla[0] = toupper(uf[cont].sigla[0]);
							uf[cont].sigla[1] = toupper(uf[cont].sigla[1]);
							
							cont++;
							qtd_uf++;
							continuar = le_valida_continuar(continuar, cont);
							
						} while(cont < 5 && continuar == 's');
					break;
					
					case 2:
						system("cls");
						
						printf("     UF       |     Sigla\n");
						for(i = 0; i < TAM; i++){
							if(uf[i].sigla[0] == '\0'){
								printf("Entrada Vazia | Entrada Vazia\n");
							} else{
								printf("%s | %s\n",uf[i].nome, uf[i].sigla);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						system("cls");
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(uf[i].sigla[0] == '\0'){
								printf("(%d) Entrada Vazia | Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								printf("Entre o novo Nome da UF (%s): ",uf[0].nome);
								scanf(" %[^\n]s",&uf[0].nome);
								printf("Entre a nova sigla da UF: ");
								scanf(" %[^\n]s",&uf[0].sigla);
							break;
							
							case 2:
								system("cls");
								printf("Entre o novo Nome da UF (%s): ",uf[1].nome);
								scanf(" %[^\n]s",&uf[1].nome);
								printf("Entre a nova sigla da UF: ");
								scanf(" %[^\n]s",&uf[1].sigla);
							break;
							
							case 3:
								system("cls");
								printf("Entre o novo Nome da UF (%s): ",uf[2].nome);
								scanf(" %[^\n]s",&uf[2].nome);
								printf("Entre a nova sigla da UF: ");
								scanf(" %[^\n]s",&uf[2].sigla);
							break;
							
							case 4:
								system("cls");
								printf("Entre o novo Nome da UF (%s): ",uf[3].nome);
								scanf(" %[^\n]s",&uf[3].nome);
								printf("Entre a nova sigla da UF: ");
								scanf(" %[^\n]s",&uf[3].sigla);
							break;
							
							case 5:
								system("cls");
								printf("Entre o novo Nome da UF (%s): ",uf[4].nome);
								scanf(" %[^\n]s",&uf[4].nome);
								printf("Entre a nova sigla da UF: ");
								scanf(" %[^\n]s",&uf[4].sigla);
							break;
							
							case 6:
								
							break;
						}
					break;
					
					case 4:
						system("cls");
						printf("Escolha qual dado Excluir\n");
						for(i = 0; i < TAM; i++){
							if(uf[i].sigla[0] != '\0'){
								printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								strcpy(uf[0].nome, "\0");
								strcpy(uf[0].sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 2:
								system("cls");
								strcpy(uf[0].nome, "\0");
								strcpy(uf[0].sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 3:
								system("cls");
								strcpy(uf[0].nome, "\0");
								strcpy(uf[0].sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 4:
								system("cls");
								strcpy(uf[0].nome, "\0");
								strcpy(uf[0].sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 5:
								system("cls");
								strcpy(uf[0].nome, "\0");
								strcpy(uf[0].sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 6:
								
							break;
						}
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
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(strlen(uf[0].nome) == 0){
							system("cls");
							printf("Impossivel de adicionar uma cidade sem primeiramente adicionar uma UF (Unidade Federativa).");
							getch();
						} else{
							cont = 0;
							do{
								system("cls");
								printf("Nome da Cidade (Maximo de %d): ",TAM);
								scanf(" %[^\n]s",&cidade[cont].nome);
								
								cidade[cont].nome[0] = toupper(cidade[cont].nome[0]);
								if(strchr(cidade[cont].nome, ' ')){
									for(i = 0; i < strlen(cidade[cont].nome); i++){
										if(cidade[cont].nome[i] == ' '){
											espaco = i + 1;
										}
									}
									cidade[cont].nome[espaco] = toupper(cidade[cont].nome[espaco]);
								}

								printf("\nEscolha uma das Unidades Federativas (UF)\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(cidade[cont].uf.nome, uf[opcao_crudl - 1].nome);
								strcpy(cidade[cont].uf.sigla, uf[opcao_crudl - 1].sigla);
								
								cont++;
								qtd_cidade++;
								continuar = le_valida_continuar(continuar, cont);
							} while(cont < 5 && continuar == 's');
						}
					break;
					
					case 2:
						system("cls");
						
						printf("    Cidade    |       UF      |     Sigla\n");
						for(i = 0; i < TAM; i++){
							if(cidade[i].nome[0] == '\0'){
								printf("Entrada Vazia | Entrada Vazia | Entrada Vazia\n");
							} else{
								printf("%s | %s | %s\n",cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						system("cls");
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(cidade[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia | Entrada Vazia | Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s | %s | %s\n",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								printf("Entre o novo Nome da Cidade (%s): ",cidade[0].nome);
								scanf(" %[^\n]s",&cidade[0].nome);
								
								printf("\nEscolha uma das Unidades Federativas (UF)\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(cidade[0].uf.nome, uf[opcao_crudl - 1].nome);
								strcpy(cidade[0].uf.sigla, uf[opcao_crudl - 1].sigla);
							break;
							
							case 2:
								system("cls");
								printf("Entre o novo Nome da Cidade (%s): ",cidade[1].nome);
								scanf(" %[^\n]s",&cidade[1].nome);
								
								printf("\nEscolha uma das Unidades Federativas (UF)\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(cidade[1].uf.nome, uf[opcao_crudl - 1].nome);
								strcpy(cidade[1].uf.sigla, uf[opcao_crudl - 1].sigla);
							break;
							
							case 3:
								system("cls");
								printf("Entre o novo Nome da Cidade (%s): ",cidade[2].nome);
								scanf(" %[^\n]s",&cidade[2].nome);
								
								printf("\nEscolha uma das Unidades Federativas (UF)\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(cidade[2].uf.nome, uf[opcao_crudl - 1].nome);
								strcpy(cidade[2].uf.sigla, uf[opcao_crudl - 1].sigla);
							break;
							
							case 4:
								system("cls");
								printf("Entre o novo Nome da Cidade (%s): ",cidade[3].nome);
								scanf(" %[^\n]s",&cidade[3].nome);
								
								printf("\nEscolha uma das Unidades Federativas (UF)\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
								}
								
								opcao_crudl = le_valida_alternativa(i);
								
								strcpy(cidade[3].uf.nome, uf[opcao_crudl - 1].nome);
								strcpy(cidade[3].uf.sigla, uf[opcao_crudl - 1].sigla);
							break;
							
							case 5:
								system("cls");
								printf("Entre o novo Nome da Cidade (%s): ",cidade[4].nome);
								scanf(" %[^\n]s",&cidade[4].nome);
								
								printf("\nEscolha uma das Unidades Federativas (UF)\n");
								for(i = 0; i < qtd_uf; i++){
									printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
								}

								opcao_crudl = le_valida_alternativa(i);

								strcpy(cidade[4].uf.nome, uf[opcao_crudl - 1].nome);
								strcpy(cidade[4].uf.sigla, uf[opcao_crudl - 1].sigla);
							break;
							
							case 6:
								
							break;
						}
					break;
					
					case 4:
						system("cls");
						printf("Escolha qual dado Excluir\n");
						for(i = 0; i < TAM; i++){
							if(cidade[i].nome[0] != '\0'){
								printf("(%d) %s | %s | %s\n",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						switch(opcao_crudl){
							case 1:
								system("cls");
								strcpy(cidade[0].nome, "\0");
								strcpy(cidade[0].uf.nome, "\0");
								strcpy(cidade[0].uf.sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 2:
								system("cls");
								strcpy(cidade[1].nome, "\0");
								strcpy(cidade[1].uf.nome, "\0");
								strcpy(cidade[1].uf.sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 3:
								system("cls");
								strcpy(cidade[2].nome, "\0");
								strcpy(cidade[2].uf.nome, "\0");
								strcpy(cidade[2].uf.sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 4:
								system("cls");
								strcpy(cidade[3].nome, "\0");
								strcpy(cidade[3].uf.nome, "\0");
								strcpy(cidade[3].uf.sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 5:
								system("cls");
								strcpy(cidade[4].nome, "\0");
								strcpy(cidade[4].uf.nome, "\0");
								strcpy(cidade[4].uf.sigla, "\0");
								printf("Dado Excluido");
								getch();
							break;
							
							case 6:
								
							break;
						}
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
					
					case 5:
						
					break;
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
	int opcao = 0, cont = 0;
	system("cls");
	
	do{
		if(cont > 0){
			system("cls");
			printf("Numero Invalido, tente novamente: \n");
		}
		printf("(1) Manter Categoria\n(2) Manter Fornecedor\n(3) Manter Produto\n(4) Manter Marca\n(5) Manter UF\n(6) Manter Cidade\n(7) Relatorios\n(8) Sair\nEntrada: ");
		scanf("%d",&opcao);
		cont++;
	} while(!(opcao >= 1 && opcao <= 8));
	return opcao;
}

int le_valida_opcao_7(int n1){
	int opcao_7 = 0, cont = 0;
	
	do{
		if(cont > 0){
			system("cls");
			printf("Numero Invalido, tente novamente: \n");
		}
		printf("(1) Quantidade de Produtos de Determinada marca em uma cidade\n(2) Quantidade de cidades cadastradas\n(3) Quais UFs apresentam os com o maior valor\n(4) Os fornecedores de determinada cidade\n(5) SAIR\nEntrada: ");
		scanf("%d",&opcao_7);
		cont++;
	}while(!(opcao_7 >= 1 && opcao_7 <= TAM));
	return opcao_7;
}

int le_valida_crudl(int n1){
	int opcao_crudl = 0, cont = 0;
	system("cls");
	
	do{
		if(cont > 0){
			system("cls");
			printf("Numero Invalido, tente novamente: \n");
		}
		printf("(1) Criar\n(2) Ler\n(3) Atualizar\n(4) Excluir\n(5) Listar\nEntrada: ");
		scanf("%d",&opcao_crudl);
		cont++;
	} while(!(opcao_crudl >= 1 && opcao_crudl <= TAM));
	return opcao_crudl;
}

char le_valida_continuar(char continuar, int cont){
	int cont1 = 0;

	do{
		if(cont1 > 0 && cont < 5){
			printf("\nOpcao invalida, tente novamente: \n");
			scanf(" %c",&continuar);
		} else if(cont < 5){
			printf("\nDeseja Continuar?: ");
			scanf(" %c",&continuar);
		}
		cont1++;
	}while(continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
	
	if(continuar == 's' || continuar == 'S'){
		continuar = 's';
	}
	return continuar;
}

int le_valida_atualizar(int opcao_crudl){
	int cont = 0;
	
	do{
		if(cont > 0){
			printf("Entrada Invalida, tente novamente\n");
		}
		printf("Entrada: ");
		scanf("%d",&opcao_crudl);
		cont++;
	}while(!(opcao_crudl >= 1 && opcao_crudl <= TAM + 1));
	return opcao_crudl;
}

int le_valida_alternativa(int i){
	int cont = 0;
	int j = 0;
	do{
		if(cont > 0){
			printf("Entrada Invalida, tente novamente");
		}
		printf("Entrada: ");
		scanf("%d",&j);
		cont++;
	}while(!(j >= 1 && j <= i));
	return j;
}
