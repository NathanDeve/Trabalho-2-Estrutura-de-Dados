#include <stdio.h>    
#include <stdlib.h>  
#include <time.h>    

long long contador_comparacoes = 0;
long long contador_trocas = 0; 

void resetar_contadores() {
    contador_comparacoes = 0;
    contador_trocas = 0;
}

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int houve_troca = 0; 
        for (j = 0; j < n - i - 1; j++) {
            contador_comparacoes++;
            if (arr[j] > arr[j + 1]) {
                contador_trocas++;
                troca(&arr[j], &arr[j + 1]);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0) {
            break; 
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int indice_menor = i; 
        for (j = i + 1; j < n; j++) {
            contador_comparacoes++;
            if (arr[j] < arr[indice_menor]) { 
                indice_menor = j;
            }
        }
        if (indice_menor != i) {
            contador_trocas++;
            troca(&arr[i], &arr[indice_menor]);
        }
    }
}

void insertion_sort(int arr[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = arr[i]; 
        j = i - 1;

        while (j >= 0) {
            contador_comparacoes++; 
            if (arr[j] > chave) {
                contador_trocas++; 
                arr[j + 1] = arr[j];
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = chave;
    }
}

int particiona(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; 
    int i = (inicio - 1); 
    int j;
    for (j = inicio; j < fim; j++) {
        contador_comparacoes++;
        if (arr[j] <= pivo) {
            i++; 
            if (i != j) {
                contador_trocas++;
                troca(&arr[i], &arr[j]);
            }
        }
    } 
    if (i + 1 != fim) {
        contador_trocas++;
        troca(&arr[i + 1], &arr[fim]); 
    }
    return (i + 1); 
}
void quick_sort_recursive(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particiona(arr, inicio, fim);
        quick_sort_recursive(arr, inicio, indice_pivo - 1);
        quick_sort_recursive(arr, indice_pivo + 1, fim);
    }
}
void quick_sort(int arr[], int n) {
    quick_sort_recursive(arr, 0, n - 1);
}

void intercala(int arr[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1; 
    int n2 = fim - meio;       

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0; j = 0; k = inicio; 

    while (i < n1 && j < n2) {
        contador_comparacoes++;
        
        if (L[i] <= R[j]) {
            contador_trocas++;
            arr[k] = L[i];
            i++;
        } else {
            contador_trocas++; 
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        contador_trocas++;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        contador_trocas++;
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}
void merge_sort_recursive(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort_recursive(arr, inicio, meio);
        merge_sort_recursive(arr, meio + 1, fim);
        intercala(arr, inicio, meio, fim);
    }
}
void merge_sort(int arr[], int n) {
    merge_sort_recursive(arr, 0, n - 1);
}

void criar_ordenado(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) { arr[i] = i; }
}
void criar_reverso(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) { arr[i] = n - 1 - i; }
}
void criar_aleatorio(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) { arr[i] = rand(); }
}
void criar_duplicados(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) { arr[i] = rand() % 10; }
}

int main() {
    int N = 1001;
    srand(time(NULL)); 
    int* vetor_teste = (int*)malloc(N * sizeof(int));
    if (vetor_teste == NULL) { 
        printf("Erro de alocação de memória!\n");
        return 1; 
    }

    printf("--- Mini-Experimento: Bubble Sort (n=1001) ---\n");
    printf("| Cenario          | Comparacoes     | Trocas          |\n");
    printf("|------------------|-----------------|-----------------|\n");
    criar_ordenado(vetor_teste, N); resetar_contadores(); bubble_sort(vetor_teste, N);
    printf("| Ja Ordenado      | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_reverso(vetor_teste, N); resetar_contadores(); bubble_sort(vetor_teste, N);
    printf("| Reverso          | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_aleatorio(vetor_teste, N); resetar_contadores(); bubble_sort(vetor_teste, N);
    printf("| Aleatorio        | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_duplicados(vetor_teste, N); resetar_contadores(); bubble_sort(vetor_teste, N);
    printf("| Muitos Duplicados | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);

    printf("\n--- Mini-Experimento: Selection Sort (n=1001) ---\n");
    printf("| Cenario          | Comparacoes     | Trocas          |\n");
    printf("|------------------|-----------------|-----------------|\n");
    criar_ordenado(vetor_teste, N); resetar_contadores(); selection_sort(vetor_teste, N);
    printf("| Ja Ordenado      | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_reverso(vetor_teste, N); resetar_contadores(); selection_sort(vetor_teste, N);
    printf("| Reverso          | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_aleatorio(vetor_teste, N); resetar_contadores(); selection_sort(vetor_teste, N);
    printf("| Aleatorio        | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_duplicados(vetor_teste, N); resetar_contadores(); selection_sort(vetor_teste, N);
    printf("| Muitos Duplicados | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    
    printf("\n--- Mini-Experimento: Insertion Sort (n=1001) ---\n");
    printf("| Cenario          | Comparacoes     | Trocas/Desliz.  |\n");
    printf("|------------------|-----------------|-----------------|\n");
    criar_ordenado(vetor_teste, N); resetar_contadores(); insertion_sort(vetor_teste, N);
    printf("| Ja Ordenado      | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_reverso(vetor_teste, N); resetar_contadores(); insertion_sort(vetor_teste, N);
    printf("| Reverso          | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_aleatorio(vetor_teste, N); resetar_contadores(); insertion_sort(vetor_teste, N);
    printf("| Aleatorio        | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_duplicados(vetor_teste, N); resetar_contadores(); insertion_sort(vetor_teste, N);
    printf("| Muitos Duplicados | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    
    printf("\n--- Mini-Experimento: Quick Sort (n=1001) ---\n");
    printf("| Cenario          | Comparacoes     | Trocas          |\n");
    printf("|------------------|-----------------|-----------------|\n");
    criar_ordenado(vetor_teste, N); resetar_contadores(); quick_sort(vetor_teste, N);
    printf("| Ja Ordenado      | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_reverso(vetor_teste, N); resetar_contadores(); quick_sort(vetor_teste, N);
    printf("| Reverso          | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_aleatorio(vetor_teste, N); resetar_contadores(); quick_sort(vetor_teste, N);
    printf("| Aleatorio        | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_duplicados(vetor_teste, N); resetar_contadores(); quick_sort(vetor_teste, N);
    printf("| Muitos Duplicados | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);

    printf("\n--- Mini-Experimento: Merge Sort (n=1001) ---\n");
    printf("| Cenario          | Comparacoes     | Movimentos      |\n");
    printf("|------------------|-----------------|-----------------|\n");
    criar_ordenado(vetor_teste, N); resetar_contadores(); merge_sort(vetor_teste, N);
    printf("| Ja Ordenado      | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_reverso(vetor_teste, N); resetar_contadores(); merge_sort(vetor_teste, N);
    printf("| Reverso          | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_aleatorio(vetor_teste, N); resetar_contadores(); merge_sort(vetor_teste, N);
    printf("| Aleatorio        | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);
    criar_duplicados(vetor_teste, N); resetar_contadores(); merge_sort(vetor_teste, N);
    printf("| Muitos Duplicados | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);

    
    free(vetor_teste); 
    return 0;
}
