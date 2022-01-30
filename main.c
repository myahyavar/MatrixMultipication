/*
* @file main.c
* @description Matrix Multipication
* @assignment Project 1
* @date 21.12.2021
* @author Muhammed Yahya Avar muhammed.avar@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include "matrixoperations.h"
#include "time.h"

int main(int argc, char **argv)
{
    int **matrix1,**matrix2;
    int n1,n2,type,seed;

    puts("Length of the first matrix..");
    scanf("%d", &n1);
    puts("Length of the second matrix..");
    scanf("%d", &n2);
    puts("Multipication type..");
    scanf("%d", &type);
    puts("Seed value for randomizing..");
    scanf("%d", &seed);
    puts("***********************");

    int c=0;
    c=check(n1,n2,type);

    if (c==1)
    {
        puts("Wrong array input.");
        return 0;
    }
    
    matrix1 = createMatrix(n1);
    fillMatrix(matrix1, n1,seed);
    puts("First Matrix");
    printMatrix(matrix1, n1);

    matrix2 = createMatrix(n2);
    fillMatrix(matrix2, n2,seed);
    puts("Second Matrix");
    printMatrix(matrix2, n2);

    int **matrix3 = multiply(matrix1, matrix2, n1, n2, type);
    int n3 = matrixLength(n1, n2, type);
    puts("Result Matrix");
    printMatrix(matrix3, n3);

    freeArray(matrix1, n1);
    freeArray(matrix2, n2);
    freeArray(matrix3, n3);
}