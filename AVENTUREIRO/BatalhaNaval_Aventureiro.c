#include <stdio.h>

// ==========================================================
// BATALHA NAVAL – DESAFIO NÍVEL AVENTUREIRO
// ==========================================================

int main() {
    // Matriz para representar o tabuleiro: 0 = água, 3 = navio
    int tabuleiro[10][10] = {0};

    // ---------------------------
    // Posicionamento dos NAVIOS
    // ---------------------------

    // 1° Diagonal ↙ (da direita para esquerda) - ocupa (1,8), (2,7), (3,6)
    tabuleiro[1][8] = 3;
    tabuleiro[2][7] = 3;
    tabuleiro[3][6] = 3;

    // 2° Diagonal ↙ (da esquerda para direita) - ocupa (2,1), (3,2), (4,3)
    tabuleiro[2][1] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[4][3] = 3;

    // 3° Horizontal – fila 6, colunas 1-3
    tabuleiro[6][1] = 3;
    tabuleiro[6][2] = 3;
    tabuleiro[6][3] = 3;

    // 4° Horizontal – fila 8, colunas 4-6
    tabuleiro[8][4] = 3;
    tabuleiro[8][5] = 3;
    tabuleiro[8][6] = 3;

    // ---------------------------
    // EXIBIR O TABULEIRO
    // ---------------------------

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    printf("0 = água | 3 = navio\n\n");

    // Cabeçalho das colunas (índices de 0 a 9)
    printf("    ");
    for(int coluna = 0; coluna < 10; coluna++)
        printf("%2d ", coluna);
    printf("\n   ------------------------------\n");

    // Exibe cada linha: índice lateral + conteúdo das colunas
    for(int linha = 0; linha < 10; linha++) {
        printf("%2d | ", linha);
        for(int coluna = 0; coluna < 10; coluna++)
            printf("%2d ", tabuleiro[linha][coluna]);
        printf("\n");
    }

    printf("\nTabuleiro montado conforme compreensão e especificação do desafio.\n");
    return 0;
}