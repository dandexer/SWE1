#include <stdio.h>
#include <stdlib.h>

void VectorOuterProd();

int main()
{
    int i = 0;
    int vector1[3], vector2[3];
    char comp = 120; // ASCII Code für x

    printf("----- Berechnung des Kreuzprodukts (Vektorprodukts) -----\n");

    while(i < 3)
    {
        printf("1. Vektor - %c-Komponente: ", comp++); scanf("%d", &vector1[i++]);
    }
    i = 0; comp = 120; puts("");
    while(i < 3)
    {
        printf("2. Vektor - %c-Komponente: ", comp++); scanf("%d", &vector2[i++]);
    }

    VectorOuterProd(vector1, vector2);

    return EXIT_SUCCESS;
}

void VectorOuterProd(int *vect1, int *vect2)
{
    int i, erg = 0, x=0, y=0, z=0;

    x = vect1[1] * vect2[2] - vect1[2] * vect2[1];
    z = vect1[0] * vect2[1] - vect1[1] * vect2[0];
    y = vect1[2] * vect2[0] - vect1[0] * vect2[2];

    printf("\nOuter Product is:\n");
    printf("( %d\t)\n( %d\t)\n( %d\t)\n", x, y, z);
}
