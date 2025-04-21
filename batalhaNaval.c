#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato (código base), Aventureiro (tabuleiro 10x10 e navios diagonais), Mestre (Habilidades Especiais)
// Este programa simula um tabuleiro de Batalha Naval com navios posicionados e exibe
// as áreas de efeito de habilidades especiais (Cone, Cruz, Octaedro).

// Tamanho do tabuleiro
const int linhas_tabuleiro = 10;
const int colunas_tabuleiro = 10;

// Tamanho das matrizes de habilidade
const int tamanho_habilidade = 5;
const int centro_habilidade = tamanho_habilidade / 2;

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[linhas_tabuleiro][colunas_tabuleiro]) {
    for (int i = 0; i < linhas_tabuleiro; i++) {
        for (int j = 0; j < colunas_tabuleiro; j++) {
            tabuleiro[i][j] = 0; // 0: Água
        }
    }
}

// Função para posicionar um navio (horizontal, vertical ou diagonal)
void posicionarNavio(int tabuleiro[linhas_tabuleiro][colunas_tabuleiro], int linha_inicial, int coluna_inicial, int tamanho, int orientacao) {
    if (orientacao == 0) { // Horizontal
        if (coluna_inicial + tamanho <= colunas_tabuleiro) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha_inicial][coluna_inicial + i] = 3; // 3: Navio
            }
        }
    } else if (orientacao == 1) { // Vertical
        if (linha_inicial + tamanho <= linhas_tabuleiro) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha_inicial + i][coluna_inicial] = 3;
            }
        }
    } else if (orientacao == 2) { // Diagonal (baixo-direita)
        if (linha_inicial + tamanho <= linhas_tabuleiro && coluna_inicial + tamanho <= colunas_tabuleiro) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha_inicial + i][coluna_inicial + i] = 3;
            }
        }
    } else if (orientacao == 3) { // Diagonal (baixo-esquerda)
        if (linha_inicial + tamanho <= linhas_tabuleiro && coluna_inicial - tamanho + 1 >= 0) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha_inicial + i][coluna_inicial - i] = 3;
            }
        }
    }
}

// Função para criar a matriz de habilidade Cone
void criarHabilidadeCone(int habilidade[tamanho_habilidade][tamanho_habilidade]) {
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            habilidade[i][j] = (i >= centro_habilidade && j >= centro_habilidade - i + centro_habilidade && j <= centro_habilidade + i - centro_habilidade) ? 1 : 0;
        }
    }
}

// Função para criar a matriz de habilidade Cruz
void criarHabilidadeCruz(int habilidade[tamanho_habilidade][tamanho_habilidade]) {
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            habilidade[i][j] = (i == centro_habilidade || j == centro_habilidade) ? 1 : 0;
        }
    }
}

// Função para criar a matriz de habilidade Octaedro
void criarHabilidadeOctaedro(int habilidade[tamanho_habilidade][tamanho_habilidade]) {
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            habilidade[i][j] = (abs(i - centro_habilidade) + abs(j - centro_habilidade) <= centro_habilidade) ? 1 : 0;
        }
    }
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[linhas_tabuleiro][colunas_tabuleiro], int habilidade[tamanho_habilidade][tamanho_habilidade], int linha_origem, int coluna_origem) {
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            if (habilidade[i][j] == 1) {
                int linha_tabuleiro = linha_origem - centro_habilidade + i;
                int coluna_tabuleiro = coluna_origem - centro_habilidade + j;
                if (linha_tabuleiro >= 0 && linha_tabuleiro < linhas_tabuleiro &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < colunas_tabuleiro &&
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] != 3) { // Não sobrepõe navios
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5; // 5: Área afetada
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[linhas_tabuleiro][colunas_tabuleiro]) {
    printf("--- Tabuleiro com Habilidades ---\n");
    for (int i = 0; i < linhas_tabuleiro; i++) {
        for (int j = 0; j < colunas_tabuleiro; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("O "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // Área afetada
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Definição do tabuleiro
    int tabuleiro[linhas_tabuleiro][colunas_tabuleiro];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos navios (exemplo)
    posicionarNavio(tabuleiro, 1, 2, 3, 0); // Navio horizontal
    posicionarNavio(tabuleiro, 5, 8, 3, 1); // Navio vertical
    posicionarNavio(tabuleiro, 0, 0, 3, 2); // Navio diagonal (baixo-direita)
    posicionarNavio(tabuleiro, 7, 2, 3, 3); // Navio diagonal (baixo-esquerda)

    // --- Habilidade Cone ---
    printf("--- Habilidade Cone ---\n");
    int habilidadeCone[tamanho_habilidade][tamanho_habilidade];
    criarHabilidadeCone(habilidadeCone);
    int origemConeLinha = 2;
    int origemConeColuna = 2;
    printf("Aplicando Cone na linha %d, coluna %d...\n", origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, habilidadeCone, origemConeLinha, origemConeColuna);
    exibirTabuleiro(tabuleiro);
    inicializarTabuleiro(tabuleiro); // Limpa o tabuleiro para a próxima habilidade
    posicionarNavio(tabuleiro, 1, 2, 3, 0);
    posicionarNavio(tabuleiro, 5, 8, 3, 1);
    posicionarNavio(tabuleiro, 0, 0, 3, 2);
    posicionarNavio(tabuleiro, 7, 2, 3, 3);

    // --- Habilidade Cruz ---
    printf("--- Habilidade Cruz ---\n");
    int habilidadeCruz[tamanho_habilidade][tamanho_habilidade];
    criarHabilidadeCruz(habilidadeCruz);
    int origemCruzLinha = 7;
    int origemCruzColuna = 5;
    printf("Aplicando Cruz na linha %d, coluna %d...\n", origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, habilidadeCruz, origemCruzLinha, origemCruzColuna);
    exibirTabuleiro(tabuleiro);
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro, 1, 2, 3, 0);
    posicionarNavio(tabuleiro, 5, 8, 3, 1);
    posicionarNavio(tabuleiro, 0, 0, 3, 2);
    posicionarNavio(tabuleiro, 7, 2, 3, 3);

    // --- Habilidade Octaedro ---
    printf("--- Habilidade Octaedro ---\n");
    int habilidadeOctaedro[tamanho_habilidade][tamanho_habilidade];
    criarHabilidadeOctaedro(habilidadeOctaedro);
    int origemOctaedroLinha = 4;
    int origemOctaedroColuna = 3;
    printf("Aplicando Octaedro na linha %d, coluna %d...\n", origemOctaedroLinha, origemOctaedroColuna);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, origemOctaedroLinha, origemOctaedroColuna);
    exibirTabuleiro(tabuleiro);

    return 0;
}