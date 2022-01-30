all:MatrixMultipication run

MatrixMultipication:	main.o	matrixoperations.o
	gcc	main.o	matrixoperations.o	-o MatrixMultipication

main.o:main.c
	gcc -c	main.c
matrixoperations.o:	matrixoperations.c	matrixoperations.h
	gcc	-c	matrixoperations.c
clean:
	del	*.o MatrixMultipication.exe
run:
	MatrixMultipication.exe