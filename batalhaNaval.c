#include <stdio.h>

int main() {
    // Desafio Batalha Naval - MateCheck
    // Nível Novato (código base) e Aventureiro (tabuleiro 10x10 e navios diagonais)
    // Este programa representa um tabuleiro de Batalha Naval 10x10 e posiciona quatro navios nele,
    // incluindo dois na diagonal.

    // Tamanho do tabuleiro
    int linhas = 10;
    int colunas = 10;

    // Criação e inicialização do tabuleiro com água (0)
    int tabuleiro[linhas][colunas];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho dos navios
    int tamanho_navio = 3;

    // --- Posicionamento dos Navios ---

    // Navio Horizontal 1
    int navio_h1_linha = 1;
    int navio_h1_coluna = 2;
    printf("Posicionando navio horizontal 1 na linha %d, coluna %d...\n", navio_h1_linha, navio_h1_coluna);
    if (navio_h1_coluna + tamanho_navio <= colunas) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio_h1_linha][navio_h1_coluna + i] = 3;
            printf("Navio H1 - Linha: %d, Coluna: %d\n", navio_h1_linha, navio_h1_coluna + i);
        }
    } else {
        printf("Erro: Navio horizontal 1 fora dos limites.\n");
    }
    printf("\n");

    // Navio Vertical 1
    int navio_v1_linha = 5;
    int navio_v1_coluna = 8;
    printf("Posicionando navio vertical 1 na linha %d, coluna %d...\n", navio_v1_linha, navio_v1_coluna);
    if (navio_v1_linha + tamanho_navio <= linhas) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio_v1_linha + i][navio_v1_coluna] = 3;
            printf("Navio V1 - Linha: %d, Coluna: %d\n", navio_v1_linha + i, navio_v1_coluna);
        }
    } else {
        printf("Erro: Navio vertical 1 fora dos limites.\n");
    }
    printf("\n");

    // Navio Diagonal 1 (para baixo e para a direita)
    int navio_d1_linha = 0;
    int navio_d1_coluna = 0;
    printf("Posicionando navio diagonal 1 na linha %d, coluna %d...\n", navio_d1_linha, navio_d1_coluna);
    if (navio_d1_linha + tamanho_navio <= linhas && navio_d1_coluna + tamanho_navio <= colunas) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio_d1_linha + i][navio_d1_coluna + i] = 3;
            printf("Navio D1 - Linha: %d, Coluna: %d\n", navio_d1_linha + i, navio_d1_coluna + i);
        }
    } else {
        printf("Erro: Navio diagonal 1 fora dos limites.\n");
    }
    printf("\n");

    // Navio Diagonal 2 (para baixo e para a esquerda)
    int navio_d2_linha = 7;
    int navio_d2_coluna = 2;
    printf("Posicionando navio diagonal 2 na linha %d, coluna %d...\n", navio_d2_linha, navio_d2_coluna);
    if (navio_d2_linha + tamanho_navio <= linhas && navio_d2_coluna - tamanho_navio + 1 >= 0) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio_d2_linha + i][navio_d2_coluna - i] = 3;
            printf("Navio D2 - Linha: %d, Coluna: %d\n", navio_d2_linha + i, navio_d2_coluna - i);
        }
    } else {
        printf("Erro: Navio diagonal 2 fora dos limites.\n");
    }
    printf("\n");

    // --- Validação de Sobreposição (simplificada para 4 navios) ---
    printf("Verificando sobreposição (simplificada para 4 navios)...\n");
    int sobreposicao = 0;
    int navios_posicionados[4][tamanho_navio][2]; // Armazena as coordenadas de cada parte dos navios
    int navio_count = 0;

    // Coleta as coordenadas do navio horizontal 1
    if (navio_h1_coluna + tamanho_navio <= colunas) {
        for (int i = 0; i < tamanho_navio; i++) {
            navios_posicionados[navio_count][i][0] = navio_h1_linha;
            navios_posicionados[navio_count][i][1] = navio_h1_coluna + i;
        }
        navio_count++;
    }

    // Coleta as coordenadas do navio vertical 1
    if (navio_v1_linha + tamanho_navio <= linhas) {
        for (int i = 0; i < tamanho_navio; i++) {
            navios_posicionados[navio_count][i][0] = navio_v1_linha + i;
            navios_posicionados[navio_count][i][1] = navio_v1_coluna;
        }
        navio_count++;
    }

    // Coleta as coordenadas do navio diagonal 1
    if (navio_d1_linha + tamanho_navio <= linhas && navio_d1_coluna + tamanho_navio <= colunas) {
        for (int i = 0; i < tamanho_navio; i++) {
            navios_posicionados[navio_count][i][0] = navio_d1_linha + i;
            navios_posicionados[navio_count][i][1] = navio_d1_coluna + i;
        }
        navio_count++;
    }

    // Coleta as coordenadas do navio diagonal 2
    if (navio_d2_linha + tamanho_navio <= linhas && navio_d2_coluna - tamanho_navio + 1 >= 0) {
        for (int i = 0; i < tamanho_navio; i++) {
            navios_posicionados[navio_count][i][0] = navio_d2_linha + i;
            navios_posicionados[navio_count][i][1] = navio_d2_coluna - i;
        }
        navio_count++;
    }

    // Verifica sobreposição comparando todas as partes de todos os navios
    for (int i = 0; i < navio_count; i++) {
        for (int j = i + 1; j < navio_count; j++) {
            for (int k = 0; k < tamanho_navio; k++) {
                for (int l = 0; l < tamanho_navio; l++) {
                    if (navios_posicionados[i][k][0] == navios_posicionados[j][l][0] &&
                        navios_posicionados[i][k][1] == navios_posicionados[j][l][1]) {
                        sobreposicao = 1;
                        break;
                    }
                }
                if (sobreposicao) break;
            }
            if (sobreposicao) break;
        }
        if (sobreposicao) break;
    }

    if (sobreposicao) {
        printf("Aviso: Os navios estão se sobrepondo.\n");
    } else {
        printf("Os navios não estão se sobrepondo.\n");
    }
    printf("\n");

    // --- Exibição do Tabuleiro ---
    printf("--- Tabuleiro com Navios ---\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}