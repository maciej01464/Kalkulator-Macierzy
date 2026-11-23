#include "matrix_io.h"
#include <stdio.h>




void wypisz_do_pliku(FILE *f, double M[max][max], int w, int k)
{
    fprintf(f, "%d %d\n", w, k);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            fprintf(f, "%8.2lf",  M[i][j]);
        }
        fprintf(f, "\n");
    }
}
int wczytaj(char *sciezka, double M[max][max], int *w, int *k)
{
    FILE *f = fopen(sciezka, "r");
    if (f == NULL)
    {
        printf("ERROR : Nie mozna otworzyc pliku %s\n", sciezka);
        return 1;
    }

    if (fscanf(f, "%d %d", w, k) != 2)
    {
        printf("ERROR : Brak wymiarow w pliku %s\n", sciezka);
        fclose(f);
        return 1;
    }

    if (*w < 1 || *w > max || *k < 1 || *k > max)
    {
        printf("ERROR : Wymiary poza zakresem w pliku %s!\n", sciezka);
        fclose(f);
        return 1;
    }

    for (int i = 0; i < *w; i++)
    {
        for (int j = 0; j < *k; j++)
        {
            if (fscanf(f, "%lf", &M[i][j]) != 1)
            {
                printf("ERROR : Za malo elementow w pliku %s\n", sciezka);
                fclose(f);
                return 1;
            }
        }
    }

    fclose(f);
    return 0;
}