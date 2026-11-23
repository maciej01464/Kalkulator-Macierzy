#ifndef MATRIX_H
#define MATRIX_H
#define max 20
int sprawdz_wymiar_DiO(int wA, int wB, int kA, int kB);
int sprawdz_wymiar_M(int kA, int wB);
void suma(double A[max][max], double B[max][max], double C[max][max], int w, int k);
void roznica(double A[max][max], double B[max][max], double C[max][max], int w, int k);
void mnozenie(double A[max][max], double B[max][max], double C[max][max], int wA, int kA, int kB);
#endif