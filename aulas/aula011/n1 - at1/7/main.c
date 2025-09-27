#include <stdio.h>

int main() {
	int idade = 0;
	
	printf("--------------------------------\n");
	printf("     M E I A - E N T R A D A    \n");
	printf("--------------------------------\n");
	
	printf("Insira a idade: ");
	scanf("%d",&idade);
	
	if(idade < 18 || idade > 60){
		printf("Meia Entrada");
	} else{
		printf("Entrada Inteira");
	}
	return 0;
}
