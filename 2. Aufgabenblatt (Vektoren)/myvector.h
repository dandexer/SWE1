#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED

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

void VectorSub(int *vect1, int *vect2, int n)
{
    int i;
    int *erg = malloc(n* sizeof(int));

    for(i = 0; i < n; i++)
    {
        erg[i] = vect1[i] - vect2[i];
    }
    puts("\nErgebnis:\n");

    for(i = 0; i < n; i++)
    {
        printf("( %d\t)\n", erg[i]);
    }
}
void VectorInnerProd(int *vect1, int *vect2, int n)
{
    int i, erg = 0;

    for(i = 0; i < n; i++)
    {
        erg+= vect1[i] * vect2[i];
    }

    printf("\nInner Product is: %d\n\n", erg);
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
    printf("\nTriple Product is: %d\n\n", erg);
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

#endif // MYVECTOR_H_INCLUDED
