#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <time.h>

void myfileinfo();

int main()
{
    FILE *datei;

    datei = fopen("text.txt", "rt");

    myfileinfo(datei);

    return EXIT_SUCCESS;
}

void myfileinfo(FILE *quelldatei)
{

/* Dateiattribute ermitteln */

    struct stat attribut;
    stat("text.txt", &attribut);

    printf("==================== DATEI-INFOS ====================\n\n");
    // Art der Datei
    if(attribut.st_mode & S_IFREG)
         printf("Es handelt sich um eine regulaere Datei\n");
    else if(attribut.st_mode & S_IFDIR)
         printf("Es handelt sich um ein Verzeichnis");
    else if(attribut.st_mode & S_IFCHR)
         printf("Es handelt sich um eine Geraetedatei");
    else
         printf("Dateiart nicht erkannt\n");

    // Dateigröße
    printf("Die Datei hat %ld Bytes\n", attribut.st_size);
    // Letzter Zugriff
    printf("Letzter Zugriff: %s", ctime(&attribut.st_atime));
    // Letzte Änderung
    printf("Letzte Aenderung: %s", ctime(&attribut.st_mtime));

    printf("Zugriffsrechte (read/write/execute): ");
    if(attribut.st_mode & S_IWRITE) printf("r "); else printf("-");
    if(attribut.st_mode & S_IREAD) printf("w "); else printf("-");
    if(attribut.st_mode & S_IEXEC) printf("x "); else printf("-");
    puts("");


/* Zeichen, Wörter und Zeilen ermitteln */

    int lines=0, words=0, chars=0;
    int ch;
    char L[254];

    while( (fgets(L, 254, quelldatei)) != NULL) // Zeilen zählen
    {
        lines++;
    }
    rewind(quelldatei);
    do
    {
        ch = fgetc(quelldatei);
        chars++;

        if(ch == ' ')
            words++;

    } while(ch != EOF);

    words+=lines; // für jede Zeile das erste Wort dazuzählen
    chars-=lines; // '\n' wird auch als Zeichen gezählt, daher ziehe ich es hier ab

    fclose(quelldatei);

    printf("\nZeichen: %d\nZeilen: %d\nWoerter: %d\n\n", chars, lines, words);
}
