#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
 setlocale(LC_ALL, "Portuguese");
	
 float distancia, velocidade;
 printf("Digite a dist�ncia da viagem em milhas n�uticas: ");
 scanf("%f", &distancia);
 printf("Digite a velocidade m�dia do navio em n�s: ");
 scanf("%f", &velocidade);
 float tempo = distancia / velocidade;
 printf("Sua viagem levar� aproximadamente %f horas.\n", tempo);
 return 0;
}




