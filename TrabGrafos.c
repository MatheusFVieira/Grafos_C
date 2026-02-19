#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem, destino, peso;
} Conexao;

typedef struct {
    int total_roteadores, total_conexoes;
    Conexao* lista_conexoes;
} Rede;

int compararConexoes(const void* a, const void* b) {
    return ((Conexao*)a)->peso - ((Conexao*)b)->peso;
}

int buscarRepresentante(int pai[], int i) {
    if (pai[i] == i) return i;
    return pai[i] = buscarRepresentante(pai, pai[i]);
}

void unirConjuntos(int pai[], int rank[], int x, int y) {
    int rX = buscarRepresentante(pai, x);
    int rY = buscarRepresentante(pai, y);
    if (rank[rX] < rank[rY]) pai[rX] = rY;
    else if (rank[rX] > rank[rY]) pai[rY] = rX;
    else { pai[rY] = rX; rank[rX]++; }
}

void exibirCabecalho() {
    printf("\n==================================================\n");
    printf("   SISTEMA DE OTIMIZACAO DE REDE - PROJETO COLTEC\n");
    printf("     Tema 3: Economia de Verba em Infraestrutura\n");
    printf("==================================================\n");
}

int main() {
    int V, E, custo_original = 0, custo_otimizado = 0;

    exibirCabecalho();

    printf("[CONFIGURACAO] Informe a escala da rede:\n");
    printf("-> Numero total de roteadores: ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        printf("\n[ERRO] Quantidade invalida de roteadores.\n");
        return 1;
    }

    printf("-> Numero de cabos instalados atualmente: ");
    if (scanf("%d", &E) != 1 || E < (V - 1)) {
        printf("\n[ERRO] Para conectar %d roteadores, sao necessarios ao menos %d cabos.\n", V, V-1);
        return 1;
    }

    Rede* rede = (Rede*)malloc(sizeof(Rede));
    rede->lista_conexoes = (Conexao*)malloc(E * sizeof(Conexao));

    printf("\n[DADOS] Agora, insira os detalhes de cada conexao existente.\n");
    printf("Formato: [ID Origem] [ID Destino] [Comprimento em Metros]\n");
    printf("Nota: Use IDs de 0 ate %d.\n", V - 1);

    for (int i = 0; i < E; i++) {
        printf("\nConexao %d/%d: ", i + 1, E);
        if (scanf("%d %d %d", &rede->lista_conexoes[i].origem, 
                            &rede->lista_conexoes[i].destino, 
                            &rede->lista_conexoes[i].peso) != 3) {
            printf("[AVISO] Entrada invalida. Tente novamente esta conexao.\n");
            while(getchar() != '\n'); // Limpa o buffer
            i--; continue;
        }

        if (rede->lista_conexoes[i].origem >= V || rede->lista_conexoes[i].destino >= V || 
            rede->lista_conexoes[i].origem < 0 || rede->lista_conexoes[i].destino < 0) {
            printf("[ERRO] Roteadores %d ou %d estao fora do limite (0 a %d)!\n", 
                    rede->lista_conexoes[i].origem, rede->lista_conexoes[i].destino, V-1);
            i--; continue;
        }
        custo_original += rede->lista_conexoes[i].peso;
    }

    printf("\n[PROCESSANDO] Calculando a Arvore Geradora Minima...\n");
    qsort(rede->lista_conexoes, E, sizeof(Conexao), compararConexoes);

    int *pai = (int*)malloc(V * sizeof(int));
    int *rank = (int*)malloc(V * sizeof(int));
    for (int v = 0; v < V; v++) { pai[v] = v; rank[v] = 0; }

    printf("\n--- RESULTADO DA OTIMIZACAO ---\n");
    int conexoes_feitas = 0;
    for (int i = 0; i < E && conexoes_feitas < V - 1; i++) {
        int u = buscarRepresentante(pai, rede->lista_conexoes[i].origem);
        int v = buscarRepresentante(pai, rede->lista_conexoes[i].destino);

        if (u != v) {
            printf("[MANTER] Roteador %d <--> Roteador %d (%d metros)\n", 
                   rede->lista_conexoes[i].origem, rede->lista_conexoes[i].destino, rede->lista_conexoes[i].peso);
            custo_otimizado += rede->lista_conexoes[i].peso;
            unirConjuntos(pai, rank, u, v);
            conexoes_feitas++;
        }
    }

    printf("\n==================================================\n");
    printf("RESUMO ECONOMICO:\n");
    printf("- Gasto Original:  %d metros\n", custo_original);
    printf("- Gasto Otimizado: %d metros\n", custo_otimizado);
    printf("- ECONOMIA TOTAL:  %d metros (%.1f%% de reducao)\n", 
           custo_original - custo_otimizado, 
           ((float)(custo_original - custo_otimizado) / custo_original) * 100);
    printf("==================================================\n");

    free(pai); free(rank);
    free(rede->lista_conexoes); free(rede);

    return 0;
}