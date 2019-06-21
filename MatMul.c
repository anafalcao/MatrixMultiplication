#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double MultMatriz(int N){

    time_t t;
    double **ptr1, *ptr2, *ptr3;
    int i, j, k;
    double aux;

    ptr1 = (double **) malloc (sizeof (double *) * N);
    ptr2 = (double *) malloc (sizeof (double) * N);
    ptr3 = (double *) malloc (sizeof (double) * N);

    for (i = 0; i < N; i++)
        ptr1[i] = (double *) malloc (sizeof (double) * N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            ptr1[i][j] = rand ();
        }
    }


    for (i = 0; i < N; i++) {
            ptr2[i] = rand ();
    }

    t = clock();

    for (i = 0; i < N; i++) {
        aux = 0;
        for (k = 0; k < N; k++){
            aux = aux + ptr1[k][i] * ptr2[k];
        }
        ptr3[i] = aux;
    }


    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Dimensão: %i \t", N);
    printf("Tempo:  %f segundos \n", time_taken);

    free(ptr2);
    free(ptr3);
    for (i = 0; i < N; i++)
        free(ptr1[i]);
    free(ptr1);

    printf ("\n");
    return (0);


}

int main ()
{

  FILE *fptr;
  fptr = fopen("multc.csv","w");

  for (int i= 100; i<=10000; i+=100){
    MultMatriz(i);
  }

  printf("FOI!");
  fclose(fptr);
  printf(":)");
  getchar();
  return (0);
}

