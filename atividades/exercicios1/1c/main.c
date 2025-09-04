#include <stdio.h>

int main() {
	int idade=0, casa=0, sapato=0, em10anos=0;
	char nome[20], cpf[14], rua[20], cidade[30], estado[20], cep[10], nascimento[10], sanguineo[3];
	float altura;
	printf("==================\n");
	printf("     CADASTRO     \n");
	printf("==================\n");
	
	printf("\nNome completo: ");
	scanf("%[^\n]s",&nome);
	
	printf("CPF: ");
	scanf("%s",&cpf);
	
	printf("Idade: ");
	scanf("%d",&idade);
	
	fflush(stdin);
	printf("Rua: ");
	scanf("%[^\n]s",&rua);
	
	printf("Numero da casa: ");
	scanf("%d",&casa);
	
	fflush(stdin);
	printf("Cidade: ");
	scanf("%[^\n]s",&cidade);
	
	fflush(stdin);
	printf("Estado: ");
	scanf("%[^\n]s",&estado);
	
	printf("CEP: ");
	scanf("%s",&cep);
	
	printf("Data nascimento: ");
	scanf("%s",&nascimento);
	
	printf("Numero sapato: ");
	scanf("%d",&sapato);
	
	printf("Idade em 10 anos: ");
	scanf("%d",&em10anos);
	
	printf("Altura: ");
	scanf("%f",&altura);
	
	printf("Tipo sanguineo: ");
	scanf("%s",&sanguineo);
	
	printf("\n==================\n");
	printf(" DADOS INFORMADOS \n");
	printf("==================\n");
	
	printf("\nNome completo: %s\nCPF: %s\nIdade: %d\nRua: %s\nNumero da casa: %d\nCidade: %s\nEstado: %s\nCEP: %s\nData nascimento: %s\nNumero sapato: %d\nIdade em 10 anos: %d\nAltura: %.2f\nTipo sanguineo: %s",nome,cpf,idade,rua,casa,cidade,estado,cep,nascimento,sapato,em10anos,altura,sanguineo);
	return 0;
}
