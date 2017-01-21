#include <stdio.h>
#include <stdlib.h>

void VectorParPidProd();

int main()
{
    int i = 0;
    int vector1[3], vector2[3], vector3[3];
    char comp = 120; // ASCII Code für x

    printf("----- Berechnung des Spatprodukts -----\n");

    while(i < 3)
    {
        printf("1. Vektor - %c-Komponente: ", comp++); scanf("%d", &vector1[i++]);
    }
    i = 0, comp = 120; puts("");
    while(i < 3)
    {
        printf("2. Vektor - %c-Komponente: ", comp++); scanf("%d", &vector2[i++]);
    }
    i = 0, comp = 120; puts("");
    while(i < 3)
    {
        printf("3. Vektor - %c-Komponente ", comp++); scanf("%d", &vector3[i++]);
    }

    VectorParPidProd(vector1, vector2, vector3);

    return EXIT_SUCCESS;
}

void VectorParPidProd(int *vect1, int *vect2, int *vect3)
{
    int i, erg = 0, tmp[3];

    tmp[0] = vect1[1] * vect2[2] - vect1[2] * vect2[1]; // x-Komponente
    tmp[1] = vect1[2] * vect2[0] - vect1[0] * vect2[2]; // y-Komponente
    tmp[2] = vect1[0] * vect2[1] - vect1[1] * vect2[0]; // z-Komponente

    for(i = 0; i < 3; i++)
    {
        erg+= tmp[i] * vect3[i];
    }
    printf("\nTriple Product is: %d", erg);
}
