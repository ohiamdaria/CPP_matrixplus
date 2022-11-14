#include <iostream>
#include "S21Matrix.h"


int main() {
    S21Matrix m(5, 3);
    S21Matrix n;

    m.AddMatrix(2);
    m.s21SetCols(7);
    m.Printmatrix();
    std::cout << '\n';
    m.s21SetRows(2);
    m.Printmatrix();

    return 0;
}
