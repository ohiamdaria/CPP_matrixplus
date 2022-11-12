#include <iostream>
#include "S21Matrix.h"


int main() {
    S21Matrix a {2, 3};

    a.AddMatrix(2);
    S21Matrix b;

    b = a.S21Resize(4, 4);
    b.Printmatrix();

//    try {
//        a.CalcComplements();
//    }
//    catch (const char*msg) {
//        std::cout<<msg;
//    }
//    S21Matrix b {a};
//    b.Printmatrix();

    return 0;
}
