#include "vector.h"

template <class T>
class Matrix : public Vector<Vector<T>>{
public:
    using Vector<Vector<T>>::operator[];//как другим способом? Конструктор перемешения?

    Matrix(size_t n, bool flag = false) : Vector<Vector<T>>(n){
        if (flag){
            for (size_t i = 0; i < n; i++){
                this->_array[i] = Vector<T>(n, i);
            }
        }
        else{
            for (size_t i = 0; i < n; i++){
                this->_array[i] = Vector<T>(n);
            }
        }
    }

    Matrix(const Matrix& mt) : Vector<Vector<T>>(mt){

    }

    Matrix(const Vector<Vector<T>>& mt) : Vector<Vector<T>>(mt){

    }

    Matrix& operator=(const Matrix& mt){
        return Vector<Vector<T>>::operator=(mt);
    }

    Matrix operator*(const Matrix& mt){
        if (this->_size != mt.Getize()){
            throw "6";
        }
        Matrix res = Matrix(this->_size);
        for (int i = 0; i < this->_size; i++){
            for (int j = 0; j < this->_size; j++){
                for (int k = 0; k < this->_size; k++){
                    int IndexArray = this->_array[i].GetSizeIndex();
                    int IndexMt = mt._array[k].GetSizeIndex();
                    if ((IndexArray > k) || (IndexMt > j)){
                        res[i][j] += 0;
                        continue;
                    }
                    res[i][j] += this->_array[i][k] * mt._array[k][j];
                }
            }
        }
        return res; 
    }

    friend std::ostream& operator<<(std::ostream& ostr, Matrix& tmp){
        for (int i = 0; i < tmp._size; i++){
            std::cout<<tmp[i];
        }
        return ostr;
    }

    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }

    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }

    Matrix Transposition(){
        Matrix m(this->_size);
        for (int i = 0; i < this->_size; i++){
            for (int j = 0; j < this->_size; j++){
                if (this->_array[j].GetSizeIndex() > i){
                    m[i][j] = 0;
                }
                else{
                    int a = this->_array[j][i];
                    m[i][j] = this->_array[j][i];
                }
            }
        }
        return m;
    }
    
};