#include <stdio.h>

// Desafio Batalha Naval - Nível Novato
// Implementação seguindo as instruções de posicionamento, validação e exibição.

int main() {
    // Cria o tabuleiro 10x10 e preenche tudo com 0 (água)
    int tabuleiro[10][10] = {0};

    // Tamanho dos navios (3 posições cada)
    int tamanho = 3;

    // Coordenadas iniciais dos navios (escolhidas manualmente)
    int linhaNavio1 = 2;  // navio horizontal começa na linha 2
    int colunaNavio1 = 4; // e na coluna 4

    int linhaNavio2 = 6;  // navio vertical começa na linha 6
    int colunaNavio2 = 1; // e na coluna 1

    // Posiciona o primeiro navio (horizontal)
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
    }

    // Posiciona o segundo navio (vertical)
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
    }

    // Mostra o tabuleiro completo na tela
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("0 = agua | 3 = navio\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // pula linha a cada linha da matriz
    }

    return 0;
}