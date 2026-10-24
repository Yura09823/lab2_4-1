#include "Matrix.h"
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

Matrix::Matrix() : size(MAX_SIZE), count(0), rows(0), cols(0) {
    for (int i = 0; i < MAX_SIZE; ++i) data[i] = 0;
}

Matrix::Matrix(int r, int c, int defaultValue) : size(MAX_SIZE) {
    if (r <= 0 || c <= 0 || r * c > MAX_SIZE) {
        std::cout << "Помилка: Некоректні розміри!" << std::endl;
        exit(1); 
    }
    rows = r;
    cols = c;
    count = r * c;
    for (int i = 0; i < MAX_SIZE; ++i) {
        data[i] = (i < count) ? defaultValue : 0;
    }
}

Matrix::Matrix(const Matrix& other) {
    size = other.size;
    count = other.count;
    rows = other.rows;
    cols = other.cols;
    for (int i = 0; i < MAX_SIZE; ++i) data[i] = other.data[i];
}

Matrix::Matrix(const std::string& str) : size(MAX_SIZE), count(0), rows(0), cols(0) {
    std::stringstream ss(str);
    int val;
    while (ss >> val && count < MAX_SIZE) {
        data[count++] = val;
    }
    rows = 1;
    cols = count;
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }
int Matrix::getSize() const { return size; }
int Matrix::getCount() const { return count; }

int Matrix::getElement(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        std::cout << "Помилка: Індекс поза межами!" << std::endl;
        return 0;
    }
    return data[r * cols + c];
}

void Matrix::setElement(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        std::cout << "Помилка: Індекс поза межами!" << std::endl;
        return; 
    }
    data[r * cols + c] = value;
}

int Matrix::norm() const {
    if (count == 0) return 0;
    int minVal = data[0], maxVal = data[0];
    for (int i = 1; i < count; ++i) {
        if (data[i] < minVal) minVal = data[i];
        if (data[i] > maxVal) maxVal = data[i];
    }
    return std::abs(maxVal - minVal);
}

Matrix::operator std::string() const {
    std::stringstream ss;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ss << data[i * cols + j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        count = other.count;
        for (int i = 0; i < count; ++i) data[i] = other.data[i];
    }
    return *this;
}

Matrix& Matrix::operator++() {
    for (int i = 0; i < count; ++i) ++data[i];
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp = *this;
    ++(*this);
    return temp;
}

Matrix& Matrix::operator--() {
    for (int i = 0; i < count; ++i) --data[i];
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp = *this;
    --(*this);
    return temp;
}

int* Matrix::operator[](int index) {
    if (index < 0 || index >= rows) {
        std::cout << "Помилка: Індекс рядка поза межами!" << std::endl;
        exit(1); 
    }
    return &data[index * cols];
}

const int* Matrix::operator[](int index) const {
    if (index < 0 || index >= rows) {
        std::cout << "Помилка: Індекс рядка поза межами!" << std::endl;
        exit(1);
    }
    return &data[index * cols];
}

Matrix operator*(const Matrix& m, int scalar) {
    Matrix res = m;
    for (int i = 0; i < res.count; ++i) res.data[i] *= scalar;
    return res;
}

Matrix operator*(int scalar, const Matrix& m) {
    return m * scalar;
}

bool operator==(const Matrix& m1, const Matrix& m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) return false;
    for (int i = 0; i < m1.count; ++i) {
        if (m1.data[i] != m2.data[i]) return false;
    }
    return true;
}

bool operator!=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}

bool operator<(const Matrix& m1, const Matrix& m2) {
    return m1.norm() < m2.norm();
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            os << m.data[i * m.cols + j] << "\t";
        }
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m) {
    for (int i = 0; i < m.count; ++i) {
        is >> m.data[i];
    }
    return is;
}