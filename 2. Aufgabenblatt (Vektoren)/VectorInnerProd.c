#include <stdio.h>
#include <stdlib.h>

void VectorInnerProd();

int main()
{
    int dim = 0, i = 0;
    int *vector1, *vector2;

    printf("----- Berechnung des Skalarprodukts -----\n");
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

    VectorInnerProd(vector1, vector2, dim);

    //for(i = 0; i < dim; printf("vector1: %d. Zahl: %d\n", i, vector1[i++]));
    //for(i = 0; i < dim; printf("vector2: %d. Zahl: %d\n", i, vector2[i++]));

    return EXIT_SUCCESS;
}

void VectorInnerProd(int *vect1, int *vect2, int n)
{
    int i, erg = 0;

    for(i = 0; i < n; i++)
    {
        erg+= vect1[i] * vect2[i];
    }

    printf("\nInner Product is: %d", erg);
}



