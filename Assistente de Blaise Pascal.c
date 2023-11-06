#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
 	setlocale(LC_ALL, "Portuguese");
	
 	float distancia, velocidade, consumo, consumo_total;
	 printf("Digite a distância da viagem em milhas náuticas: \n");
 	 scanf("%f", &distancia);
 	 printf("Digite a velocidade média do navio em nós: \n");
 	 scanf("%f", &velocidade);
 	 
 	 int condicoes_climaticas;
 	 printf("Condições climáticas (0 para sem tempestade, 1 para tempesdade leve, 2 para tempestade média , 3 para tempestade forte, 4 para tempestade severa e 5 para sem condições de navegar): \n");
 	 scanf("%d", &condicoes_climaticas);
 	 
 	 if(condicoes_climaticas == 5){
 	 	printf("Navegação impossivel devido às condições climáticas \n");
	  }
	  else{
    float reducoes_velocidade[] = {0.0, 0.1, 0.3, 0.5, 0.7};

    
    float fator_reducao = reducoes_velocidade[condicoes_climaticas];
    float velocidade_final = velocidade - (velocidade * fator_reducao);   
	float tempo = distancia / velocidade_final; 
	int horas = (int)tempo;
    int minutos = (tempo - horas) * 60;  

printf("Digite a taxa média de consumo de combustivél do navio (galão/hora): \n");
scanf("%f",&consumo);
consumo_total = consumo * tempo;
printf("Sua viagem levará aproximadamente %d horas e %d minutos e o consumo de combustivél é de:%.2f galões. \n", horas, minutos, consumo_total);
}
return 0;
}


// 1. Expanda o sistema para considerar diferentes condições climáticas. Por exemplo, se houver uma tempestade
// prevista, a velocidade média do navio pode diminuir em 20%.
// 2. Adicione uma opção para calcular o consumo de combustível com base na velocidade e tempo de viagem.
// 3. Permita que o usuário adicione vários destinos, calculando o tempo total da viagem e o consumo total de
// combustível.
// 4. No final, o sistema deve ser capaz de fornecer uma rota otimizada (por exemplo, parando em um porto
// intermediário pode ser mais eficiente em termos de combustível do que ir diretamente ao destino final).