⦁	Introdução:
Este programa em C aborda um problema de classificação de jogadores com base em suas pontuações. O
objetivo é calcular a pontuação final para cada jogador, considerando as 10 melhores pontuações de cada
um. Os jogadores são então classificados em ordem decrescente de pontuação final, com desempate por
ordem alfabética nos nomes

GitHub:

LINK: https://github.com/m4rcossss/TabelaCompetidores


⦁	Implementação:
O programa utiliza uma estrutura de struct definida como Jogador para armazenar informações sobre cada
jogador, incluindo nome, pontuações individuais e pontuação final. A função comparador é implementada
para ser usada como argumento na função de ordenação qsort. O código é composto por um loop principal
que processa vários casos de teste até finalizar o tanto de jogadores escolhido pelo usuário.
⦁	Testes
Teste com 2 competidores:  Teste com 4 competidores, onde se mostra um erro quando não é colocado algum valor entre os 12
necessários:
 


⦁	Conclusão
⦁	O programa atende aos requisitos do problema, classificando os jogadores com base nas pontuações finais.
⦁	As principais dificuldades encontradas estavam relacionadas ao gerenciamento de pontuações e ordenação.
⦁	Possíveis melhorias incluiriam a implementação de verificações de entrada onde o valor é nulo (não tenha
⦁	valor) e a otimização de desempenho para conjuntos de dados maiores.

Anexos
⦁	Partes.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[16];
    int pontuacoes[12];
    int pontuacaoFinal;
    int classificacao;
} Jogador;


int comparador(const void *a, const void *b) {
    const Jogador *jogadorA = (const Jogador *)a;
    const Jogador *jogadorB = (const Jogador *)b;


    if (jogadorB->pontuacaoFinal != jogadorA->pontuacaoFinal) {
        return jogadorB->pontuacaoFinal - jogadorA->pontuacaoFinal;
    }

    return strcmp(jogadorA->nome, jogadorB->nome);
}

int main() {
    int numTeste = 1; 

    while (1) {
        int J;
        scanf("%d", &J);

        if (J == 0) {
            break; 
        }

        Jogador jogadores[J];

        for (int i = 0; i < J; i++) {
            scanf("%s", jogadores[i].nome);
            jogadores[i].pontuacaoFinal = 0;

            for (int j = 0; j < 12; j++) {
                scanf("%d", &jogadores[i].pontuacoes[j]);
            }


            qsort(jogadores[i].pontuacoes, 12, sizeof(int), comparador);
            

            for (int k = 1; k < 11; k++) {
                jogadores[i].pontuacaoFinal += jogadores[i].pontuacoes[k];
            }
        }


        qsort(jogadores, J, sizeof(Jogador), comparador);

 
        printf("Teste %d\n", numTeste++);
        int posicao = 1;
        for (int i = 0; i < J; i++) {
            if (i > 0 && jogadores[i].pontuacaoFinal != jogadores[i - 1].pontuacaoFinal) {
                posicao = i + 1;
            }
            printf("%d %d %s\n", posicao, jogadores[i].pontuacaoFinal, jogadores[i].nome);
        }
        printf("\n");
    }

    return 0;
}
