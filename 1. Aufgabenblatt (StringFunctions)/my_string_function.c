#include <stdio.h>
#include <stdlib.h>
#include "mystring.h" // Eigener String-Header

int main()
{
    int eingabe = 0, n = 0;
    char str1[50], str2[50];
    char ch;

    do
    {

    printf("- 1 -\t strcat - Strings aneinanderhaengen\n");
    printf("- 2 -\t strchr - ein Zeichen im String suchen\n");
    printf("- 3 -\t strcmp - Strings vergleichen\n");
    printf("- 4 -\t strcpy - einen String kopieren\n");
    printf("- 5 -\t strcspn - einen Teilstring ermitteln\n");
    printf("- 6 -\t strlen - Länge eines Strings ermitteln\n");
    printf("- 7 -\t strncat - String mit n Zeichen aneinanderhängen\n");
    printf("- 8 -\t strncmp - n Zeichen von zwei Strings miteinander vergleichen\n");
    printf("- 9 -\t strncpy - String mit n Zeichen kopieren\n");
    printf("- 10 -\t strpbrk - nach dem Auftreten bestimmter Zeichen suchen\n");
    printf("- 11 -\t strrchr - das letzte Auftreten eines bestimmten Zeichens im String suchen\n");
    printf("- 12 -\t strspn - das erste Auftreten eines Zeichens, das nicht vorkommt\n");
    printf("- 13 -\t strstr - einen String nach dem Auftreten eines Teilstrings durchsuchen\n");
    printf("- 14 -\t strtok - einen String anhand bestimmter Zeichen zerlegen\n");
    printf("- 15 -\t Beenden\n\n");
    printf("Welche Stringfunktion wollen Sie testen (Zahl eingeben)? ");
    scanf("%d", &eingabe); printf("\n\n");

    switch(eingabe)
    {
    case 1:
        printf("mystrcat - Strings aneinanderhaengen:\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("\nErgebnis: %s\n\n", mystrcat(str1, str2));
        break;

    case 2:
        printf("mystrchr - ein Zeichen im String suchen:\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("Zeichen eingeben, das gesucht werden soll: "); fflush(stdin); scanf("%c", &ch);

        if(mystrchr(str1, ch) != NULL)
            printf("\nZeichen enthalten!\n");
        else
            printf("\nZeichen nicht enthalten!\n");
        break;

    case 3:
        printf("mystrcmp - strcmp - Strings vergleichen:\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);

        if(mystrcmp(str1, str2) == 0)
            printf("\nStrings sind gleich.\n");
        else if(mystrcmp(str1, str2) < 0)
            printf("\nString2 > String1.\n");
        else
            printf("\nString1 > String2.\n");
        break;

    case 4:
        printf("mystrcpy - einen String kopieren\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("\nErgebnis: %s\n\n", mystrcpy(str1, str2));
        break;

    case 5:
        printf("mystrcspn - einen Teilstring ermitteln\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("\nErstes uebereinstimmendes Zeichen: Pos. %d\n\n", mystrcspn(str1, str2));
        break;

    case 6:
        printf("mystrlen - Laenge eines Strings ermitteln\n");
        printf("String eingeben: "); scanf("%s", &str1);
        printf("\nErgebnis: %d\n\n", mystrlen(str1));
        break;

    case 7:
        printf("mystrncat - String mit n Zeichen aneinanderhaengen\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("Wieviele Zeichen sollen aneinandergehaengt werden? "); scanf("%d", &n);
        printf("\nErgebnis: %s\n\n", mystrncat(str1, str2, n));
        break;

    case 8:
        printf("mystrncmp - n Zeichen von zwei Strings miteinander vergleichen\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("Wieviele Zeichen sollen miteinander verglichen werden? "); scanf("%d", &n);

        if(mystrncmp(str1, str2, n) == 0)
            printf("\nTeilstrings sind gleich\n");
        else if(mystrncmp(str1, str2, n) < 0)
            printf("\nTeilstring2 > Teilstring1\n");
        else
            printf("\nTeilstring1 > Teilstring2.\n");
        break;

    case 9:
        printf("mystrncpy - String mit n Zeichen kopieren\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("Wieviele Zeichen sollen kopiert werden? "); scanf("%d", &n);
        printf("\nErgebnis: %s\n\n", mystrncpy(str1, str2, n));
        break;

    case 10:
        printf("mystrpbrk - nach dem Auftreten bestimmter Zeichen suchen\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("Welche Zeichen sollen gesucht werden? "); scanf("%s", &str2);
        printf("\nErstes gefundene Zeichen: %c\n", mystrpbrk(str1, str2));
        break;

    case 11:
        printf("mystrrchr - das letzte Auftreten eines bestimmten Zeichens im String suchen\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("Welches Zeichen soll gesucht werden? "); fflush(stdin); scanf("%c", &ch);
        printf("\nString nach '%c' ist - '%s'\n", ch, mystrrchr(str1, ch));
        break;

    case 12:
        printf("mystrspn - das erste Auftreten eines Zeichens, das nicht vorkommt\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);
        printf("\nPosition des ersten Zeichen, das nicht vorkommt: %d\n", mystrspn(str1, str2));
        break;

    case 13:
        printf("mystrstr - einen String nach dem Auftreten eines Teilstrings durchsuchen\n");
        printf("String 1 eingeben: "); scanf("%s", &str1);
        printf("String 2 eingeben: "); scanf("%s", &str2);

        if(mystrstr(str1, str2) != NULL)
            printf("\nTeilstring ist enthalten\n");
        else
            printf("\nTeilstring ist nicht enthalten\n");
        break;

    case 14:
        printf("mystrtok - einen String anhand bestimmter Zeichen zerlegen\n");
        printf("String 1 mit Trennzeichen (zB ;) eingeben: "); scanf("%s", &str1);
        printf("Trennzeichen eingeben (zB ;): "); fflush(stdin); scanf("%c", &ch);
        mystrtok(str1, ch);
        break;
    }
        printf("\n");

    } while(eingabe != 15);

    return EXIT_SUCCESS;
}

