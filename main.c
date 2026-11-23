#include <stdio.h>
#include "matrix.h"
#include "matrix_io.h"

#define SCIEZKA_A     "C:\\Users\\macie\\Desktop\\Studia\\C_Projekt\\A.txt"
#define SCIEZKA_B     "C:\\Users\\macie\\Desktop\\Studia\\C_Projekt\\B.txt"
#define SCIEZKA_WYNIK "C:\\Users\\macie\\Desktop\\Studia\\C_Projekt\\Wynik.txt"

int main()
{
    double A[max][max], B[max][max], C[max][max];
    int wA, kA, wB, kB;
    int wC, kC;
    int wybor;

    if (wczytaj(SCIEZKA_A, A, &wA, &kA) !=0)
        return 1;
    printf("Wczytano macierz A z pliku.\n");

    if (wczytaj(SCIEZKA_B, B, &wB, &kB)!= 0)
        return 1;
    printf("Wczytano macierz B z pliku.\n");

    printf("\nWybierz dzialanie:\n");
    printf("1 - Dodawanie \n");
    printf("2 - Odejmowanie \n");
    printf("3 - Mnozenie\n");
    printf("Twoj wybor: ");
    if (scanf("%d", &wybor) != 1)
    {
        printf("ERROR : Niepoprawny wybor!\n");
        return 1;
    }

    switch (wybor)
    {
    case 1:
        if (sprawdz_wymiar_DiO(wA, wB, kA, kB)!= 0)
            return 1;
        suma(A, B, C, wA, kA);
        wC = wA;
        kC = kA;
        break;
    case 2:
        if (sprawdz_wymiar_DiO(wA, wB, kA, kB)!=0)
            return 1;
        roznica(A, B, C, wA, kA);
        wC = wA;
        kC = kA;
        break;
    case 3:
        if (sprawdz_wymiar_M(kA, wB)!=0)
            return 1;
        mnozenie(A, B, C, wA, kA, kB);
        wC = wA;
        kC = kB;
        break;
    default:
        printf("ERROR : Nieznane dzialanie!\n");
        return 1;
    }

    FILE *f = fopen(SCIEZKA_WYNIK, "w");
    if (f == NULL)
    {
        printf("ERROR : Nie mozna utworzyc pliku Wynik.txt\n");
        return 1;
    }
    wypisz_do_pliku(f, C, wC, kC);
    fclose(f);

    printf("Wynik zapisano do pliku Wynik.txt.\n");
    return 0;
}