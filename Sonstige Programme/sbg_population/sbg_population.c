#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sbg_population.h"

int main()
{
    int auswahl=0;
    FILE *quelldatei = fopen("sbg_einwohner.txt", "rt");

    EINW_PTR population = readfile(quelldatei);

    do
    {
        printf("Bitte Auswahl treffen:\n"\
               "====================================================================\n"\
               "-1-\tList all\n"\
               "-2-\tSum M_AUT\t-3-\tSum M_FOR\t-4-\tSum M_All\n"\
               "-5-\tSum F_AUT\t-6-\tSum F_FOR\t-7-\tSum F_All\n"\
               "-8-\tSum AUT_ALL\t-9-\tSum FOR_ALL\t-10-\tSum All\n"\
               "-11-\tSum MOST_MAN\t-12-\tSum MOST_WOMEN\t-13-\tSum MOST_AUT\n"\
               "-14-\tSum MOST_FOR\t-15-\tSum MOST_ALL\t-16-\tAverage_Age\n"\
               "-17-\tSortBy_M_AUT\t-18-\tSortBy_M_FOR\t-19-\tSortBy_F_AUT\n"\
               "-20-\tSortBy_F_FOR\t-21-\tSortBy_Total\t-22-\tEXIT\n");
        scanf("%d", &auswahl);

        switch(auswahl)
        {
            case 1: print(population); break;
            case 2: printf("\nSummer aller inlaendischen Maenner: %d\n\n", summe(population, m_aut)); break;
            case 3: printf("\nSumme aller auslaendischen Maenner: %d\n\n", summe(population, m_for)); break;
            case 4: printf("\nSumme aller Maenner: %d\n\n", summe(population, m_all)); break;
            case 5: printf("\nSummer aller inlaendischen Frauen: %d\n\n", summe(population, f_aut)); break;
            case 6: printf("\nSumme aller auslaendischen Frauen: %d\n\n", summe(population, f_for)); break;
            case 7: printf("\nSumme aller Frauen: %d\n\n", summe(population, f_all)); break;
            case 8: printf("\nSommer aller inlaendischen Einwohner: %d\n\n", summe(population, aut_all)); break;
            case 9: printf("\nSummer aller auslaendischen Einwohner: %d\n\n", summe(population, for_all)); break;
            case 10: printf("\nSumme aller Einwohner: %d\n\n", summe(population, all)); break;
            case 11: printf("\nAlter mit den meisten Maennern: %d\n\n", most_men(population)); break;
            case 12: printf("\nAlter mit den meisten Frauen: %d\n\n", most_women(population)); break;
            case 13: printf("\nAlter mit den meisten Inlaendern: %d\n\n", most_aut(population)); break;
            case 14: printf("\nAlter mit den meisten Auslaendern: %d\n\n", most_for(population)); break;
            case 15: printf("\nAlter mit den meisten Einwohnern: %d\n\n", most_all(population)); break;
            case 16: printf("\nDurchschnittsalter aller Einwohner: %.3lf\n\n", mean_age(population)); break;
            case 17: sortByN(population, m_aut); break;
            case 18: sortByN(population, m_for); break;
            case 19: sortByN(population, f_aut); break;
            case 20: sortByN(population, f_for); break;
            case 21: sortByN(population, all); break;
            case 22: return EXIT_SUCCESS;
        }

    } while(auswahl != 22);

    fclose(quelldatei);

    return EXIT_SUCCESS;
}

