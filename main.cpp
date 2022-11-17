#include <iostream>
#include "S21Matrix.h"

 // --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no

int main() {
    S21Matrix m {8, 3};
    m.AddMatrix(2);
    //m.Printmatrix();
    std::cout << std::endl;
    S21Matrix  k (m);// constr copy
    k.Printmatrix();
    m.Printmatrix();
  ///  std::cout  << &k << std::endl;
   // std::cout  << &m << std::endl;
    //k.Printmatrix();
    std::cout << std::endl;
    //m.Printmatrix();
    std::cout << std::endl;

    m.AddMatrix(3);
    k.Printmatrix();
    std::cout << std::endl;
    //m.Printmatrix();
//    k.Printmatrix();













//    m.AddMatrix(3);
//
//    S21Matrix n = std::move(m);// constr move
//
//    k = n;
//    k.Printmatrix();.
//    std::cout << std::endl;
//    n.Printmatrix();
    return 0;
}
