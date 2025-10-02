#include <stdio.h>

int main() {
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int contador = 0;
	
	printf("Valores iniciais: a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
	
	while(contador < 4) {
		contador++;
		if(a % 2 == 0) {
			b += a;
			c = 2 * b;
		} else if(b > c) {
			a += d;
			e--;
		} else {
			d = a + b + c;
		}
		
		do {
			if(e > 10) {
				e -= 3;
			} else if(e < 2) {
				e += 3;
			}
			d++;
		} while(d % 3 != 0);
		
		if(contador == 2) {
			a *= b;
			c = d - e;
		}
		
		printf("Execucao %d: a=%d b=%d c=%d d=%d e=%d\n", contador, a, b, c, d, e);
	}
	return 0;
}
