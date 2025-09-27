#include <stdio.h>

int main() {
	int i = 0;
	
	printf("--------------------------------\n");
	printf("        R E L A T O R I O       \n");
	printf("--------------------------------\n");
	
	for(i = 1;i <=50;i++){
		if(i % 2 == 0){
			if(i % 7 == 0){
				printf("%d M7\n",i);
			} else{
				printf("%d\n",i);
			}
		}
	}
	return 0;
}
