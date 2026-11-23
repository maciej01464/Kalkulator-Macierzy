#ifndef MATRIX_IO_H
#define MATRIX_IO_H
#define max 20
#include <stdio.h>
void wypisz_do_pliku(FILE *f, double M[max][max], int w, int k);
int wczytaj(char *sciezka, double M[max][max], int *w, int *k);
#endif