#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#pragma pack(push, 1)
class MatrixPack {
    int data[100];
    int size;
    int count;
    int rows;
    int cols;
};
#pragma pack(pop)

class Matrix {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int size;
    int count;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int r, int c, int defaultValue = 0);
    Matrix(const Matrix& other);
    Matrix(const std::string& str);

    int getRows() const;
    int getCols() const;
    int getSize() const; 
    int getCount() const;
    int getElement(int r, int c) const;
    void setElement(int r, int c, int value);

    int norm() const;

    operator std::string() const;

    Matrix& operator=(const Matrix& other);
    Matrix& operator++();    
    Matrix operator++(int);  
    Matrix& operator--();    
    Matrix operator--(int);  

    int* operator[](int index);
    const int* operator[](int index) const;

    
    friend Matrix operator*(const Matrix& m, int scalar);
    friend Matrix operator*(int scalar, const Matrix& m);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
    friend bool operator!=(const Matrix& m1, const Matrix& m2);
    friend bool operator<(const Matrix& m1, const Matrix& m2); // порівняння за нормою

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};

#endif 