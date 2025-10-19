#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 20

char le_valida_genero();
float le_valida_notas();
char le_valida_continuar(int i);
float calcular_media(float n1, float n2);
void cabecalho();

int main() {
	int i = 0, total_alunos = 0, qtd_aprovados = 0, qtd_reprovados = 0, j = 0;
	float media_geral, media_aprovados, media_reprovados;
	int aprovados_m = 0, aprovados_f = 0, aprovados_p = 0, max_aprovacoes = 0;
	char genero, continuar, genero_mais_aprovacoes;
	
	struct Endereco{
		char endereco[50];
		int numero;
		char complemento[30];
		char cidade[30];
		char uf[3];
		char cep[10];
	};
	
	struct Aluno{
		char nome[50];
		char genero;
		float notas[2];
		struct Endereco end;
	};
	
	struct Aluno aluno[MAX_ALUNOS];
	
	i = 0;
	do{
		cabecalho();
		printf("       Cadastro (Aluno %d)      \n",i+1);
		printf("--------------------------------\n");
		
		printf("Insira o Nome Completo: ");
		scanf(" %[^\n]s",&aluno[i].nome);
		
		aluno[i].genero = le_valida_genero();
		
		aluno[i].notas[0] = le_valida_notas(1);
		aluno[i].notas[1] = le_valida_notas(2);
		
		printf("Insira o Endereco: ");
		scanf(" %[^\n]s",&aluno[i].end.endereco);
		
		printf("Insira o Numero: ");
		scanf("%d",&aluno[i].end.numero);
		
		printf("Insira o Complemento: ");
		scanf(" %[^\n]s",&aluno[i].end.complemento);
		
		printf("Insira a Cidade: ");
		scanf(" %[^\n]s",&aluno[i].end.cidade);
		
		printf("Insira o UF: ");
		scanf(" %s",&aluno[i].end.uf);
		
		printf("Insira o CEP: ");
		scanf(" %s",&aluno[i].end.cep);
		
		i++;
		j++;
		continuar = le_valida_continuar(j);
		
	}while(continuar == 's' && i < MAX_ALUNOS);
	
	cabecalho();
	total_alunos = i;
	
	for(i = 0; i < total_alunos; i++){
		float media = calcular_media(aluno[i].notas[0], aluno[i].notas[1]);
		media_geral += media;
	}
	
	printf("--------ALUNOS APROVADOS--------\n");
	for(i = 0; i < total_alunos; i++){
		float media = calcular_media(aluno[i].notas[0], aluno[i].notas[1]);
		
		if(media >= 7.0){
			printf("%s | %s | %s | %.1f\n", aluno[i].nome, aluno[i].end.cidade, aluno[i].end.uf, media);
			media_aprovados += media;
			qtd_aprovados++;
			
			switch(aluno[i].genero){
				case 'm': 
					aprovados_m++;
				break;
				case 'f': 
					aprovados_f++;
				break;
				case 'p': 
					aprovados_p++;
				break;
			}
		}
	}
	if(qtd_aprovados == 0){
		printf("Nao tem nenhum aluno aprovado\n");
	}
	
	printf("--------ALUNOS REPROVADOS-------\n");
	for(i = 0; i < total_alunos; i++){
		float media = calcular_media(aluno[i].notas[0], aluno[i].notas[1]);
		
		if(media < 7.0){
			printf("%s | %s | %s | %.1f\n", aluno[i].nome, aluno[i].end.cidade, aluno[i].end.uf, media);
			media_reprovados += media;
			qtd_reprovados++;
		}
	}
	if(qtd_reprovados == 0){
		printf("Nao tem nenhum aluno reprovado\n");
	}
	
	printf("----------ESTATISTICAS----------\n");
	printf("Media Geral da Turma: %.1f\n",media_geral / total_alunos);
	
	if(qtd_aprovados > 0){
		printf("Media geral dos aprovados: %.1f\n",media_aprovados / qtd_aprovados);
	} else{
		printf("Media geral dos aprovados: 0.0\n");
	}
	
	if(qtd_reprovados > 0){
		printf("Media geral dos reprovados: %.1f\n",media_reprovados / qtd_reprovados);
	} else{
		printf("Media geral dos reprovados: 0.0\n");
	}
	
	max_aprovacoes = 0;
	if(aprovados_m > max_aprovacoes){
		max_aprovacoes = aprovados_m;
		genero_mais_aprovacoes = 'm';
	}
	if(aprovados_f > max_aprovacoes){
		max_aprovacoes = aprovados_f;
		genero_mais_aprovacoes = 'f';
	}
	if(aprovados_p > max_aprovacoes){
		max_aprovacoes = aprovados_p;
		genero_mais_aprovacoes = 'p';
	}
	
	printf("Genero com mais aprovacoes: ");
	switch(genero_mais_aprovacoes){
		case 'm':
			printf("Masculino");
		break;
		
		case 'f':
			printf("Feminino");
		break;
		
		case 'p':
			printf("Prefiro nao informar");
		break;
	}
	return 0;
}

char le_valida_genero(){
	char genero;
	int cont = 0;
	do{
		if(cont == 0){
			printf("Insira o Genero (m/f/p): ");
			scanf(" %c",&genero);
		} else{
			printf("Entrada Invalida, tente novamente (m/f/p): ");
			scanf(" %c",&genero);
		}
		cont++;
	}while(genero != 'm' && genero != 'f' && genero != 'p');
	return genero;
}

float le_valida_notas(int indice){
	float nota;
	int cont = 0;
	
	do{
		if(cont == 0){
			printf("Insira a N%d (0 - 10): ",indice);
			scanf("%f",&nota);
		} else{
			printf("Nota Invalida, tente novamente (0 - 10): ");
			scanf("%f",&nota);
		}
		cont++;
	}while(nota < 0.0 || nota > 10.0);
	return nota;
}

char le_valida_continuar(int i){
	char continuar;
	int cont = 0;
	
	do{
		if(i < MAX_ALUNOS - 1){
			if(cont == 0){
				printf("Deseja Continuar? (s/n): ");
				scanf(" %c",&continuar);
			} else{
				printf("Entrada Invalida, tente novamente: ");
				scanf(" %c",&continuar);
			}
		} else{
			printf("Limite de Alunos que podem ser Registrados atingido!\n");
			continuar = 'n';
		}
		cont++;
	}while((continuar != 's' && continuar != 'S') && (continuar != 'n' && continuar != 'N'));
	
	if(continuar == 's' || continuar == 'S'){
		continuar = 's';
	}
	return continuar;
}

float calcular_media(float n1, float n2){
	return (n1 + n2) / 2.0;
}

void cabecalho(){
	system("cls");
	printf("--------------------------------\n");
	printf("    S   T   R   U   C   T   S   \n");
	printf("--------------------------------\n");
}
