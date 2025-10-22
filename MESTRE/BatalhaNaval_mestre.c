#include <stdio.h>
#include <stdlib.h>

// ==========================================================
// BATALHA NAVAL – DESAFIO NÍVEL MESTRE
// ==========================================================


#define N 10        // Define o tamanho do tabuleiro (10x10)
#define HAB 5       // Tamanho das matrizes de habilidade (5x5)

// ------------------------------------------------------------
// Função para imprimir uma matriz de habilidade (cone, cruz, octaedro)
// Mostra visualmente valores 0 (não afetado) e 1 (afetado) para estudo
// ------------------------------------------------------------
void imprimirMatrizHabilidade(const char* nome, int m[HAB][HAB]) {
    printf("\n>> Matriz de Habilidade: %s\n", nome);
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

// ------------------------------------------------------------
// Função para exibir o tabuleiro completo e legendado
// Os símbolos são: ~ para água, N para navio, * para área de habilidade
// ------------------------------------------------------------
void imprimirTabuleiro(int tab[N][N]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    printf("~ = água | N = navio | * = habilidade\n\n");
    printf("    ");
    for (int j = 0; j < N; j++) printf("%2d ", j);
    printf("\n   ------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < N; j++) {
            if (tab[i][j] == 0) printf(" ~ ");
            else if (tab[i][j] == 3) printf(" N ");
            else if (tab[i][j] == 5) printf(" * ");
        }
        printf("\n");
    }
}

// ------------------------------------------------------------
// Funções que montam cada matriz de habilidade:
// ------------------------------------------------------------

// Função CONE: monta um triângulo isósceles, simétrico, com base cortada
void matrizCone(int m[HAB][HAB]) {
    int centro = HAB / 2;
    // Inicializa todas as posições como 0
    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++)
            m[i][j] = 0;
    // Desenha da linha 0 à penúltima linha (HAB-2)
    for (int i = 0; i < HAB-1; i++)
        for (int j = centro - i; j <= centro + i; j++)
            if (j >= 0 && j < HAB)
                m[i][j] = 1;
}

// Função CRUZ: linha e coluna central viram 1, formando cruz simétrica
void matrizCruz(int m[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++)
            m[i][j] = 0;
    // Marca linha e coluna do centro com 1
    for (int i = 0; i < HAB; i++)
        m[centro][i] = m[i][centro] = 1;
}

// Função OCTAEDRO: desenha um losango usando soma dos deltas ao centro
void matrizOctaedro(int m[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++)
            m[i][j] = (abs(i - centro) + abs(j - centro) <= centro) ? 1 : 0;
}

// ------------------------------------------------------------
// Função para copiar o tabuleiro base para um temporário
// Usada para "limpar" habilidades anteriores
// ------------------------------------------------------------
void copiar(int dest[N][N], int src[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dest[i][j] = (src[i][j] == 5 ? 0 : src[i][j]);
}

// ------------------------------------------------------------
// Função para sobrepor matriz de habilidade ao tabuleiro
// Coloca o centro da matriz no ponto (oi, oj) e só marca onde for água
// ------------------------------------------------------------
void sobrepor(int tab[N][N], int m[HAB][HAB], int oi, int oj) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++) {
            int ti = oi - centro + i; // Calcula linha no tabuleiro
            int tj = oj - centro + j; // Calcula coluna no tabuleiro
            if (ti >= 0 && ti < N && tj >= 0 && tj < N) { // Fica dentro do tabuleiro?
                if (m[i][j] == 1 && tab[ti][tj] != 3) // Só marca onde não tem navio
                    tab[ti][tj] = 5; // Marca área de habilidade
            }
        }
}

int main() {
    int base[N][N] = {0}; // Tabuleiro original: 0 = água, 3 = navio

    // ----------------------------
    // POSICIONAMENTO DOS NAVIOS
    // Cada navio ocupa 3 casas em direções diferentes
    // ----------------------------
    base[1][8] = 3; base[2][7] = 3; base[3][6] = 3;           // diagonal 1
    base[2][1] = 3; base[3][2] = 3; base[4][3] = 3;           // diagonal 2
    base[6][1] = 3; base[6][2] = 3; base[6][3] = 3;           // horizontal
    base[8][4] = 3; base[8][5] = 3; base[8][6] = 3;           // horizontal

    // ----------------------------
    // MATRIZES DE HABILIDADE (cone, cruz, octaedro)
    // ----------------------------
    int cone[HAB][HAB], cruz[HAB][HAB], octa[HAB][HAB];
    matrizCone(cone);
    matrizCruz(cruz);
    matrizOctaedro(octa);

    // VISUALIZA MATRIZ DAS HABILIDADES SEPARADAMENTE
    imprimirMatrizHabilidade("CONE", cone);
    imprimirMatrizHabilidade("CRUZ", cruz);
    imprimirMatrizHabilidade("OCTAEDRO", octa);

    int tabH[N][N];

    // ----------------------------
    // SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO
    // O cone está em uma posição livre (linha 6, coluna 6)
    // Cruz e Octaedro em posições centrais ou livres
    // ----------------------------

    copiar(tabH, base);
    sobrepor(tabH, cone, 6, 6); // Mude aqui para outro ponto se quiser
    printf("\n>> Tabuleiro + habilidade CONE (origem [6,6]):\n");
    imprimirTabuleiro(tabH);

    copiar(tabH, base);
    sobrepor(tabH, cruz, 5, 5); // Cruz centrada em [5,5]
    printf("\n>> Tabuleiro + habilidade CRUZ (origem [5,5]):\n");
    imprimirTabuleiro(tabH);

    copiar(tabH, base);
    sobrepor(tabH, octa, 5, 5); // Octaedro centrado em [5,5]
    printf("\n>> Tabuleiro + habilidade OCTAEDRO (origem [5,5]):\n");
    imprimirTabuleiro(tabH);

    printf("\nLegenda: ~ = água | N = navio | * = habilidade\n");
    printf("Altere a origem das habilidades se quiser testar outras regiões!\n");

    return 0;
}
