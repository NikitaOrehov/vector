#include <iostream>

template <class T>
class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t size = 10, size_t startIndex = 0):_size(size), _startIndex(startIndex){
        if (_size == 0){
            throw "2";
        }
        if (_startIndex >= _size)
            throw "1";
        _size = size;
        _startIndex = startIndex;
        _array = new T[_size - startIndex];
        for (int i = 0; i < _size - _startIndex; i++){
            _array[i] = {};
        }
    }

    Vector(const Vector& tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        _array = new T[_size - _startIndex];
        for (int i = 0; i < _size - _startIndex; i++){
            _array[i] = tmp._array[i];
        }
    }

    // Vector(Vector&& moved) : _size(moved._size), _startIndex(moved._startIndex) {
    //     _array = moved._array;
    // }

    ~Vector() {
        delete [] _array;
    } 


    size_t Getize() const{
        return _size;
    }

    size_t GetSizeIndex() const{
        return _startIndex;
    }

    T& At(size_t pos){
        if (pos < _startIndex || pos >= _startIndex + _size) {
            throw std::out_of_range("Индекс вне допустимого диапазона.");
        }
        return _array[pos - _startIndex];
    }

    T& operator[](size_t pos){
        return _array[pos - _startIndex];
    }

    Vector& operator=(const Vector& tmp){
        if (this == &tmp) {
            return *this;
        }
        if (_size != tmp._size){
            T* p = new T[tmp._size - tmp._startIndex];
            delete _array;
            _array = p;
        }
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        for (size_t i = 0; i < _size - _startIndex; ++i) {
                _array[i] = tmp._array[i];
        }
        return *this;
    } 

    // Vector& operator=(const Vector&& tmp){
    //     _size = tmp._size;
    //     _startIndex = tmp._startIndex;
    //     delete [] _array;
    //     _array = tmp._array;
    //     return *this;
    // }

    Vector operator+(const T& tmp) const {
        Vector result(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] + tmp;
        }
        return result;
    }

    Vector operator-(const T& tmp) const {
        Vector result(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] - tmp;
        }
        return result;
    }

    Vector operator+(const Vector& tmp) const {
        if (_size != tmp._size ){
            throw "4";
        }

        if(_startIndex == tmp._startIndex){
            Vector v = Vector(_size, _startIndex);
            for (int i = 0; i < _size - _startIndex; i++){
                v[i] = _array[i] + tmp._array[i];
            }
            return v;
        }
        else if (_startIndex > tmp._startIndex){
            Vector v = Vector(_size, tmp._startIndex);
            for (int i = 0; i < _startIndex - tmp._startIndex; i++){
                v[i] = tmp._array[i];
            }
            for (int i = _startIndex - tmp._startIndex; i < _size - tmp._startIndex; i++){
                v[i] = _array[i - _startIndex - tmp._startIndex] + tmp._array[i];
            }
            return v;
        }
        else{
            Vector v = Vector(_size, _startIndex);
            for (int i = 0; i < tmp._startIndex - _startIndex; i++){
                v[i] = _array[i];
            }
            for (int i = tmp._startIndex - _startIndex; i < _size - _startIndex; i++){
                v[i] = _array[i] + tmp._array[i - tmp._startIndex - _startIndex];
            }
            return v;
        }
    }

    Vector operator-(const Vector& tmp) const{
        if (_size != tmp._size ){
            throw "4";
        }

        if(_startIndex == tmp._startIndex){
            Vector v = Vector(_size, _startIndex);
            for (int i = 0; i < _size - _startIndex; i++){
                v[i] = _array[i] - tmp._array[i];
            }
            return v;
        }
        else if (_startIndex > tmp._startIndex){
            Vector v = Vector(_size, tmp._startIndex);
            for (int i = 0; i < _startIndex - tmp._startIndex; i++){
                v[i] = tmp._array[i] * (-1);
            }
            for (int i = _startIndex - tmp._startIndex; i < _size - tmp._startIndex; i++){
                v[i] = _array[i - _startIndex - tmp._startIndex] - tmp._array[i];
            }
            return v;
        }
        else{
            Vector v = Vector(_size, _startIndex);
            for (int i = 0; i < tmp._startIndex - _startIndex; i++){
                v[i] = _array[i];
            }
            for (int i = tmp._startIndex - _startIndex; i < _size - _startIndex; i++){
                v[i] = _array[i] - tmp._array[i - tmp._startIndex - _startIndex];
            }
            return v;
        }
    }

    T operator*(const Vector tmp){
        if (_size != tmp._size || _startIndex != tmp._startIndex) {
            throw std::invalid_argument("Несовместимые размеры векторов.");
        }
        T sum = 0;
        for (size_t i = 0; i < _size; ++i) {
            sum += _array[i] * tmp._array[i];
        }
        return sum;
    }

    Vector operator*(int elem){
        Vector v = Vector(*this);
        for (int i = 0; i < _size; i++){
            _array[i] *= elem;
        }
        return v;
    }

    friend std::ostream& operator<<(std::ostream& ostr, Vector& v){
        for (int i = 0; i < v._startIndex; i++){
            std::cout<<"0 ";
        }
        for (int i = 0; i < v._size - v._startIndex; i++){
            std::cout<<v._array[i]<<" ";
        }
        std::cout<<"\n";
        return ostr;
    }
};