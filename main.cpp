#include <iostream>
#include "Matrix.h"

int main() {
    Vector<int> v1(3);
    v1[0] = 3;
    Vector<int> v2(3, 1);
    v2[1] = 5;
    Vector<int> v3(3, 0);
    v3[0] = 1;
    v3 = v1 + v2;
    std::cout<<v1<<v2<<v3<<"\n";
    Matrix<int> m1(3, 1);
    m1[0][1] = 1;
    m1[0][2] = 2;
    m1[1][1] = 3;
    std::cout<<m1<<"\n";
    Matrix<int> m2(3, 1);
    m2[0][1] = 4;
    m2[0][2] = 5;
    m2[1][1] = 6;
    std::cout<<m2;
    Matrix<int> m3 = m1 * m2;
    std::cout<<"\n"<<m3;
    Matrix<int> m4 = m2.Transposition();
    std::cout<<"\n"<<m4;
}