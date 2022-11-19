#include "s21_matrix_oop.h"

int main() {
    S21Matrix m{4, 5};
    m.AddMatrix(4.5);
    m.Printmatrix();

    std::cout << std::endl;
    m.S21Resize(5, 1);
    m.Printmatrix();

    return 0;
}