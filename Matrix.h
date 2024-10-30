#include "vector.h"

template <class T>
class Matrix : public Vector<Vector<T>>{
public:
    Matrix(size_t n) : Vector<Vector<T>>(n){
        for (size_t i = 0; i < n; i++){
            _array[i] = Vector<T>(n - i, i);
        }
    }
    Matrix(const Matrix& mt);
    Matrix(const Vector<Vector<T>>& mt);
    Matrix& operator=(const Matrix& mt);
    Matrix operator+(const Matrix& mt);
    Matrix operator-(const Matrix& mt);
    Matrix operator*(const Matrix& mt);
    
};