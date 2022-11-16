#include <iostream>
#include "S21Matrix.h"

 // --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no

int main() {
    S21Matrix m {8, 3};
    m.AddMatrix(5.0);
    m.Printmatrix();

//    S21Matrix n {m};
//    n.Printmatrix();


//    int i = 9;
//    n = m * 7;
//    n.Printmatrix();
//    std::cout << std::endl;
//    m.Printmatrix();
//    m = 8 * n;
//    std::cout << std::endl;
//    m.Printmatrix();
//    m.InverseMatrix();
    return 0;
}
