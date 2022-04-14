//Insersion sort and quick sort algorithm visualization
//Author : Gustavo Adame

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void insertion_sort(int aux);
void quickSort(int vetor[], int left, int right, int aux);

int main(){


    int flag = 0;
    int opcao = 0;

    while(flag = 1){
        printf("Insira qual algoritmo deseja utilizar:\n");
        printf("1 - Insertion Sort\n");
        printf("2 - Quick Sort\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            int aux;
            printf("insira o tamanho do vetor: ");
            scanf("%d", &aux);
            insertion_sort(aux);
        }
        else if(opcao == 2){
            int aux;
            printf("insira o tamanho do vetor: ");
            scanf("%d", &aux);
            int vetor[aux];

            //seed the random number generator
            srand(time(NULL));

            //fill the vector with random numbers from 0 to aux
            for(int i = 0; i < aux; i++){
                vetor[i] = (rand() % aux)+1;
            }

            quickSort(vetor, 0 , aux, aux);

        }
        else if(opcao == 3){
            flag = 0;
            break;
        }
        else{
            printf("Opcao invalida\n");
        }

        //delay of 5 seconds
        sleep(5);

        system("@cls||clear");

    }

    return 0;
}


void insertion_sort(int aux){
    
    int matrix[aux][aux];
    
    int vetor[aux];

    //seed the random number generator
    srand(time(NULL));

    //fill the vector with random numbers from 0 to aux
    for(int i = 0; i < aux; i++){
        vetor[i] = (rand() % aux)+1;
    }

    //inserction sort a vector
    int temp;
    for(int i = 1; i < aux; i++){
        
        //delay for 0.5 seconds
        usleep(500000);

        system("@cls||clear");
        
        //Insertion sort algorithm starts here
        temp = vetor[i];
        int j = i - 1;
        while(j >= 0 && vetor[j] > temp){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = temp;
       //Insertion sort algorithm ends here 

        //fill the matriz with the number -1
        for(int i = 0; i < aux; i++){
            for(int j = 0; j < aux; j++){
                matrix[i][j] = -1;
            }        int aux3[aux][aux];
        }

        for (int i = 0; i < aux; i++){
            for (int j = 0; j < vetor[i]; j++){
                matrix[i][j] = 1;
            }
        }

        //Auxiliar matrix of size aux x aux to store the matrix rotated 270 degrees
        int aux3[aux][aux];
        for(int i = 0; i < aux; i++){
            for(int j = 0; j < aux; j++){
                aux3[i][j] = matrix[j][aux - i - 1];
            }
        }

        //Print the matrix rotated 270 degrees
        printf("\n\n\n");
        for(int i = 0; i < aux; i++){
            for(int j = 0; j < aux; j++){
                if (aux3[i][j] == 1){
                    printf(" @");
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        }

    } 

}


void quickSort(int vetor[], int left, int right, int aux){
    int i = left, j = right;
    int pivot = vetor[(left + right) / 2];

    int matrix[aux][aux];

    //delay for 0.5 seconds
    usleep(500000);

    system("@cls||clear");

    //fill the matriz with the number -1
    for(int i = 0; i < aux; i++){
        for(int j = 0; j < aux; j++){
            matrix[i][j] = -1;
        }        int aux3[aux][aux];
    }

    for (int i = 0; i < aux; i++){
        for (int j = 0; j < vetor[i]; j++){
            matrix[i][j] = 1;
        }
    }

    //Auxiliar matrix of size aux x aux to store the matrix rotated 270 degrees
    int aux3[aux][aux];
    for(int i = 0; i < aux; i++){
        for(int j = 0; j < aux; j++){
            aux3[i][j] = matrix[j][aux - i - 1];
        }
    }

    //print the matrix rotated 270 degrees
    printf("\n\n\n");
    for(int i = 0; i < aux; i++){
        for(int j = 0; j < aux; j++){
            if (aux3[i][j] == 1){
                printf(" @");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }

    //Quick sort algorithm starts here
    while (i <= j) {
        while (vetor[i] < pivot)
            i++;
        while (vetor[j] > pivot)
            j--;
        if (i <= j) {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(vetor, left, j, aux);
    if (i < right)
        quickSort(vetor, i, right, aux);
}


