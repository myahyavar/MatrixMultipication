/*
* @file matrixoperations.c
* @description Matrix Multipication
* @assignment Project 1
* @date 21.12.2021
* @author Muhammed Yahya Avar muhammed.avar@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include "matrixoperations.h"
#include "time.h" 

int check(int n1,int n2,int type){
    int wrong=0;
    if(n1%2==0 ||n2%2==0 || n1==n2 ||n2>n1 ||(n2!=5 && n2!=3) ||type>1 || type<0){
        wrong=1;

    }

    return wrong;
}

int **createMatrix(int n)
{

    int i;
    int **matrix = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        matrix[i] = malloc(n * sizeof(int));
    return matrix;
}

void fillMatrix(int **d, int n, int seed)
{
    int i, j;
    srand(seed);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            d[i][j] = (rand() % 10)+1;
}

void printMatrix(int **d, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", d[i][j]);
        }
        puts("");
    }
    puts("***********************");
}

void freeArray(int **d, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(d[i]);
    }

    free(d);
}

int matrixLength(int n1, int n2, int type)
{
    int L = 0;

    if (type == 0)
    {
        L = n1 - n2 + 1;
    }
    else if (type == 1)
    {
        L = n1;
    }

    return L;
}

int **multiply(int **v1, int **v2, int n1, int n2, int type)
{
    int i, j, m, n;

    int L = matrixLength(n1, n2,type);

    int **matrix1t;
    int tn = n1 + 2;

    if (type == 1)
    {
        matrix1t = createMatrix(n1 + 2);

        for (i = 0; i < tn; i++)
            for (j = 0; j < tn; j++)
                matrix1t[i][j] = 0;

        for (i = 0; i < n1; i++)
            for (j = 0; j < n1; j++)
                matrix1t[i + 1][j + 1] += v1[i][j];

        v1 = matrix1t;
        //printMatrix(v1, tn);
    }

    int **result = createMatrix(L);

    for (i = 0; i < L; i++)
        for (j = 0; j < L; j++)
            result[i][j] = 0;

    int t1 = -1;
    int t2 = -1;

    for (i = 0; i < L; i++)
    {
        t1++;
        if (t1 == L)
        {
            t1 = 0;
        }
        for (j = 0; j < L; j++)
        {
            t2++;
            if (t2 == L)
            {
                t2 = 0;
            }
            for (m = 0; m < n2; m++)
            {
                for (n = 0; n < n2; n++)
                {
                    result[i][j] += v1[m + t1][n + t2] * v2[m][n];
                }
            }
        }
    }

    return result;
}