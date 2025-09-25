#include <stdio.h> // biblioteca padr�o de C (que tem fun��es de entrada e saida de dados)
#define PI 3.14159 // Define PI como 3.14159

int main() { // Fun��o principal de indica para o compilador onde come�ar
	float raio, area; // Declara 2 variaveis do tipo float com os nomes "raio" e "area"
	scanf("%f", &raio); // Usa o scanf para entrada de dados que vai mudar o valor da variavel "raio"
	area = PI * raio * raio; // Inicializa a variavel "area" como a multiplica��o entre "pi" e "raio" ao quadrado (raio vezes ele mesmo)
	printf("Area = %.2f\n", area); // Usa printf como saida de dados mostrando o valor da "area" do circulo com precis�o de duas casas decimais
	return 0; // Vai retornar ao final o valor 0 que indica fim da execu��o
} // Fecha o bloco do "main"
