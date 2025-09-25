#include <stdio.h> // biblioteca padrão de C (que tem funções de entrada e saida de dados)
#define PI 3.14159 // Define PI como 3.14159

int main() { // Função principal de indica para o compilador onde começar
	float raio, area; // Declara 2 variaveis do tipo float com os nomes "raio" e "area"
	scanf("%f", &raio); // Usa o scanf para entrada de dados que vai mudar o valor da variavel "raio"
	area = PI * raio * raio; // Inicializa a variavel "area" como a multiplicação entre "pi" e "raio" ao quadrado (raio vezes ele mesmo)
	printf("Area = %.2f\n", area); // Usa printf como saida de dados mostrando o valor da "area" do circulo com precisão de duas casas decimais
	return 0; // Vai retornar ao final o valor 0 que indica fim da execução
} // Fecha o bloco do "main"
