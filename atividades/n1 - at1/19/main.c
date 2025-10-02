#include <stdio.h>

int main() {
	int a = 1, b = 2, c = 3, d = 4, e = 5, i;
	
	printf("Valores iniciais: a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
	
	for(i = 1; i <= 3; i++){
		if(a < b) {
			a += c;
			b += 2;
		} else {
			c--;
			d += e;
		}
		switch(i) {
			case 1:
				e = (a + b) - c;
			break;
			case 2:
				if(d > e) {
					d += 2;
					e += 3;
				} else {
					d++;
					e--;
				}
			break;
			default:
				a = b % 4;
				c += d;
		}
		printf("Iteracao %d: a=%d b=%d c=%d d=%d e=%d\n", i, a, b, c, d, e);
	}
	return 0;
}
