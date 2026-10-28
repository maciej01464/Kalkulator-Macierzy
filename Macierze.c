#include <stdio.h>
#include <stdbool.h>
#define max 20

int sprawdz_wymiar(int wA, int wB, int kA, int kB)
{

    bool error = false;
    if (wA < 1 || wA > max || kA < 1 || kA > max || wB < 1 || wB > max || kB < 1 || kB > max)
    {
        printf("ERROR : Wymiary poza zakresem!");
        error = true;
    }

    if (wA != wB || kA != kB)
    {
        printf("\nERROR : Niezgodne wymiary macierzy!");
        error = true;
    }
    return error;
}

double wypisz(double M[max][max], int w, int k)
{

    for (int i = 0; i < w; i++)
    {

        for (int j = 0; j < k; j++)
        {

            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
}
double suma(double A[max][max], double B[max][max], double C[max][max], int w, int k)
{
    

}
double różnica(double A[max][max], double B[max][max], double C[max][max], int w, int k)
{
}

int main()

{
    int wA = 2;
    int kA = 6;
    int wB = 2;
    int kB = 6;
    double A[max][max] = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14}};
    double B[max][max] = {
        {2, 4, 6, 8, 10, 12, 14},
        {1, 3, 5, 7, 9, 11, 13}};
    double C[max][max];
    if (!sprawdz_wymiar(wA, wB, kA, kB))
    {
        printf("Macierz A to:\n");
        wypisz(A, wA, kA);
        printf("Macierz B to:\n");
        wypisz(B, wB, kB);
    }
    return 0;
}