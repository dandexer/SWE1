#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s.h"
#define MAX 1024

DATA* readfile(char *filename)
{
    char buffer[MAX];
    int i;
    char *tmp;

    FILE *input = fopen(filename,"rt");
    if(NULL==input) return EXIT_FAILURE;

    len= atoi ( fgets(buffer,MAX,input) );

    messwerte = malloc(sizeof(DATA)*len);
    if(messwerte==NULL) return EXIT_FAILURE;

    for(i=0; i < len;i++)
    {
        fgets(buffer,MAX,input);
        sscanf(buffer,"%f;%s\n",&messwerte[i].temp, messwerte[i].ort);
    }

    return messwerte;
}

int cmp_temp(const void *a, const void *b)
{
    DATA *p1 = a;
    DATA *p2 = b;

    if (p1->temp > p2->temp) return (+1);
    else if (p1->temp < p2->temp) return (-1);
    else return 0;
}

int cmp_name(const void *a, const void *b)
{
    DATA *p1 = a;
    DATA *p2 = b;

    if(p1->ort < p2->ort) return (+1);
    else if(p1->ort > p2->ort) return (-1);
    else return 0;
}

DATA *sortdata(DATA *p, int element)
{
    if(element==1)
        qsort(p, len, sizeof(DATA), cmp_temp);
    else
        qsort(p, len, sizeof(DATA), cmp_name);

    return p;
}

void printdata(DATA *p)
{
    int i=0;

    for(i=0;i<len;i++)
    {
        printf("Ort: %s\t Temperatur: %f\n", p[i].ort, p[i].temp);
    }
}

int main(int argc, char **argv)
{

    if(argc < 3)
    {
        printf("ung argumente\n");
        return EXIT_FAILURE;
    }
    char *pfad = argv[1];
    int sort = atoi(argv[2]);

    readfile(pfad);
    sortdata(messwerte, sort);
    printdata(messwerte);


    return 0;
}
