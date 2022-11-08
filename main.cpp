#include <iostream>
#include "S21Matrix.h"


int main() {
    S21Matrix a {3, 3};
    S21Matrix b {3, 3};
    S21Matrix c {3, 3};

    a.AddMatrix(a, 2.0);
    b.AddMatrix(b, 5.0);

    a.Printmatrix(a);

    std::cout << '\n';
    b.Printmatrix(b);

    a.SumMatrix(b);
    std::cout << '\n';
    a.Printmatrix(a);

    std::cout << '\n';
    b.Printmatrix(b);


    a + b;
    c = a;
    std::cout << '\n';
    a.Printmatrix(a);

    std::cout << '\n';
    b.Printmatrix(b);


    std::cout << '\n';
    c.Printmatrix(c);
    return 0;
}
