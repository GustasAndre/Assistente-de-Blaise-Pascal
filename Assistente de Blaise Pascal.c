#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calctempo(float distancia, float velocidade_final)
{
    float tempo = distancia / velocidade_final;
    return tempo;
}

float calcconsumo(float consumo, float tempo)
{
    float consumo_total = consumo * tempo;
    return consumo_total;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    float distancia, velocidade, consumo;
    int clima;
    int num_destinos;
    printf("***************************************************\n");
    printf("🌍Quantos destinos deseja adicionar?🌍\n");
    printf("***************************************************\n");
    scanf("%d", &num_destinos);

    float tempo_total = 0;
    float consumo_total = 0;

    for (int i = 1; i <= num_destinos; i++)
    {
        printf("***************************************************\n");
        printf("🚢 🌍 Destino %d:\n", i);
        printf("***************************************************\n");
        printf("📏Digite a distância da viagem em milhas náuticas:\n ");

        scanf("%f", &distancia);
        printf("***************************************************\n");
        printf("🪢 Digite a velocidade média do navio em nós : \n");
        scanf("%f", &velocidade);

        printf("***************************************************\n");
        printf("🛢️Digite a taxa média de consumo de combustível do navio (galão/hora):");
        scanf("%f", &consumo);

        printf("****************CONDIÇÕES CLIMATICA****************\n");
        printf("*         [0] - SEM PREVISAO DE CHUVA    ☀️        *\n");
        printf("*         [1] - TEMPESTADE LEVE          🌦️        *\n");
        printf("*         [2] - TEMPESTADE MÉDIA         🌧️        *\n");
        printf("*         [3] - TEMPESTADE FORTE         ⛈️        *\n");
        printf("*         [4] - TEMPESTADE SEVERA        ⛈️⛈️      *\n");
        printf("*         [5] - SEM CONDIÇÕES DE NAVEGAR 🌪️        *\n");
        printf("***************************************************\n");
        printf("OPÇÃO:");
        scanf("%d", &clima);

        if (clima == 5)
        {
            printf("***************************************************\n");
            printf("Navegação ao destino %d impossível devido  às condições climáticas.\n", i);
            printf("***************************************************\n");
        }
        else
        {
            float fator_velocidade[] = {1.0, 0.9, 0.7, 0.5, 0.3};
            float fator_climatico = fator_velocidade[clima];

            float velocidade_final = velocidade * fator_climatico;

            float tempo = calctempo(distancia, velocidade_final);
            float consumo_destino = calcconsumo(consumo, tempo);

            int horas = (int)tempo;
            int minutos = (tempo - horas) * 60;

            tempo_total += tempo;
            consumo_total += consumo_destino;

            printf("***************************************************\n");
            printf("Sua viagem para o destino %d levará aproximadamente %d hora(s) e %d minuto(s) 🕰️.\nO consumo de combustível é de %.2f 🛢️.\n", i, horas, minutos, consumo_destino);
            printf("***************************************************\n");
        }
    }

    int horas_total = (int)tempo_total;
    int minutos_total = (tempo_total - horas_total) * 60;
    printf("***************************************************\n");
    printf("Tempo total da viagem para todos os destinos: %d hora(s) e %d minuto(s) 🕰️.\nConsumo total de combustível: %.2f 🛢️.\n", horas_total, minutos_total, consumo_total);
    printf("***************************************************\n");
    return 0;
}
