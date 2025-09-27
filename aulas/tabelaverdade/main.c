#include <stdio.h>

int main() {
	int i = 0, j = 0, x = 0, y = 0, z = 0;
	
	x = 5;
	y = 5 * 2;
	z = x + y;
	
	for(i = 1;i < 3;i++){
		for(j = 1;j < 3;j++){
			x++;
			if(x % 3 == 0){
				z++;
			} else{
				z = z + z;
			}
		}
		y = y + 1;
	}
	
	printf("x: %d, y: %d, z: %d, i: %d, j: %d",x, y, z, i, j);
	return 0;
}
