#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5
#define STR 30

int le_valida_opcao_menu(int n1);
int le_valida_opcao_7(int n1);
int le_valida_crudl(int n1);
char le_valida_continuar(char continuar, int cont);
int le_valida_atualizar(int opcao_crudl);
int le_valida_alternativa(int i);
int le_valida_sort();
void bubbleSortAZ(char arr[][STR], int n);
void bubbleSortZA(char arr[][STR], int n);
void cabecalho();

int main() {
	int qtd_cidade = 0, qtd_uf = 0, qtd_marca = 0, qtd_fornecedor = 0, qtd_produto = 0, qtd_categoria = 0;
	int opcao_crudl = 0, opcao = 0, opcao_7 = 0, cont = 0, i = 0, j = 0, sort = 0;
	float maior_valor;
	char continuar, espaco, uf_valor;
	char uf_nome[TAM][STR] = {0}, cidade_nome[TAM][STR] = {0}, marca_nome[TAM][STR] = {0}, fornecedor_nome[TAM][STR] = {0}, categoria_nome[TAM][STR] = {0}, produto_nome[TAM][STR] = {0};
	
	struct Uf{
		char nome[STR];
		char sigla[3];
	};
	
	struct Cidade{
		char nome[STR];
		struct Uf uf;
	};
	
	struct Marca{
		char nome[STR];
	};
	
	struct Fornecedor{
		char nome[STR];
		struct Cidade cidade;
	};
	
	struct Categoria{
		char nome[STR];
	};
	
	struct Produto{
		char nome[STR];
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
						if(qtd_categoria == TAM){
							cabecalho();
							printf("Quantidade maxima de categorias atingida\n");
							printf("\nPressione qualquer botao para sair");
							getch();
						} else{
							cont = 0;
							j = 0;
							do{
								if(categoria[cont].nome[0] == '\0'){
									cabecalho();
									printf("| Limite de 5 Categorias\n\nNome da Categoria: ",TAM);
									scanf(" %[^\n]s",&categoria[cont].nome);
									
									categoria[cont].nome[0] = toupper(categoria[cont].nome[0]);
									if(strchr(categoria[cont].nome, ' ')){
										for(i = 0; i < strlen(categoria[cont].nome); i++){
											categoria[cont].nome[i] = tolower(categoria[cont].nome[i]);
											if(categoria[cont].nome[i] == ' '){
												espaco = i + 1;
											}
										}
										categoria[cont].nome[espaco] = toupper(categoria[cont].nome[espaco]);
									}
									strcpy(categoria_nome[cont], categoria[cont].nome);
									
									cont++;
									qtd_categoria++;
									for(i = 0; i < TAM; i++){
										if(categoria[i].nome[0] == '\0'){
											j++;
										}
									}
									
									if(j != 0){
										continuar = le_valida_continuar(continuar, cont);
									}
								} else{
									cont++;
								}
							} while(cont < TAM && continuar == 's');
						}
					break;
					
					case 2:
						cabecalho();
						
						printf("      Nome\n");
						for(i = 0; i < TAM; i++){
							if(categoria[i].nome[0] == '\0'){
								printf("| Entrada Vazia\n");
							} else{
								printf("| %s\n",categoria[i].nome);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						cabecalho();
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
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							if(categoria[opcao_crudl - 1].nome[0] == '\0'){
								qtd_categoria++;
							}
							printf("Entre o novo Nome da Categoria (%s): ",categoria[opcao_crudl - 1].nome);
							scanf(" %[^\n]s",&categoria[opcao_crudl - 1].nome);
							
							categoria[opcao_crudl - 1].nome[0] = toupper(categoria[opcao_crudl - 1].nome[0]);
							if(strchr(categoria[opcao_crudl - 1].nome, ' ')){
								for(i = 0; i < strlen(categoria[opcao_crudl - 1].nome); i++){
									if(categoria[opcao_crudl - 1].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								categoria[opcao_crudl - 1].nome[espaco] = toupper(categoria[opcao_crudl - 1].nome[espaco]);
							}
							strcpy(categoria_nome[opcao_crudl - 1], categoria[opcao_crudl - 1].nome);
						}
					break;
					
					case 4:
						cabecalho();
						printf("Escolha qual dado excluir\n");
						j = 0;
						for(i = 0; i < TAM; i++){
							if(categoria[i].nome[0] != '\0'){
								j++;
								printf("(%d) %s\n", j, categoria[i].nome);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							strcpy(categoria[opcao_crudl - 1].nome, "\0");
							strcpy(categoria_nome[opcao_crudl - 1], "\0");
							printf("Dado Excluido");
							qtd_categoria--;
							getch();
						}
					break;
					
					case 5:
						cabecalho();
						if(qtd_categoria == 0){
							printf("Nao a nenhuma Categoria adicionada para listar, adicione uma Categoria primeiro.");
							getch();
						} else{
							sort = le_valida_sort();
							cabecalho();
							
							if(sort == 1){
								printf("Lista de A a Z dos nomes das categorias:\n");
								
								bubbleSortAZ(categoria_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(categoria_nome[i][0] != '\0'){
										printf("| %s\n",categoria_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							} else{
								printf("Lista de Z a A dos nomes das categorias:\n");
								
								bubbleSortZA(categoria_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(categoria_nome[i][0] != '\0'){
										printf("| %s\n",categoria_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							}
						}		
					break;
					
					case 6:
						
					break;
				}
			break;
			
			case 2:
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(strlen(cidade[0].nome) == 0){
							cabecalho();
							printf("Impossivel de adicionar um fornecedor sem primeiramente adicionar uma cidade.");
							getch();
						} else if(qtd_fornecedor == TAM){
							cabecalho();
							printf("Quantidade maxima de Fornecedores atingida\n");
							printf("\nPressione qualquer botao para sair");
							getch();
						} else{
							cont = 0;
							do{
								if(fornecedor[cont].cidade.uf.nome[0] == '\0'){
									cabecalho();
									printf("| Limite de 5 Fornecedores\n\nNome do Fornecedor: ",TAM);
									scanf(" %[^\n]s",&fornecedor[cont].nome);
									
									fornecedor[cont].nome[0] = toupper(fornecedor[cont].nome[0]);
									if(strchr(fornecedor[cont].nome, ' ')){
										for(i = 0; i < strlen(fornecedor[cont].nome); i++){
											if(fornecedor[cont].nome[i] == ' '){
												espaco = i + 1;
											}
										}
										fornecedor[cont].nome[espaco] = toupper(fornecedor[cont].nome[espaco]);
									}
									strcpy(fornecedor_nome[cont], fornecedor[cont].nome);
									
									printf("\nEscolha uma das cidades\n");
									for(i = 0; i < qtd_cidade; i++){
										printf("(%d) %s | %s | %s\n",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
									}
									
									opcao_crudl = le_valida_alternativa(i);
									
									strcpy(fornecedor[cont].cidade.nome, cidade[opcao_crudl - 1].nome);
									strcpy(fornecedor[cont].cidade.uf.nome, cidade[opcao_crudl - 1].uf.nome);
									strcpy(fornecedor[cont].cidade.uf.sigla, cidade[opcao_crudl - 1].uf.sigla);		
									
									cont++;
									qtd_fornecedor++;
									for(i = 0; i < TAM; i++){
										if(fornecedor[i].cidade.uf.nome[0] == '\0'){
											j++;
										}
									}
									
									if(j != 0){
										continuar = le_valida_continuar(continuar, cont);
									}
								} else{
									cont++;
								}	
							} while(cont < TAM && continuar == 's');
						}
					break;
					
					case 2:
						cabecalho();
						
						printf("    Fornecedor  |     Cidade    |       UF      |     Sigla\n");
						for(i = 0; i < TAM; i++){
							if(fornecedor[i].cidade.uf.nome[0] == '\0' ){
								printf("| Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia\n");
							} else{
								printf("| %s | %s | %s | %s\n",fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						cabecalho();
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(fornecedor[i].cidade.uf.nome[0] == '\0' ){
								printf("(%d) Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s | %s | %s | %s\n",i + 1, fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							if(fornecedor[opcao_crudl - 1].nome[0] == '\0'){
								qtd_fornecedor++;
							}
							printf("Entre o novo Nome do Fornecedor (%s): ",fornecedor[opcao_crudl - 1].nome);
							scanf(" %[^\n]s",&fornecedor[opcao_crudl - 1].nome);
							
							fornecedor[opcao_crudl - 1].nome[0] = toupper(fornecedor[opcao_crudl - 1].nome[0]);
							if(strchr(fornecedor[opcao_crudl - 1].nome, ' ')){
								for(i = 0; i < strlen(fornecedor[opcao_crudl - 1].nome); i++){
									if(fornecedor[opcao_crudl - 1].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								fornecedor[opcao_crudl - 1].nome[espaco] = toupper(fornecedor[opcao_crudl - 1].nome[espaco]);
							}
							strcpy(fornecedor_nome[opcao_crudl - 1], fornecedor[opcao_crudl - 1].nome);
							cont = opcao_crudl - 1;
							
							printf("\nEscolha uma das cidades\n");
							for(i = 0; i < qtd_cidade; i++){
								printf("(%d) %s | %s | %s\n",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
							
							opcao_crudl = le_valida_alternativa(i);
							
							strcpy(fornecedor[cont].cidade.nome, cidade[opcao_crudl - 1].nome);
							strcpy(fornecedor[cont].cidade.uf.nome, cidade[opcao_crudl - 1].uf.nome);
							strcpy(fornecedor[cont].cidade.uf.sigla, cidade[opcao_crudl - 1].uf.sigla);
						}
					break;
					
					case 4:
						cabecalho();
						printf("Escolha qual dado Excluir\n");
						j = 0;
						for(i = 0; i < TAM; i++){
							if(fornecedor[i].cidade.uf.nome[0] != '\0' ){
								j++;
								printf("(%d) %s | %s | %s | %s\n", j, fornecedor[i].nome, fornecedor[i].cidade.nome, fornecedor[i].cidade.uf.nome, fornecedor[i].cidade.uf.sigla);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							strcpy(fornecedor[opcao_crudl - 1].nome, "\0");
							strcpy(fornecedor[opcao_crudl - 1].cidade.nome, "\0");
							strcpy(fornecedor[opcao_crudl - 1].cidade.uf.nome, "\0");
							strcpy(fornecedor[opcao_crudl - 1].cidade.uf.sigla, "\0");
							strcpy(fornecedor_nome[opcao_crudl - 1], "\0");
							printf("Dados Excluidos");
							qtd_fornecedor--;
							getch();
						}
					break;
					
					case 5:
						cabecalho();
						if(qtd_fornecedor == 0){
							printf("Nao a nenhum Fornecedor adicionado para listar, adicione um Fornecedor primeiro.");
							getch();
						} else{
							sort = le_valida_sort();
							cabecalho();
							
							if(sort == 1){
								printf("Lista de A a Z dos nomes dos Fornecedores:\n");
								
								bubbleSortAZ(fornecedor_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(fornecedor_nome[i][0] != '\0'){
										printf("| %s\n",fornecedor_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							} else{
								printf("Lista de Z a A dos nomes dos Fornecedores:\n");
								
								bubbleSortZA(fornecedor_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(fornecedor_nome[i][0] != '\0'){
										printf("| %s\n",fornecedor_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							}
						}
					break;
					
					case 6:
						
					break;
				}
			break;
			
			case 3:
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(strlen(categoria[0].nome) == 0 && strlen(fornecedor[0].nome) == 0 && strlen(marca[0].nome) == 0){
							cabecalho();
							printf("Impossivel de adicionar um Produto sem primeiramente adicionar uma Categoria, Fornecedor e Marca.");
							getch();
						} else if(qtd_produto == TAM){
							cabecalho();
							printf("Quantidade maxima de Produtos atingida\n");
							printf("\nPressione qualquer botao para sair");
							getch();
						} else{
							cont = 0;
							do{
								if(produto[cont].nome[0] == '\0'){
									cabecalho();
									printf("| Limite de 5 Produtos\n\nNome do Produto: ",TAM);
									scanf(" %[^\n]s",&produto[cont].nome);
									
									produto[cont].nome[0] = toupper(produto[cont].nome[0]);
									if(strchr(produto[cont].nome, ' ')){
										for(i = 0; i < strlen(produto[cont].nome); i++){
											if(produto[cont].nome[i] == ' '){
												espaco = i + 1;
											}
										}
										produto[cont].nome[espaco] = toupper(produto[cont].nome[espaco]);
									}
									strcpy(produto_nome[cont], produto[cont].nome);
									
									printf("Valor do Produto: ");
									scanf("%f",&produto[cont].valor);
									
									if(produto[cont].valor > maior_valor){
										strcpy(uf_valor, produto[cont].fornecedor.cidade.uf.nome);
									}
	
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
									qtd_produto++;
									for(i = 0; i < TAM; i++){
										if(produto[i].nome[0] == '\0'){
											j++;
										}
									}
									
									if(j != 0){
										continuar = le_valida_continuar(continuar, cont);
									}
								} else{
									cont++;
								}
							} while(cont < TAM && continuar == 's');
						}
					break;
					
					case 2:
						cabecalho();
						printf("    Produto  |   Valor   |   Fornecedor   |     Cidade    |       UF      |     Sigla  |   Categoria   |    Marca   \n");
						for(i = 0; i < TAM; i++){
							if(produto[i].nome[0] == '\0'){
								printf("| Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia | Entrada Vazia \n");
							} else{
								printf("| %s  |  %.2f  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  \n", produto[i].nome, produto[i].valor, produto[i].fornecedor.nome, produto[i].fornecedor.cidade.nome, produto[i].fornecedor.cidade.uf.nome, produto[i].fornecedor.cidade.uf.sigla, produto[i].categoria.nome, produto[i].marca.nome);
							}
						}
					break;
					
					case 3:
						cabecalho();
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
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							if(produto[opcao_crudl - 1].nome[0] == '\0'){
								qtd_produto++;
							}
							printf("Novo nome do Produto (%s): ",produto[opcao_crudl - 1].nome);
							scanf(" %[^\n]s",&produto[opcao_crudl - 1].nome);
							
							produto[opcao_crudl - 1].nome[0] = toupper(produto[opcao_crudl - 1].nome[0]);
							if(strchr(produto[opcao_crudl - 1].nome, ' ')){
								for(i = 0; i < strlen(produto[opcao_crudl - 1].nome); i++){
									if(produto[opcao_crudl - 1].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								produto[opcao_crudl - 1].nome[espaco] = toupper(produto[opcao_crudl - 1].nome[espaco]);
							}
							strcpy(produto_nome[opcao_crudl - 1], produto[opcao_crudl - 1].nome);
							
							printf("Novo valor do Produto (%s): ",produto[opcao_crudl - 1].nome);
							scanf("%f",&produto[opcao_crudl - 1].valor);
							cont = opcao_crudl - 1;
							
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
						}
					break;
					
					case 4:
						cabecalho();
						printf("Escolha qual dado Excluir\n");
						j = 0;
						for(i = 0; i < TAM; i++){
							if(produto[i].nome[0] != '\0'){
								j++;
								printf("(%d)  %s  |  %.2f  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  \n", j, produto[i].nome, produto[i].valor, produto[i].fornecedor.nome, produto[i].fornecedor.cidade.nome, produto[i].fornecedor.cidade.uf.nome, produto[i].fornecedor.cidade.uf.sigla, produto[i].categoria.nome, produto[i].marca.nome);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							strcpy(produto[opcao_crudl - 1].nome, "\0");
							produto[opcao_crudl - 1].valor = 0;
							strcpy(produto[opcao_crudl - 1].fornecedor.nome, "\0");
							strcpy(produto[opcao_crudl - 1].fornecedor.cidade.nome, "\0");
							strcpy(produto[opcao_crudl - 1].fornecedor.cidade.uf.nome, "\0");
							strcpy(produto[opcao_crudl - 1].fornecedor.cidade.uf.sigla, "\0");
							strcpy(produto[opcao_crudl - 1].categoria.nome, "\0");
							strcpy(produto[opcao_crudl - 1].marca.nome, "\0");
							strcpy(produto_nome[opcao_crudl - 1], "\0");
							printf("Dados Excluidos");
							qtd_produto--;
							getch();
						}
					break;
					
					case 5:
						cabecalho();
						if(qtd_produto == 0){
							printf("Nao a nenhum Produto adicionado para listar, adicione um Produto primeiro.");
							getch();
						} else{
							sort = le_valida_sort();
							cabecalho();
							
							if(sort == 1){
								printf("Lista de A a Z dos nomes dos Produtos:\n");
								
								bubbleSortAZ(produto_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(produto_nome[i][0] != '\0'){
										printf("| %s\n",produto_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							} else{
								printf("Lista de Z a A dos nomes dos Produtos:\n");
								
								bubbleSortZA(produto_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(produto_nome[i][0] != '\0'){
										printf("| %s\n",produto_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							}
						}
					break;
					
					case 6:
						
					break;
				}
			break;
			
			case 4:
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(qtd_marca == TAM){
							cabecalho();
							printf("Quantidade maxima de Marcas atingida\n");
							printf("\nPressione qualquer botao para sair");
							getch();
						} else{
							cont = 0;
							do{
								if(marca[cont].nome[0] == '\0'){
									cabecalho();
									printf("| Limite de 5 Marcas\n\nNome da Marca: ",TAM);
									scanf(" %[^\n]s",&marca[cont].nome);
									
									marca[cont].nome[0] = toupper(marca[cont].nome[0]);
									if(strchr(marca[cont].nome, ' ')){
										for(i = 0; strlen(marca[cont].nome); i++){
											if(marca[cont].nome[i] == ' '){
												espaco = i + 1;
											}
										}
										marca[cont].nome[espaco] = toupper(marca[cont].nome[espaco]);
									}
									strcpy(marca_nome[cont], marca[cont].nome);
									
									cont++;
									qtd_marca++;
									for(i = 0; i < TAM; i++){
										if(marca[i].nome[0] == '\0'){
											j++;
										}
									}
									
									if(j != 0){
										continuar = le_valida_continuar(continuar, cont);
									}
								} else{
									cont++;
								}
							} while(cont < TAM && continuar == 's');
						}
					break;
					
					case 2:
						cabecalho();
						
						printf("      Nome\n");
						for(i = 0; i < TAM; i++){
							if(marca[i].nome[0] == '\0'){
								printf("| Entrada Vazia\n");
							} else{
								printf("| %s\n",marca[i].nome);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						cabecalho();
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(marca[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s\n",i + 1, marca[i].nome);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							if(marca[opcao_crudl - 1].nome[0] == '\0'){
								qtd_marca++;
							}
							printf("Entre o novo Nome da Marca (%s): ",marca[opcao_crudl - 1].nome);
							scanf(" %[^\n]s",&marca[opcao_crudl - 1].nome);
							
							marca[opcao_crudl - 1].nome[0] = toupper(marca[opcao_crudl - 1].nome[0]);
							if(strchr(marca[opcao_crudl - 1].nome, ' ')){
								for(i = 0; strlen(marca[opcao_crudl - 1].nome); i++){
									if(marca[opcao_crudl - 1].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								marca[opcao_crudl - 1].nome[espaco] = toupper(marca[opcao_crudl - 1].nome[espaco]);
							}
							strcpy(marca_nome[opcao_crudl - 1], marca[opcao_crudl - 1].nome);
						}
					break;
					
					case 4:
						cabecalho();
						printf("Escolha qual dado Excluir\n");
						j = 0;
						for(i = 0; i < TAM; i++){
							if(marca[i].nome[0] != '\0'){
								j++;
								printf("(%d) %s\n", j, marca[i].nome);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							strcpy(marca[opcao_crudl - 1].nome, "\0");
							strcpy(marca_nome[opcao_crudl - 1], "\0");
							printf("Dado Excluido");
							qtd_marca--;
							getch();
						}
					break;
					
					case 5:
						cabecalho();
						if(qtd_marca == 0){
							printf("Nao a nenhuma Marca adicionada para listar, adicione uma Marca primeiro.");
							getch();
						} else{
							sort = le_valida_sort();
							cabecalho();
							
							if(sort == 1){
								printf("Lista de A a Z dos nomes das Marcas:\n");
								
								bubbleSortAZ(marca_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(marca_nome[i][0] != '\0'){
										printf("| %s\n",marca_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							} else{
								printf("Lista de Z a A dos nomes das Marcas:\n");
								
								bubbleSortZA(marca_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(marca_nome[i][0] != '\0'){
										printf("| %s\n",marca_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							}
						}
					break;
					
					case 6:
						
					break;
				}
			break;
			
			case 5:
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(qtd_uf == TAM){
							cabecalho();
							printf("Quantidade maxima de UFs atingida\n");
							printf("\nPressione qualquer botao para sair");
							getch();
						} else{
							cont = 0;
							do{
								if(uf[cont].sigla[0] == '\0'){
									cabecalho();
									printf("| Limite de %d UFs\n\nNome da UF: ",TAM);
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
									strcpy(uf_nome[cont], uf[cont].nome);
									
									i = 0;
									do{
										if(i > 0){
											printf("\nA UF precisa ter 2 caracteres\n");
										}
										printf("Sigla da UF: ");
										scanf(" %s",&uf[cont].sigla);
										i++;
									} while(strlen(uf[cont].sigla) != 2);
									uf[cont].sigla[0] = toupper(uf[cont].sigla[0]);
									uf[cont].sigla[1] = toupper(uf[cont].sigla[1]);
									
									cont++;
									qtd_uf++;
									for(i = 0; i < TAM; i++){
										if(uf[i].sigla[0] == '\0'){
											j++;
										}
									}
									
									if(j != 0){
										continuar = le_valida_continuar(continuar, cont);
									}
								} else{
									cont++;
								}
							} while(cont < TAM && continuar == 's');
						}
					break;
					
					case 2:
						cabecalho();
						
						printf("       UF       |     Sigla\n");
						for(i = 0; i < TAM; i++){
							if(uf[i].sigla[0] == '\0'){
								printf("| Entrada Vazia | Entrada Vazia\n");
							} else{
								printf("| %s | %s\n",uf[i].nome, uf[i].sigla);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						cabecalho();
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(uf[i].sigla[0] == '\0'){
								printf("(%d) Entrada Vazia | Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							if(uf[opcao_crudl - 1].nome[0] == '\0'){
								qtd_uf++;
							}
							printf("Entre o novo Nome da UF (%s): ",uf[opcao_crudl - 1].nome);
							scanf(" %[^\n]s",&uf[opcao_crudl - 1].nome);
							
							uf[opcao_crudl - 1].nome[0] = toupper(uf[opcao_crudl - 1].nome[0]);
							if(strchr(uf[opcao_crudl - 1].nome, ' ')){
								for(i = 0; i < strlen(uf[opcao_crudl - 1].nome); i++){
									if(uf[opcao_crudl - 1].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								uf[opcao_crudl - 1].nome[espaco] = toupper(uf[opcao_crudl - 1].nome[espaco]);
							}
							strcpy(uf_nome[opcao_crudl - 1], uf[opcao_crudl - 1].nome);
							
							i = 0;
							do{
								if(i > 0){
									printf("\nA UF precisa ter 2 caracteres\n");
								}
								printf("Entre a nova Sigla da UF (%s): ",uf[opcao_crudl - 1].sigla);
								scanf(" %s",&uf[opcao_crudl - 1].sigla);
								i++;
							} while(strlen(uf[opcao_crudl - 1].sigla) != 2);
							uf[opcao_crudl - 1].sigla[0] = toupper(uf[opcao_crudl - 1].sigla[0]);
							uf[opcao_crudl - 1].sigla[1] = toupper(uf[opcao_crudl - 1].sigla[1]);
						}
					break;
					
					case 4:
						cabecalho();
						printf("Escolha qual dado Excluir\n");
						j = 0;
						for(i = 0; i < TAM; i++){
							if(uf[i].sigla[0] != '\0'){
								j++;
								printf("(%d) %s | %s\n", j, uf[i].nome, uf[i].sigla);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							strcpy(uf[opcao_crudl - 1].nome, "\0");
							strcpy(uf[opcao_crudl - 1].sigla, "\0");
							strcpy(uf_nome[opcao_crudl - 1], "\0");
							printf("Dados Excluidos");
							qtd_uf--;
							getch();
						}
					break;
					
					case 5:
						cabecalho();
						if(qtd_uf == 0){
							printf("Nao a nenhuma UF adicionada para listar, adicione uma UF primeiro.");
							getch();
						} else{
							sort = le_valida_sort();
							cabecalho();
							
							if(sort == 1){
								printf("Lista de A a Z dos nomes das UFs:\n");
								
								bubbleSortAZ(uf_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(uf_nome[i][0] != '\0'){
										printf("| %s\n",uf_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							} else{
								printf("Lista de Z a A dos nomes das UFs:\n");
								
								bubbleSortZA(uf_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(uf_nome[i][0] != '\0'){
										printf("| %s\n",uf_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							}
						}
					break;
					
					case 6:
						
					break;
				}
			break;
			
			case 6:
				opcao_crudl = le_valida_crudl(opcao_crudl);
				
				switch(opcao_crudl){
					case 1:
						if(strlen(uf[0].nome) == 0){
							cabecalho();
							printf("Impossivel de adicionar uma cidade sem primeiramente adicionar uma UF (Unidade Federativa).");
							getch();
						} else if(qtd_cidade == TAM){
							cabecalho();
							printf("Quantidade maxima de Cidades atingida\n");
							printf("\nPressione qualquer botao para sair");
							getch();
						} else{
							cont = 0;
							do{
								if(cidade[cont].nome[0] == '\0'){
									cabecalho();
									printf("| Limite de 5 Cidades\n\nNome da Cidade: ",TAM);
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
									strcpy(cidade_nome[cont], cidade[cont].nome);
									
									printf("\nEscolha uma das Unidades Federativas (UF)\n");
									for(i = 0; i < qtd_uf; i++){
										printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
									}
									
									opcao_crudl = le_valida_alternativa(i);
									
									strcpy(cidade[cont].uf.nome, uf[opcao_crudl - 1].nome);
									strcpy(cidade[cont].uf.sigla, uf[opcao_crudl - 1].sigla);
									
									cont++;
									qtd_cidade++;
									for(i = 0; i < TAM; i++){
										if(cidade[i].nome[0] == '\0'){
											j++;
										}
									}
									
									if(j != 0){
										continuar = le_valida_continuar(continuar, cont);
									}
								} else{
									cont++;
								}
							} while(cont < TAM && continuar == 's');
						}
					break;
					
					case 2:
						cabecalho();
						
						printf("      Cidade    |       UF      |     Sigla\n");
						for(i = 0; i < TAM; i++){
							if(cidade[i].nome[0] == '\0'){
								printf("| Entrada Vazia | Entrada Vazia | Entrada Vazia\n");
							} else{
								printf("| %s | %s | %s\n",cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						cabecalho();
						printf("Escolha qual dado atualizar\n");
						for(i = 0; i < TAM; i++){
							if(cidade[i].nome[0] == '\0'){
								printf("(%d) Entrada Vazia | Entrada Vazia | Entrada Vazia\n",i + 1);
							} else{
								printf("(%d) %s | %s | %s\n",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
						}
						printf("\n(%d) SAIR",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							if(cidade[opcao_crudl - 1].nome[0] == '\0'){
								qtd_cidade++;
							}
							printf("Entre o novo Nome da Cidade (%s): ",cidade[opcao_crudl - 1].nome);
							scanf(" %[^\n]s",&cidade[opcao_crudl - 1].nome);
							
							cidade[opcao_crudl - 1].nome[0] = toupper(cidade[opcao_crudl - 1].nome[0]);
							if(strchr(cidade[opcao_crudl - 1].nome, ' ')){
								for(i = 0; i < strlen(cidade[opcao_crudl - 1].nome); i++){
									if(cidade[opcao_crudl - 1].nome[i] == ' '){
										espaco = i + 1;
									}
								}
								cidade[opcao_crudl - 1].nome[espaco] = toupper(cidade[opcao_crudl - 1].nome[espaco]);
							}
							strcpy(cidade_nome[opcao_crudl - 1], cidade[opcao_crudl - 1].nome);
					
							cont = opcao_crudl - 1;
							printf("\nEscolha uma das Unidades Federativas (UF)\n");
							for(i = 0; i < qtd_uf; i++){
								printf("(%d) %s | %s\n",i + 1, uf[i].nome, uf[i].sigla);
							}
							
							opcao_crudl = le_valida_alternativa(i);
							
							strcpy(cidade[cont].uf.nome, uf[opcao_crudl - 1].nome);
							strcpy(cidade[cont].uf.sigla, uf[opcao_crudl - 1].sigla);
						}
					break;
					
					case 4:
						cabecalho();
						printf("Escolha qual dado Excluir\n");
						j = 0;
						for(i = 0; i < TAM; i++){
							if(cidade[i].nome[0] != '\0'){
								j++;
								printf("(%d) %s | %s | %s\n", j, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
						}
						printf("\n(%d) SAIR\n",TAM + 1);
						
						opcao_crudl = le_valida_atualizar(opcao_crudl);
						
						if(opcao_crudl == TAM + 1){
							break;
						} else{
							cabecalho();
							strcpy(cidade[opcao_crudl - 1].nome, "\0");
							strcpy(cidade[opcao_crudl - 1].uf.nome, "\0");
							strcpy(cidade[opcao_crudl - 1].uf.sigla, "\0");
							strcpy(cidade_nome[opcao_crudl - 1], "\0");
							printf("Dados Excluidos");
							qtd_cidade--;
							getch();
						}
					break;
					
					case 5:
						cabecalho();
						if(qtd_cidade == 0){
							printf("Nao a nenhuma Cidade adicionada para listar, adicione uma Cidade primeiro.");
							getch();
						} else{
							sort = le_valida_sort();
							cabecalho();
							
							if(sort == 1){
								printf("Lista de A a Z dos nomes das Cidades:\n");
								
								bubbleSortAZ(cidade_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(cidade_nome[i][0] != '\0'){
										printf("| %s\n",cidade_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							} else{
								printf("Lista de Z a A dos nomes das Cidades:\n");
								
								bubbleSortZA(cidade_nome, TAM);
								for(i = 0; i < TAM; i++){
									if(cidade_nome[i][0] != '\0'){
										printf("| %s\n",cidade_nome[i]);
									}
								}
								printf("\nPressione qualquer botao para sair");
								getch();
							}
						}
					break;
					
					case 6:
						
					break;
				}
			break;
			
			case 7:
				opcao_7 = le_valida_opcao_7(opcao_7);
				switch(opcao_7){
					case 1:
						cabecalho();
						if(qtd_produto == 0){
							printf("Nao a nenhum Produto Cadastrado para escolher\n");
						} else{
							printf("Escolha uma das marcas\n");
							for(i = 0; i < qtd_marca; i++){
								printf("(%d) %s",marca[i].nome);
							}
							opcao_crudl = le_valida_alternativa(i);
							
							printf("\nProdutos da marca %s em cada Cidade cadastrada\n",marca[opcao_crudl - 1].nome);
							for(i = 0; i < TAM; i++){
								if(!(stricmp(produto[i].marca.nome, marca[opcao_crudl - 1].nome))){
									printf("| %s | %s",produto[i].nome,cidade[i].nome);
								}
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 2:
						cabecalho();
						if(qtd_cidade == 0){
							printf("Nao a nenhuma Cidade Cadastrada\n");
						} else{
							printf("Cidades Cadastradas: %d\n",qtd_cidade);
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 3:
						cabecalho();
						if(qtd_produto == 0){
							printf("Nao a nenhum Produto Cadastrado para escolher\n");
						} else{
							printf("UF com o produto de maior valor\n");
							printf("| %s | Valor: %s",uf_valor,maior_valor);
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 4:
						cabecalho();
						if(qtd_fornecedor == 0){
							printf("Nao a nenhum fornecedor cadastrado para escolher\n");
						} else{
							printf("Escolha uma das cidades\n");
							for(i = 0; i < qtd_cidade; i++){
								printf("(%d) %s | %s | %s\n",i + 1, cidade[i].nome, cidade[i].uf.nome, cidade[i].uf.sigla);
							}
							opcao_crudl = le_valida_alternativa(i);
							
							printf("\nFornecedores de %s\n",cidade[opcao_crudl - 1].nome);
							for(i = 0; i < TAM; i++){
								if(!(stricmp(fornecedor[i].cidade.nome, cidade[opcao_crudl - 1].nome))){   
									printf("| %s\n",fornecedor[i].nome);
								}
							}
						}
						printf("\nPressione qualquer botao para sair");
						getch();
					break;
					
					case 5:
						
					break;
				}
			break;
			
			case 8:
				cabecalho();
				printf("       Programa Finalizado");
			break;
		}
	}while(opcao >= 1 && opcao < 8);
	
	return 0;
}

int le_valida_opcao_menu(int n1){
	int opcao = 0, cont = 0;
	
	cabecalho();
	do{
		if(cont > 0){
			cabecalho();
			printf("Numero Invalido, tente novamente: \n");
		}
		printf("(1) Manter Categoria\n(2) Manter Fornecedor\n(3) Manter Produto\n(4) Manter Marca\n(5) Manter UF\n(6) Manter Cidade\n(7) Relatorios\n\n(8) SAIR\nEntrada: ");
		scanf("%d",&opcao);
		cont++;
	} while(!(opcao >= 1 && opcao <= 8));
	return opcao;
}

int le_valida_opcao_7(int n1){
	int opcao_7 = 0, cont = 0;
	
	cabecalho();
	do{
		if(cont > 0){
			cabecalho();
			printf("Numero Invalido, tente novamente: \n");
		}
		printf("(1) Quantidade de Produtos de Determinada marca em uma cidade\n(2) Quantidade de cidades cadastradas\n(3) UFs que apresentam os produtos com o maior valor\n(4) Fornecedores de determinada cidade\n\n(5) SAIR\nEntrada: ");
		scanf("%d",&opcao_7);
		cont++;
	}while(!(opcao_7 >= 1 && opcao_7 <= TAM));
	return opcao_7;
}

int le_valida_crudl(int n1){
	int opcao_crudl = 0, cont = 0;
	
	cabecalho();
	do{
		if(cont > 0){
			cabecalho();
			printf("Numero Invalido, tente novamente: \n");
		}
		printf("(1) Criar\n(2) Ler\n(3) Atualizar\n(4) Excluir\n(5) Listar\n\n(6) SAIR\nEntrada: ");
		scanf("%d",&opcao_crudl);
		cont++;
	} while(!(opcao_crudl >= 1 && opcao_crudl <= TAM + 1));
	return opcao_crudl;
}

char le_valida_continuar(char continuar, int cont){
	int cont1 = 0;

	do{
		if(cont1 > 0 && cont < TAM){
			printf("\nOpcao invalida, tente novamente: \n");
			scanf(" %c",&continuar);
		} else if(cont < TAM){
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
		printf("\nEntrada: ");
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
		printf("\nEntrada: ");
		scanf("%d",&j);
		cont++;
	}while(!(j >= 1 && j <= i));
	return j;
}

void bubbleSortAZ(char arr[][STR], int n) {
    int i, j;
    char temp[STR];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void bubbleSortZA(char arr[][STR], int n) {
    int i, j;
    char temp[STR];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) < 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int le_valida_sort(){
	int cont = 0, sort = 0;
	
	cabecalho();
	do{
		if(cont > 0){
			cabecalho();
			printf("Entrada Invalida, tente novamente\n");
		}
		printf("Escolha uma das formas de listagem:\n(1) A - Z\n(2) Z - A\n");
		printf("\nEntrada: ");
		scanf("%d",&sort);
		cont++;
	} while(sort != 1 && sort != 2);
	return sort;
}

void cabecalho(){
	system("cls");
	printf("--------------------------------\n");
	printf("    E   S   T   O   Q   U   E   \n");
	printf("--------------------------------\n");
}
