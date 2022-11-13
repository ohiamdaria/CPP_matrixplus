#include <iostream>
#include "S21Matrix.h"


int main() {

    S21Matrix a {2, 3};
    S21Matrix c {2, 3};
    a.AddMatrix(2);
    a.Printmatrix();
    c.AddMatrix(4);
    c.Printmatrix();
    S21Matrix b {a * 1.0};
    b.Printmatrix();

    b.S21Resize(5, 5);
    b.Printmatrix();


    return 0;
}
