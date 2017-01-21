#include <stdio.h>
#include <stdlib.h>

void VectorAdd();

int main()
{
    int dim = 0, i = 0;
    int *vector1, *vector2;

    printf("----- Addition von 2 Vektoren -----\n");
    printf("Bitte Dimension eingeben: "); scanf("%d", &dim);
    vector1 = malloc(dim * sizeof(int));
    vector2 = malloc(dim * sizeof(int));

    while(i < dim)
    {
        printf("1. Vektor - %d. Zahl: ", i+1); scanf("%d", &vector1[i++]);
    }
    i = 0; puts("");
    while(i < dim)
    {
        printf("2. Vektor - %d. Zahl: ", i+1); scanf("%d", &vector2[i++]);
    }

    VectorAdd(vector1, vector2, dim);

    return EXIT_SUCCESS;
}

void VectorAdd(int *vect1, int *vect2, int n)
{
    int i;
    int *erg = malloc(n* sizeof(int));

    for(i = 0; i < n; i++)
    {
        erg[i] = vect1[i] + vect2[i];
    }
    puts("\nErgebnis:\n");

    for(i = 0; i < n; i++)
    {
        printf("( %d\t)\n", erg[i]);
    }
}
