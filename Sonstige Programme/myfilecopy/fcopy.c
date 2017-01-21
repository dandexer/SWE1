#include <stdio.h>
#include <stdlib.h>

int myfilecopy(FILE *quelldatei, FILE *zieldatei)
{
    int ch;
    while((ch = fgetc(quelldatei)) != EOF)
    {
        fputc(ch, zieldatei);
    }


    if(fgetc(quelldatei) == EOF)
        printf("Datei erfolgreich kopiert!\n\n\n");

    return 0;
}


int main()
{
    FILE *quelldatei;
    FILE *zieldatei;

    quelldatei = fopen("quelle.txt", "rt");
    zieldatei = fopen("ziel.txt", "wt");

    myfilecopy(quelldatei, zieldatei);

    fclose(quelldatei); fclose(zieldatei);

    return EXIT_SUCCESS;
}
