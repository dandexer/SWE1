#ifndef SBG_POPULATION_H_INCLUDED
#define SBG_POPULATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 255

typedef struct sbg_population
{
    char date[10];
    unsigned int age;
    unsigned int m_aut;
    unsigned int m_for;
    unsigned int f_aut;
    unsigned int f_for;
    unsigned int sum;
} EINW;

typedef EINW* EINW_PTR; // you can use EINW_PTR instead of EINW* (but it's optional)

typedef enum
{
    date, age, m_aut, m_for, m_all, f_aut, f_for, f_all, aut_all, for_all, all
} KEY;


int lines = 0; // Globale Variable

EINW* readfile(FILE *quelldatei)
{
    int i;
    char puffer[255];

    while ( fgets(puffer, 255, quelldatei) != NULL)
    {
        lines++;
    }

    rewind(quelldatei);

    EINW* population = malloc(sizeof(EINW) * lines); // Speicher reservieren (size of EINW * Anzahl Zeilen)

    fgets(puffer, 255, quelldatei); // 1. Zeile überspringen, da dort die Spaltenbeschriftung steht
    for(i = 0; i < lines; i++)
    {
    fscanf(quelldatei,"%[^;];%d;%d;%d;%d;%d\n", population[i].date, &population[i].age, &population[i].m_aut, &population[i].m_for, &population[i].f_aut, &population[i].f_for);
    }

    for(i = 0; i < lines; i++)
    {
        population[i].sum = population[i].m_aut + population[i].m_for + population[i].f_aut + population[i].f_for; // Einwohner Gesamt pro Alter
    }

    return population;
}

void print(EINW* print)
{
    if(!print)
        printf("Nothing to print available!\n");

    int i;

    printf("Alter\t M/AUT\t M/Ausl\t W/AUT\t W/Ausl\t Total\n");
    for(i = 0; i < lines-1; i++)
    {
        printf("%d\t %d\t %d\t %d\t %d\t %d\n", print[i].age, print[i].m_aut, print[i].m_for, print[i].f_aut, print[i].f_for, print[i].sum);
    }
    puts("");
}

int summe(EINW* sum, KEY k)
{
    int i, sum_m_aut=0, sum_m_for=0, sum_f_aut=0, sum_f_for=0;

    for(i = 0; i <lines-1; i++)
    {
        sum_m_aut+= sum[i].m_aut;
        sum_m_for+= sum[i].m_for;
        sum_f_aut+= sum[i].f_aut;
        sum_f_for+= sum[i].f_for;
    }

    switch(k)
    {
        case m_aut: return sum_m_aut;
        case m_for: return sum_m_for;
        case m_all: return sum_m_aut + sum_m_for;
        case f_aut: return sum_f_aut;
        case f_for: return sum_f_for;
        case f_all: return sum_f_aut + sum_f_for;
        case aut_all: return sum_m_aut + sum_f_aut;
        case for_all: return sum_m_for + sum_f_for;
        case all: return sum_m_aut + sum_m_for + sum_f_aut + sum_f_for;
        default: printf("no valid key entered");
    }
}

int most_men(EINW* men)
{
    int i, age=0, max = men[0].m_aut + men[0].m_for;

    for(i = 0; i < lines-1; i++)
    {
        if( (men[i].m_aut + men[i].m_for) > max )
        {
            max = men[i].m_aut + men[i].m_for;
            age = men[i].age;
        }
    }
    return age;
}

int most_women(EINW* women)
{
    int i, age=0, max = women[0].f_aut + women[0].f_for;

    for(i = 0; i < lines-1; i++)
    {
        if( (women[i].f_aut + women[i].f_for) > max )
        {
            max = women[i].f_aut + women[i].f_for;
            age = women[i].age;
        }
    }
    return age;
}

int most_aut(EINW* aut)
{
    int i, age=0, max = aut[0].m_aut + aut[0].f_aut;

    for(i = 0; i < lines-1; i++)
    {
        if( (aut[i].m_aut + aut[i].f_aut) > max )
        {
            max = aut[i].m_aut + aut[i].f_aut;
            age = aut[i].age;
        }
    }
    return age;
}

int most_for(EINW* foreign)
{
    int i, age=0, max = foreign[0].m_for + foreign[0].f_for;

    for(i = 0; i < lines-1; i++)
    {
        if( (foreign[i].m_for + foreign[i].f_for) > max )
        {
            max = foreign[i].m_for + foreign[i].f_for;
            age = foreign[i].age;
        }
    }
    return age;
}

int most_all(EINW* all)
{
    int i, age=0, max = all[0].m_aut + all[0].m_for + all[0].f_aut + all[0].f_for;

    for(i = 0; i < lines-1; i++)
    {
        if( (all[i].m_aut + all[i].m_for + all[i].f_aut + all[i].f_for) > max )
        {
            max = all[i].m_aut + all[i].m_for + all[i].f_aut + all[i].f_for;
            age = all[i].age;
        }
    }
    return age;
}

double mean_age(EINW *mean)
{
    int i, sum=0;
    double erg=0;

    for(i = 0; i <lines-1; i++)
    {
        sum += mean[i].m_aut + mean[i].m_for + mean[i].f_aut + mean[i].f_for;
    }
    for(i = 0; i < lines-1; i++)
    {
        erg = erg + (mean[i].m_aut + mean[i].m_for + mean[i].f_aut + mean[i].f_for) * mean[i].age;
    }
    erg /= sum;

    return erg;
}

int compare_by_age(const void *a, const void *b)
{
    EINW_PTR l = (EINW_PTR) a;
    EINW_PTR r = (EINW_PTR) b;
    return (l->age - r->age);
}

int compare_by_m_aut(const void *a, const void *b)
{
    EINW_PTR l = (EINW_PTR) a;
    EINW_PTR r = (EINW_PTR) b;
    return (l->m_aut - r->m_aut);
}

int compare_by_m_for(const void *a, const void *b)
{
    EINW_PTR l = (EINW_PTR) a;
    EINW_PTR r = (EINW_PTR) b;
    return (l->m_for - r->m_for);
}

int compare_by_f_aut(const void *a, const void *b)
{
    EINW_PTR l = (EINW_PTR) a;
    EINW_PTR r = (EINW_PTR) b;
    return (l->f_aut - r->f_aut);
}

int compare_by_f_for(const void *a, const void *b)
{
    EINW_PTR l = (EINW_PTR) a;
    EINW_PTR r = (EINW_PTR) b;
    return (l->f_for - r->f_for);
}

int compare_by_sum(const void *a, const void *b)
{
    EINW_PTR l = (EINW_PTR) a;
    EINW_PTR r = (EINW_PTR) b;
    return (l->sum - r->sum);
}

EINW_PTR sortByN(EINW_PTR sort, KEY k)
{
    if(!sort) return NULL;

    switch(k)
    {
       case age:    qsort(sort, lines-1, sizeof(EINW), compare_by_age); print(sort); break;
       case m_aut:  qsort(sort, lines-1, sizeof(EINW), compare_by_m_aut); print(sort); break;
       case m_for:  qsort(sort, lines-1, sizeof(EINW), compare_by_m_for); print(sort); break;
       case f_aut:  qsort(sort, lines-1, sizeof(EINW), compare_by_f_aut); print(sort); break;
       case f_for:  qsort(sort, lines-1, sizeof(EINW), compare_by_f_for); print(sort); break;
       case all:    qsort(sort, lines-1, sizeof(EINW), compare_by_sum); print(sort); break;
    }

    return sort;
}

#endif // SBG_POPULATION_H_INCLUDED
