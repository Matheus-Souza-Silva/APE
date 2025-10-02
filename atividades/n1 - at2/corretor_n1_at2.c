#include <stdio.h>

int main() {
// Informe aqui dia e mês do nascimento:

    int d1 = 0, d2 = 2, m1 = 0, m2 = 7; 

// Questão 1 ---------------------------------------------------------------------------------

    int a = d1, b = d2, c = m1, d = m2, i = 0;
	a++;
	b++;
	c++;
	d++;

    for(i = 1; i <= 3; i++) {
        if(a < c) {
            a = a + b;
            c--;
        } else {
            b += 2;
            d -= 1;
        }
        switch(i) {
            case 1:
                d = (a + b) % 3;
                break;
            case 2:
                if(c % 2 == 0) {
                    c += 3;
                } else {
                    c--;
                }
                break;
            default:
                a++;
                b--;
        }    
    }
	printf("Q1 - Valores finais: a=%d b=%d c=%d d=%d\n", a, b, c, d);

// Questão 2 ---------------------------------------------------------------------------------

    a = d1, b = d2, c = m1, d = m2;
    int contador = 0;

	b++;
	a++;
	d++;
	c++;

    while(contador < 3) {
        contador++;

        if(a % 2 == 0) {
            b += a;
            c -= 1;
        } else if(b > c) {
            a += d;
        } else {
            d += c;
        }

        if(contador == 2) {
            a += 2;
            b--;
        }
    }
	
	printf("Q2 - Valores finais: a=%d b=%d c=%d d=%d\n", a, b, c, d);
	
// Questão 3 ---------------------------------------------------------------------------------

   a = d1, b = d2, c = m1, d = m2, i = 0;

	a++;
	d++;	
	c++;
	d++;
		
    for(i = 1; i <= 4; i++) {
        if(d % 2 == 0) {
            a += c;
            b++;
        } else {
            c -= 2;
            d += a;
        }

        switch(i) {
            case 1:
                a = (b + c) % 5;
                break;
            case 3:
                b += 2;
                c++;
                break;
            default:
                d--;
        }
    }

	printf("Q3 - Valores finais: a=%d b=%d c=%d d=%d\n", a, b, c, d);

// Questão 4 ---------------------------------------------------------------------------------

    a = d1, b = d2, c = m1, d = m2;
    i = 0;

	a = b + 1;
	b++;
	c++;
	b++;

    while(i < 3) {
        i++;

        if(a > d) {
            a--;
            b += c;
        } else {
            c += 2;
            d--;
        }

        if(i % 2 == 0) {
            b--;
            a += d;
        }
    }

	printf("Q4 - Valores finais: a=%d b=%d c=%d d=%d\n", a, b, c, d);

// Questão 5 ---------------------------------------------------------------------------------


    a = d1, b = d2, c = m1, d = m2, i = 0;
    int j = 0;

	a++;
	b++;
	c = c + 2;
	b++;
	
	for(j = 1; j < 2; j++){
	    for(i = 0; i < 3; i++) {
	        if((a + b) % 2 == 0) {
	            c += a;
	            d--;
	        } else {
	            a += 2;
	            b--;
	        }
	
	        switch(i) {
	            case 2:
	                a++;
	                d = c % 4;
	                break;
	            default:
	                b += 2;
	        }
	    }
	}	
	printf("Q5 - Valores finais: a=%d b=%d c=%d d=%d\n", a, b, c, d);
	return 0;
}
