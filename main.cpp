#include "s21_matrix_oop.h"

int main() {
    S21Matrix matrixA(1, 1);
    S21Matrix matrixB(1, 1);

    matrixA(0, 0) = 1.25;

    matrixA.Printmatrix();
    matrixA.InverseMatrix();
    matrixA.Printmatrix();
//    std:: cout << matrixA.EqMatrix(matrixB) << std::endl;


    return 0;
}


