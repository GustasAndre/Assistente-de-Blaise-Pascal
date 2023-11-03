#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
 setlocale(LC_ALL, "Portuguese");
	
 float distancia, velocidade;
 printf("Digite a distância da viagem em milhas náuticas: ");
 scanf("%f", &distancia);
 printf("Digite a velocidade média do navio em nós: ");
 scanf("%f", &velocidade);
 float tempo = distancia / velocidade;
 printf("Sua viagem levará aproximadamente %f horas.\n", tempo);
 return 0;
}




