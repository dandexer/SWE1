#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myvector.h"
#define DIM 3

void showhelp();

int main(int argc, char *argv[])
{
    int vekt1[3] = {0}, vekt2[3] = {0}, vekt3[3] = {0}, skalar = 0;
    char auswahl, i;

    printf("%s", argv[1]);
    showhelp();

if(argc > 1)
    {
    if( strchr(argv[1], 'a'))       // Addition
        auswahl = 'a';
    else if( strchr(argv[1], 'b'))  // Subtraktion
        auswahl = 'b';
    else if( strchr(argv[1], 'c'))  // Mult. mit Skalar
        auswahl = 'c';
    else if( strchr(argv[1], 'd'))  // Skalarprodukt
        auswahl = 'd';
    else if( strchr(argv[1], 'e'))  // Kreuzprodukt
        auswahl = 'e';
    else if( strchr(argv[1], 'f'))  // Spatprodukt
        auswahl = 'f';
    else return EXIT_FAILURE;


    if(auswahl == 'a' || auswahl == 'b' || auswahl == 'd' || auswahl == 'e')
    {
        if(argc < 4) return EXIT_FAILURE;

        else
        {
            sscanf(argv[2],"%d-%d-%d", &vekt1[0], &vekt1[1], &vekt1[2]);
            sscanf(argv[3],"%d-%d-%d", &vekt2[0], &vekt2[1], &vekt2[2]);
        }
    }
    else if(auswahl == 'c')
    {
        if(argc < 4) return EXIT_FAILURE;

        else
        {
            sscanf(argv[2],"%d-%d-%d", &vekt1[0], &vekt1[1], &vekt1[2]);
            sscanf(argv[3],"%d", &skalar);
        }
    }
    else if(auswahl == 'f')
    {
        if(argc < 5) return EXIT_FAILURE;

        else
        {
            sscanf(argv[2],"%d-%d-%d", &vekt1[0], &vekt1[1], &vekt1[2]);
            sscanf(argv[3],"%d-%d-%d", &vekt2[0], &vekt2[1], &vekt2[2]);
            sscanf(argv[4],"%d-%d-%d", &vekt3[0], &vekt3[1], &vekt3[2]);
        }
    }
    else return EXIT_FAILURE;

    switch(auswahl)
    {
        case 'a': VectorAdd(vekt1, vekt2, DIM); break;
        case 'b': VectorSub(vekt1, vekt2, DIM); break;
        case 'c': VectorMultiByScalar(vekt1, skalar, DIM); break;
        case 'd': VectorInnerProd(vekt1, vekt2, DIM); break;
        case 'e': VectorOuterProd(vekt1, vekt2); break;
        case 'f': VectorParPidProd(vekt1, vekt2, vekt3); break;
    }
}
    return EXIT_SUCCESS;
}

void showhelp(void) {

    printf("=============== Vektoroperationen ===============\n\n"\
          "Programm fuehrt folgende Operationen mit 3-dimensionalen Vektoren aus"\
          "\n\nFolgende Optionen stehen"\
          " Ihnen zur Verfuegung:\n\n"\
          "\t-a  Addition von 2 Vektoren\t| zB. -a 4-3-0 2-2-1\n"\
          "\t-b  Subtraktion von 2 Vektoren\t| zB. -b 4-3-0 2-2-1\n"\
          "\t-c  Multiplikation mit Skalar\t| zB. -c 4-3-0 5\n"\
          "\t-d  Bildung des Skalarprodukts\t| zB. -d 4-3-0 2-2-1\n "\
          "\t-e  Bildung des Vektorprodukts\t| zB. -e 4-3-0 2-2-1\n"
          "\t-f  Berechnung des Spatprodukts\t| zB. -f 4-3-0 2-2-1 5-0-1\n\n");
}
