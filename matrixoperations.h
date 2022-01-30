/*
* @file matrixoperations.h
* @description Matrix Multipication
* @assignment Project 1
* @date 21.12.2021
* @author Muhammed Yahya Avar muhammed.avar@stu.fsm.edu.tr
*/
#define MATRIXOPERATIONS_C 
int check(int n1, int n2, int type);
int **createMatrix(int n);
void fillMatrix(int **d, int n, int seed);
void printMatrix(int **d, int n);
void freeArray(int **d, int n);
int matrixLength(int n1, int n2, int type);
int **multiply(int **v1, int **v2, int n1, int n2, int type);

