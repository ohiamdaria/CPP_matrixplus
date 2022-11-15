#include <iostream>
#include "S21Matrix.h"


int main() {
//    try {
//        S21Matrix m{-1, 3};
//    }
//    catch (const std::out_of_range& oor) {
//        std::cout << "Caught: " << oor.what() << std::endl;
//    }

    S21Matrix m{1, 3};
    S21Matrix n;
    n = m;
    n.Printmatrix();
    std::cout << std::endl;
    m.Printmatrix();
    return 0;
}
