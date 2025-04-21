#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[10][10];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

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

    // Posição do navio horizontal
    int navio_horizontal_linha = 2;   // Linha inicial
    int navio_horizontal_coluna = 1;  // Coluna inicial

    // Posição do navio vertical
    int navio_vertical_linha = 6;     // Linha inicial
    int navio_vertical_coluna = 7;    // Coluna inicial

    // Posicionamento do navio horizontal
    printf("Posicionando navio horizontal na linha %d, coluna %d...\n", navio_horizontal_linha, navio_horizontal_coluna);
    if (navio_horizontal_coluna + tamanho_navio <= colunas) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3; // 3 representa o navio
            printf("Navio Horizontal - Linha: %d, Coluna: %d\n", navio_horizontal_linha, navio_horizontal_coluna + i);
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }
    printf("\n");

    // Posicionamento do navio vertical
    printf("Posicionando navio vertical na linha %d, coluna %d...\n", navio_vertical_linha, navio_vertical_coluna);
    if (navio_vertical_linha + tamanho_navio <= linhas) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3; // 3 representa o navio
            printf("Navio Vertical - Linha: %d, Coluna: %d\n", navio_vertical_linha + i, navio_vertical_coluna);
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }
    printf("\n");

    // Validação de sobreposição (mais adequada para o nível novato)
    printf("Verificando sobreposição...\n");
    int sobreposicao = 0;

    // Verifica se o navio horizontal ocupa a mesma linha do navio vertical
    if (navio_horizontal_linha >= navio_vertical_linha && navio_horizontal_linha < navio_vertical_linha + tamanho_navio) {
        // Se estiverem na mesma linha, verifica se há alguma coluna em comum
        if ((navio_horizontal_coluna < navio_vertical_coluna + 1 && navio_horizontal_coluna + tamanho_navio > navio_vertical_coluna) ||
            (navio_vertical_coluna < navio_horizontal_coluna + tamanho_navio && navio_vertical_coluna + 1 > navio_horizontal_coluna)) {
            sobreposicao = 1;
        }
    }
    // Verifica se o navio vertical ocupa a mesma coluna do navio horizontal
    else if (navio_vertical_coluna >= navio_horizontal_coluna && navio_vertical_coluna < navio_horizontal_coluna + tamanho_navio) {
        // Se estiverem na mesma coluna, verifica se há alguma linha em comum
        if ((navio_vertical_linha < navio_horizontal_linha + 1 && navio_vertical_linha + tamanho_navio > navio_horizontal_linha) ||
            (navio_horizontal_linha < navio_vertical_linha + tamanho_navio && navio_horizontal_linha + 1 > navio_vertical_linha)) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Aviso: Os navios estão se sobrepondo.\n");
    } else {
        printf("Os navios não estão se sobrepondo.\n");
    }
    printf("\n");

    // Exibição do tabuleiro completo
    printf("--- Tabuleiro com Navios ---\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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