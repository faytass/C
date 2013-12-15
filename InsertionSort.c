#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(unsigned long *A, int *delka, int *srovnani, int *presuny)
{
    int i = 0, j, tmp;
    *srovnani = *presuny = 0;
    for (i = 1; i < *delka; i++)
    {
        tmp = A[i];
        j = i - 1;
        while ((j >= 0) & (A[j] > tmp))
        {
            *srovnani += 1;
            *presuny += 1;
            A[j + 1] = A[j];
            j -= 1;
        }
        if(j >= 0)*srovnani += 1;
        *presuny += 1;
        A[j + 1] = tmp;
    }
}

int main()
{
    int array_lengths[] = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000}, i, j, cmps, mvs;
    int array_size = sizeof(array_lengths) / sizeof(int);
    unsigned long *B;
    srand(time(0));
    printf("\n    POCET           SROVNANI              PRESUNY\n");
    for (i = 0; i < 57; i++)printf("-");
    printf("\n");
    for (i = 0; i < array_size; i++)
    {
        unsigned long *A = (unsigned long *)malloc(array_lengths[i] * sizeof(unsigned long));
        for (j = 0; j < array_lengths[i]; j++)
        {
            A[j] = RAND_MAX*rand() + rand();
        }
        InsertionSort(A, &array_lengths[i], &cmps, &mvs);
        printf("| %7d | %15d %4.2lf | %15d %4.2lf |\n", array_lengths[i], cmps, ((double)cmps) / (array_lengths[i]*array_lengths[i]), mvs, ((double)mvs) / (array_lengths[i]*array_lengths[i]));
        if (i + 1 != array_size)free(A);
        else B = A;
    }
    for (i = 0; i < 57; i++)printf("-");
    printf("\nPrvnich 20 setridenych cisel pole o velikosti 5000 prvku:\n");
    for (i = 0; i < 20; i++)
    {
        printf("\n%lu", B[i]);
    }
    printf("\n");
    for (i = 0; i < 57; i++)printf("-");
    printf("\nPoslednich 10 setridenych cisel pole o velikosti 5000 prvku:\n");
    for (i = (array_lengths[array_size - 1] - 10); i < array_lengths[array_size - 1]; i++)
    {
        printf("\n%lu", B[i]);
    }
	getchar();
    return 0;
}
