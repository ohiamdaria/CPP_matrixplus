#include <iostream>
#include "S21Matrix.h"


int main() {
    S21Matrix a {2, 3};

    a.AddMatrix(2);
    try {
        a.CalcComplements();
    }
    catch (const char*msg) {
        std::cout<<msg;
    }
//    S21Matrix b {a};
//    b.Printmatrix();

    return 0;
}
