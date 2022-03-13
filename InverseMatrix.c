#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ordo;

void augmentedMatriks(float matriks[][ordo + ordo]);
void konversiAugmentedToDiagonal(float matriks[][ordo + ordo]);
void diagonalSatu(float matriks[][ordo + ordo]);
void tampil(float matriks[][ordo + ordo]);

int main()
{

    printf("Masukkan Ordo Matriks : ");
    scanf("%d", &ordo);
    float matriks[ordo][ordo + ordo];
    printf("Masukkan Data Matriks ! \n");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            if (j == 0)
                printf("Matriks Baris ke-%d : \n", i + 1);
            printf("Matriks[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &matriks[i][j]);
        }
    }
    augmentedMatriks(matriks);
    // Menampilkan Setelah Matriks Ditambah Identitas
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo + ordo; j++)
        {
            printf("%g\t", matriks[i][j]);
            if (j == ordo - 1)
                printf("|\t");
        }
        puts("");
    }
    konversiAugmentedToDiagonal(matriks);
    diagonalSatu(matriks);
    tampil(matriks);
}

void augmentedMatriks(float matriks[][ordo + ordo])
{
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            if (j == i)
                matriks[i][ordo + j] = 1;
            else
                matriks[i][ordo + j] = 0;
        }
    }
}

void konversiAugmentedToDiagonal(float matriks[][ordo + ordo])
{
    {
        float rasio;
        int perubahan = 0;

        puts("\nPengkonversian Menjadi Matriks Diagonal");
        for (int i = 0; i < ordo; i++)
        {
            for (int j = 0; j < ordo; j++)
            {
                if (j != i)
                {
                    // Mengubah isi Matriks
                    rasio = matriks[j][i] / matriks[i][i];
                    perubahan++;
                    for (int k = 0; k < ordo + ordo; k++)
                    {
                        matriks[j][k] -= rasio * matriks[i][k];
                    }

                    // Hasil Perubahan Matriks
                    printf("Perubahan ke-%d\n", perubahan);
                    for (int x = 0; x < ordo; x++)
                    {
                        for (int y = 0; y < ordo + ordo; y++)
                        {
                            printf("%.3f\t", matriks[x][y]);
                            if (y == ordo - 1)
                                printf("|\t");
                        }
                        puts("");
                    }
                    puts("");
                }
            }
        }
    }
}

void diagonalSatu(float matriks[][ordo + ordo])
{
    int i, j;

    for (i = 0; i < ordo; i++)
    {
        for (j = ordo; j < ordo + ordo; j++)
        {
            matriks[i][j] = matriks[i][j] / matriks[i][i];
        }
        matriks[i][i] = matriks[i][i] / matriks[i][i];
    }
    printf("Matriks Terkini\n");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo + ordo; j++)
        {
            printf("%.3f\t", matriks[i][j]);
            if (j == ordo - 1)
                printf("|\t");
        }
        puts("");
    }
}

void tampil(float matriks[][ordo + ordo])
{
    puts("\nMatriks Invers");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = ordo; j < ordo + ordo; j++)
        {
            printf("%.3f\t", matriks[i][j]);
        }
        puts("");
    }
}