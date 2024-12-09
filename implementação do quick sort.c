#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000

void quickSort(int V[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int pivot = V[direita];
        int i = (esquerda - 1);

        for (int j = esquerda; j < direita; j++)
        {
            if (V[j] <= pivot)
            {
                i++;
                int temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }

        int temp = V[i + 1];
        V[i + 1] = V[direita];
        V[direita] = temp;

        int p = i + 1;

        quickSort(V, esquerda, p - 1);
        quickSort(V, p + 1, direita);
    }
}

int main()
{
    int V[MAX];
    for (int m = 0; m < 3; m++)
    {
        printf("\n%d: \n \n", m+1);
        for (int n = 0; n <= MAX; n += 20000)
        {
            for (int i = 0; i < n; i++)
            {
                V[i] = rand() % 1000000;
            }

            clock_t comeco = clock();
            quickSort(V, 0, n - 1);
            clock_t fim = clock();

            double demorou = ((double)(fim - comeco)) / CLOCKS_PER_SEC;

            printf("N = %d, Tempo = %f segundos\n", n, demorou);
        }
    }
    printf("acabou \n \n");
    return 0;
}
