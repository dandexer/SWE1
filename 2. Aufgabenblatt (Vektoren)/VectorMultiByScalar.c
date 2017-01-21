#include <stdio.h>
#include <stdlib.h>

void VectorMultiByScalar();

int main()
{
    int i = 0, dim = 0, scalar = 0;
    int *vector1;

    printf("----- Multiplikation eines Vektors mit einem Skalar -----\n");
    printf("Bitte Dimension eingeben: "); scanf("%d", &dim);

    vector1 = malloc(dim * sizeof(int));

    while(i < dim)
    {
        printf("%d. Komponente: ", i+1); scanf("%d", &vector1[i++]);
    }
    printf("Bitte Skalar eingeben: "); scanf("%d", &scalar);

    VectorMultiByScalar(vector1, scalar, dim);

    return EXIT_SUCCESS;
}

void VectorMultiByScalar(int *vect1, int scalar, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        vect1[i] = vect1[i] * scalar;
    }
    printf("\n\nErgebnis:\n\n");
    for(i = 0; i < n; i++)
    {
        printf("( %d\t)\n", vect1[i]);
    }
}
