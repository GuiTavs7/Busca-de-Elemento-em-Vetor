#include <stdio.h>
#include <stdlib.h>

// Funcao para verificar se um valor esta presente em um vetor nao ordenado
int buscaValorNaoOrdenado(int valor, int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return 1; // Valor encontrado
        }
    }
    return 0; // Valor nao encontrado
}

// Funcao para ordenar um vetor usando o algoritmo de ordenacao "bubble sort"
void ordenaVetor(int vetor[], int tamanho) {
    int i; 
    for (i = 0; i < tamanho - 1; i++) {
        int j;
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Funcao para verificar se um valor esta¡ presente em um vetor ordenado (usando busca binaria)
int buscaValorOrdenado(int valor, int vetor[], int tamanho) {
    int esquerda = 0;
    int direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] == valor) {
            return 1; // Valor encontrado
        }
        if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return 0; // Valor nao encontrado
}

int main() {
    int tamanho;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    int i;

    // Leitura dos elementos do vetor nao ordenado
    for (i = 0; i < tamanho; i++) {
        printf("Informe o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int valorProcurado;
    printf("Informe o valor a ser procurado: ");
    scanf("%d", &valorProcurado);

    // Parte 1: Busca em vetor nao ordenado
    if (buscaValorNaoOrdenado(valorProcurado, vetor, tamanho)) {
        printf("O valor %d foi encontrado no vetor nao ordenado.\n", valorProcurado);
    } else {
        printf("O valor %d nao foi encontrado no vetor nao ordenado.\n", valorProcurado);
    }

    // Parte 2: Ordenacao do vetor
    ordenaVetor(vetor, tamanho);

    printf("Vetor ordenado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Parte 3: Busca em vetor ordenado
    if (buscaValorOrdenado(valorProcurado, vetor, tamanho)) {
        printf("O valor %d foi encontrado no vetor ordenado.\n", valorProcurado);
    } else {
        printf("O valor %d nao foi encontrado no vetor ordenado.\n", valorProcurado);
    }

    return 0;
}
