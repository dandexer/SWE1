#include <stdio.h>
#include <stdlib.h>
// 1
int mystrcat(char str1[], char str2[])
{
    int len1 = 0, len2 = 0, i;
    while(str1[++len1] != '\0'); // Länge String1
    while(str2[++len2] != '\0'); // Länge String2

    for(i = 0; i < len2; i++, len1++)
    {
        str1[len1] = str2[i];
    }
    str1[len1] = '\0';

    return str1;
}
// 2
char *mystrchr(char *string1, char *srch)
{
    int i = 0, j = 0, len = 0, pos = 0;

    while(string1[++len] != '\0');

    for(i = 0; i < len; i++)
    {
        if(string1[i] == srch)
        {
            pos = i;
            break;
        }

    }
    if(pos == 0)
        return 0;
    else
    {
        string1 += pos;
        return string1;
    }
}
// 3
int mystrcmp(char string1[], char string2[])
{
    int i = 0, erg, len = 0;

    while(string1[len++] != '\0');

    while(string1[i] == string2[i])
    {
        i++;
    }

    if(len == i)
        return 0;
    else
        return (string1[i] > string2[i] ? 1 : -1);
}
// 4
int mystrcpy(char string1[], char string2[])
{
    int i = 0, len = 0;

    while(string2[++len] != '\0');

    for(i = 0; i < len; i++)
    {
        string1[i] = string2[i];
    }
    string1[i] = '\0';

    return string1;
}
// 5
int mystrcspn(char string1[], char string2[])
{
    int i, j, len1 = 0, len2 = 0;

    while(string1[++len1] != '\0');
    while(string2[++len2] != '\0');

    int pos = len1;

    for(j = 0; j < len2; j++)
    {
        for(i = 0; i < len1; i++)
        {
            if(string1[i] == string2[j] && i < pos)
                pos = i;
        }
    }
    return pos+1;
}
// 6
int mystrlen(char string1[])
{
    int i = 0;

    while(string1[i] != '\0')
    {
        i++;
    }

    return i;
}
// 7
int mystrncat(char string1[], char string2[], int n)
{
    int len1 = 0, len2 = 0, i;

    while(string1[++len1] != '\0');
    while(string2[++len2] != '\0');

    for(i = 0; i < n; i++, len1++)
    {
        string1[len1] = string2[i];
    }
    string1[len1] = '\0';

    return string1;
}
// 8
int mystrncmp(char string1[], char string2[], int n)
{
    int i = 0, erg, len = 0;

    while(string1[len++] != '\0');

    while(string1[i] == string2[i] && i < n)
    {
        i++;
    }
    if(n == i)
        return 0;
    else
        return (string1[i] > string2[i] ? 1 : -1);
}
// 9
char *mystrncpy(char *dest, char *src, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;
}
// 10
char mystrpbrk(char string1[], char suche[])
{
    int i, j, len1 = 0, len2 = 0;

    while(string1[++len1] != '\0');
    while(suche[++len2] != '\0');

    for(j = 0; j < len2; j++)
    {
        for (i = 0; i < len1; i++)
        {
            if(string1[i] == suche[j])
                return suche[j];
        }
    }
    return 0;
}
// 11
char *mystrrchr(char string1[], char srch[])
{
    int i = 0, j = 0, start, len = 0;

    while(string1[++len] != '\0');

    for(i = 0; i < len; i++)
    {
        if(string1[i] == srch)
            start = i;
    }

    for(i = start; i < len; i++, j++)
    {
        string1[j] = string1[i];
    }
    string1[j] = '\0';

    return string1;
}
// 12
int mystrspn(char *string1, char *string2)
{
    int i, len = 0;

    while(string1[++len] != '\0');

    for(i = 0; i < len; i++)
    {
        if(string1[i] != string2[i])
            return i+1;
    }
}
// 13
char *mystrstr(char *string1, char *srch)
{
    int len1 = 0, len2 = 0, pos = 0, i = 0;

    while(string1[++len1] != '\0'); // Länge von string
    while(srch[++len2] != '\0'); // Länge von srch

    for(pos = 0; pos <= len1; pos++) // Anfang von srch suchen
    {
        if(srch[0] == string1[pos]) // wenn gefunden, Schleife verlassen, pos speichern
            break;

        else if(pos == len1) // Wenn nicht gefunden wurde, gleich 0 zurückgeben
            return 0;
    }

    char *start = string1 + pos; // String ab 1 Buchstaben von srch ermitteln

    for(i = 0; i < len2; i++)
    {
        if(start[i] != srch[i])
            return 0;

        else if(i == len2-1)
            return start;
    }
    return 0;
}
// 14
void mystrtok(char string1[], char trennzeichen)
{
    int i, j, k, len1 = 0, pos = 0;

    while(string1[++len1] != '\0');

    for(i = 0; i <= len1; i++)
    {
        if(string1[i] == trennzeichen || string1[i] == '\0')
        {
            for(k = pos; k < i; k++)
            {
                printf("%c", string1[k]);
            }
            pos = i+1;
            printf("\n");
        }
    }
}
