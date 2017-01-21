/*
Schreiben Sie eine Funktion mit dem Namen RandBin, mit der Sie n Zufallszahlen erzeugen.
Die Zufallszahlen sollen sich im Wertebereich einer vorzeichenlosen 16-bit Zahl bewegen.
Die R�ckgabe (short*, malloc) soll als n*16 short-Array mit etwaigen f�hrenden Nullen erfolgen.
Die R�ckgabematrix eines Aufrufes mit n =3 k�nnen wie folgt aussehen:
0110101011010100
1111000101011111
0001001010010010
Hinweis: Zur Erzeugung einer Zufallszahl k�nnen die Funktionen rand() und srand() aus der stdlib.h verwendet werden.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 16

void RandBin();

int main()
{
    int anzahl;

    printf("Wieviele 16-bit-Zufallszahlen wollen Sie erzeugen? "); scanf("%d", &anzahl);
    puts("");

    RandBin(anzahl);

    return EXIT_SUCCESS;
}

void RandBin(int n)
{
    int i, j;
    short **matrix = malloc(n * sizeof(short *)); // Speicherreservierung f�r Zeile

    srand(time(NULL));

    for(i = 0; i < n; i++) // Speicherreservierung f�r Spalten
    {
        matrix[i] = malloc(SIZE * sizeof(short));
    }

    for(i = 0; i < n; i++) // Zeile
    {
        for(j = 0; j < SIZE; j++) // Spalte
        {
            matrix[i][j] = rand() % 2;
            printf("%d", matrix[i][j]);
        }
        puts("");
    }
}
