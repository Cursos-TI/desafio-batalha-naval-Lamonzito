#include <stdio.h>

#define TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA_VALOR 0
#define NAVIO_VALOR 3

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TABULEIRO][TABULEIRO]) {
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA_VALOR;
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TABULEIRO][TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser posicionado sem ultrapassar o tabuleiro ou sobrepor outro navio
int podePosicionar(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);

        // Verifica se está dentro dos limites do mapa
        if (l >= TABULEIRO || c >= TABULEIRO) {
            return 0;
        }

        // Verifica se já tem navio na posição
        if (tabuleiro[l][c] == NAVIO_VALOR) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[l][c] = NAVIO_VALOR;
    }
}

int main() {
    int tabuleiro[TABULEIRO][TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas do navio 'horizontal'
    int linhaH = 2, colunaH = 3;
    // Coordenadas do navio 'vertical'
    int linhaV = 5, colunaV = 6;

    // Posiciona navio horizontal 'se possível'
    if (podePosicionar(tabuleiro, linhaH, colunaH, 'H')) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Posiciona navio vertical 'se possível'
    if (podePosicionar(tabuleiro, linhaV, colunaV, 'V')) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
