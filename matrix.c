#include "matrix.h"
#include <stdio.h>

int sprawdz_wymiar_DiO(int wA, int wB, int kA, int kB)
{
    if (wA != wB || kA != kB)
    {
        printf("ERROR : Niezgodne wymiary macierzy dla dodawania lub odejmowania!\n");
        return 1;
    }
    return 0;
}
int sprawdz_wymiar_M(int kA, int wB)
{
    if (kA != wB)
    {
        printf("ERROR : Niezgodne wymiary macierzy dla mnozenia!\n");
        return 1;
    }
    return 0;
}
void suma(double A[max][max], double B[max][max], double C[max][max], int w, int k)
{
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void roznica(double A[max][max], double B[max][max], double C[max][max], int w, int k)
{
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void mnozenie(double A[max][max], double B[max][max], double C[max][max], int wA, int kA, int kB)
{
    for (int i = 0; i < wA; i++)
    {
        for (int j = 0; j < kB; j++)
        {
            double s = 0; 
            for (int n = 0; n < kA; n++)
            {
                s += A[i][n] * B[n][j];
            }
            C[i][j] = s;
        }
    }
}