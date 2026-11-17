#include <stdio.h>
#include <stdbool.h>
#define max 20

int sprawdz_wymiar_DiO(int wA, int wB, int kA, int kB)
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
int sprawdz_wymiar_M(int wA, int wB, int kA, int kB)
{

    bool error = false;
    if (kA != wB || kB != wA)
    {
        printf("\nERROR : Niezgodne wymiary macierzy dla mnożenia!");
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
    for (int i = 0; i < w; i++)
    {

        for (int j = 0; j < k; j++)
        {

            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
double różnica(double A[max][max], double B[max][max], double C[max][max], int w, int k)
{
    for (int i = 0; i < w; i++)
    {

        for (int j = 0; j < k; j++)
        {

            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

double mnożenie(double A[max][max], double B[max][max], double C[max][max], int wA, int kA, int kB)
{
    double suma;
    for (int i = 0; i < wA; i++)
    {

        for (int j = 0; j < kB; j++)
        {

            for (int n = 0; n < kA; n++)
            {
                suma = suma + A[i][n] * B[n][j];
            }
            C[i][j] = suma;
        }
    }
}
void ZczytywanieiZapis()
{
    FILE *f;
    FILE *f1;
    FILE *f2;
    int wA, kA, wB, kB;

    f = fopen("C:\\Users\\macie\\Desktop\\A.txt", "r");
    if (f == NULL)
    {
        printf("Blad: nie mozna otworzyc pliku\n");
        return 1;
    }
    else if (fscanf(f, "%d %d", &wA, &kA) != 2)
    {
        printf("Blad: brak wymiarow\n");
        fclose(f);
        return 1;
    }
    else{
    f2 = fopen("C:\\Users\\macie\\Desktop\\C.txt", "w");
    fprintf(f2,"%d", );
    fclose(f);
    }
    f1 = fopen("C:\\Users\\macie\\Desktop\\B.txt", "r");
     if (f1 == NULL)
    {
        printf("Blad: nie mozna otworzyc pliku\n");
        return 1;
    }
    if (fscanf(f1, "%d %d", &wB, &kB) != 2)
    {
        printf("Blad: brak wymiarow\n");
        fclose(f1);
        return 1;
    }
    
    printf("Wymiary B: %d x %d\n", wB, kB);
    fclose(f1);

}

int main()

{
    int w, k;
    /* int wA = 2;
     int kA = 3;
     int wB = 3;
     int kB = 2; */
    double A[max][max] = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14}};
    double B[max][max] = {
        {2, 4, 6, 8, 10, 12, 14},
        {1, 3, 5, 7, 9, 11, 13}};
    double C[max][max];
    /*   if (!sprawdz_wymiar_DiO(wA, wB, kA, kB))
       {
           printf("Macierz A to:\n");
           wypisz(A, wA, kA);
           printf("Macierz B to:\n");
           wypisz(B, wB, kB);
           suma(A, B, C, wA, kA);
           printf("Suma macierzy A i B to:\n");
           wypisz(C, wA, kA);
           różnica(A, B, C, wA, kA);
           printf("Różnica macierzy A i B to:\n");
           wypisz(C, wA, kA);
       }
       if (!sprawdz_wymiar_M(wA, wB, kA, kB))
       {
           mnożenie(A, B, C, wA, kA, kB);
           printf("Iloczyn macierzy A i B to:\n");
           wypisz(C, wA, kB);
       }

   */
    ZczytywanieiZapis();
    
    return 0;
}