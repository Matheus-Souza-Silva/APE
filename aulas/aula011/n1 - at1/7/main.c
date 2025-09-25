#include <stdio.h>

int main() {
	int idade = 0;
	
	printf("Insira a idade: ");
	scanf("%d",&idade);
	
	if(idade < 18 || idade > 60){
		printf("Meia Entrada");
	} else{
		printf("Entrada Inteira");
	}
	return 0;
}
