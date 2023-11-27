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
