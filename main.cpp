#include <iostream>
#include "S21Matrix.h"


int main() {
    S21Matrix a {3, 3};
    S21Matrix b {2, 2};
    S21Matrix c {3, 3};

    a.AddMatrix(a, 2);
    b.AddMatrix(b, 6);

    try
    {
        bool res = a.EqMatrix(b);
        std::cout << res;
    }
    catch (const char* msg)
    {
        std::cout << msg;
    }

    return 0;
}
