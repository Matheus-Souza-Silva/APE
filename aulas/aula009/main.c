#include <stdio.h>

int main() {
	int i = 0, n = 0;
	
	printf("--------------------------------\n");
	printf("--------------FOR---------------\n");
	printf("--------------------------------\n");
	
	for(i = 10;i > 0;i--){
		printf("%d\n",i);
	}
	
	for(i = 1;i <= 100;i += 2){
		printf("%d\n",i);
	}
	
	for(i = 500;i >= 10;i -= 3){ //Qunado for trabalhar com saltos maior que 1 usa-se  -= *tamanho do salto ou += *tamanho do salto
		printf("%d\n",i);
	}
	
	printf("Entre o valor: ");
	scanf("%d",&n);
	
	for(i = 1; i <= n;i++){
		if(i % 2 == 0){
			printf("%d - Par\n",i);
		} else{
			printf("%d - Impar\n",i);
		}
	}

	printf("--------------------------------\n");
	printf("-------------WHILE--------------\n");
	printf("--------------------------------\n");
	
	i = 10;
	while(i >= 1){
		printf("%d\n",i);
		i--;
	}
	
	i = 1;
	while(i <= 100){
		printf("%d\n",i);
		i += 2;
	}
	
	i = 500;
	while(i >= 10){
		printf("%d\n",i);
		i -= 3;
	}

	printf("Entre o valor: ");
	scanf("%d", &n);
	
	i = 1;
	while(i <= n){
		printf("%d\n",i);
		i++;
	}
	
/*
	for(INICIALIZAÇÃO; CONDIÇÃO; SALTO){
	
	}
	
	while(CONDICAO){
		
	}
	
*/
	return 0;
}
