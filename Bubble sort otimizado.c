#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>    

long long contador_comparacoes = 0;
long long contador_trocas = 0;


void resetar_contadores() {
    contador_comparacoes = 0;
    contador_trocas = 0;
}

//Para eu conseguir trocar
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

//Criar elementos N para o loop for
void criar_ordenado(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
}


void criar_reverso(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i] = n - 1 - i;
    }
}


void criar_aleatorio(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void criar_duplicados(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10; 
    }
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



    criar_ordenado(vetor_teste, N);
    resetar_contadores();
    bubble_sort(vetor_teste, N);
    printf("| Ja Ordenado      | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);


    criar_reverso(vetor_teste, N);
    resetar_contadores();
    bubble_sort(vetor_teste, N);
    printf("| Reverso          | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);


    criar_aleatorio(vetor_teste, N);
    resetar_contadores();
    bubble_sort(vetor_teste, N);
    printf("| Aleatorio        | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);

	
    criar_duplicados(vetor_teste, N);
    resetar_contadores();
    bubble_sort(vetor_teste, N);
    printf("| Muitos Duplicados | %-15lld | %-15lld |\n", contador_comparacoes, contador_trocas);


    free(vetor_teste); 
    
    return 0;
}
