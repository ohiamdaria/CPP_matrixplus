#include "s21_matrix_oop.h"

int main() {
    S21Matrix m {3, 3};

    S21Matrix n = std::move(m);


    return 0;
}