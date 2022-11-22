#include "s21_matrix_oop.h"
#include <cstring>

void S21Matrix::S21insertValues(int n, ...) {
    va_list arg_list;
    va_start(arg_list, n);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (i * cols_ + j < n) {
                this->matrix_[i][j] = va_arg(arg_list, double);
            } else {
                this->matrix_[i][j] = 0;
            }
        }
    }
    va_end(arg_list);
}


int main() {
    // S21Matrix n = std::move(m);
    S21Matrix a(3, 1), c(3, 2), d(3, 3);
    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    c.S21insertValues(9, 1., 2., 4., 5., 7., 8.);
    a.s21SetCols(2);
    a.Printmatrix();
    std::cout << a.s21GetCols() << endl;

//    c.S21insertValues(6, 1., 2., 4., 5., 7., 8.);
    c.Printmatrix();
    std::cout << endl;

    a.s21SetCols(3);
    d.S21insertValues(9, 1., 2., 0., 4., 5., 0., 7., 8., 0.);
    d.Printmatrix();
    std::cout << a.s21GetCols() << endl;
    a.Printmatrix();
    return 0;
}