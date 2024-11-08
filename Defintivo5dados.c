#include <stdio.h>
#include <string.h>

// Função para ordenar uma lista de strings usando o Quicksort
void quick(char vet[][100], int esq, int dir) {
    int pivo = esq;
    int i, j;
    char temp[100];  // Buffer temporário para trocar strings

    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (strcmp(vet[j], vet[pivo]) < 0) {  // Ordenação em ordem alfabética
            strcpy(temp, vet[j]);
            while (j > pivo && strcmp(temp, vet[j - 1]) < 0) {
                strcpy(vet[j], vet[j - 1]);
                j--;
            }
            strcpy(vet[j], temp);
            pivo++;
        }
    }

    if (pivo - 1 >= esq) {
        quick(vet, esq, pivo - 1);
    }
    if (pivo + 1 <= dir) {
        quick(vet, pivo + 1, dir);
    }
}

int main() {
    char lista[5][100] = {
        "Banana",
        "Uva",
        "Maca",
        "Laranja",
        "Abacaxi"
    };
    int n = sizeof(lista) / sizeof(lista[0]);

    printf("Lista antes da ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", lista[i]);
    }

    quick(lista, 0, n - 1);

    printf("\nLista após a ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", lista[i]);
    }

    return 0;
}
