#include "s21_matrix_oop.h"

int main() {
    S21Matrix m{4, 5};
    m.AddMatrix(4.5);
    m.Printmatrix();

    std::cout << std::endl;
    S21Matrix n;
    n = m;
    m.Printmatrix();
    m.S21Resize(6, 6);
    std::cout << std::endl;
    n.Printmatrix();
    std::cout << std::endl;
    m.AddMatrix(666);
    m.Printmatrix();
    n = m;
    std::cout << std::endl;
    n.Printmatrix();
    std::cout << std::endl;


    return 0;
}