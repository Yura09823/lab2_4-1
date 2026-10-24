#include <iostream>
#include "Matrix.h"
#include <Windows.h>


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Розмір класу Matrix без #pragma pack(1): " << sizeof(Matrix) << " байт" << endl;
    cout << "Розмір структури MatrixPack з #pragma pack(1): " << sizeof(MatrixPack) << " байт" << endl;
    
    Matrix m1;
    cout << "m1 (за замовчуванням, size=" << m1.getSize() << "): \n" << m1 << endl;

    Matrix m2(2, 2, 5);
    cout << "m2 (2x2, заповнена 5): \n" << m2;

    Matrix m3("1 2 3 4 5");
    cout << "m3: \n" << m3;

    Matrix m4 = m2;
    cout << "m4 (копія m2): \n" << m4;

    m4[0][0] = 10;
    m4.setElement(1, 1, 15);
    cout << "m4 після зміни [0][0] та (1,1): \n" << m4;

    m4++;
    cout << "m4 після постфіксного інкременту (++): \n" << m4;
    --m4;
    cout << "m4 після префіксного декременту (--): \n" << m4;

    Matrix m5 = m4 * 2;
    cout << "m5 (m4 * 2): \n" << m5;

    cout << "Норма m4 (max - min): " << m4.norm() << endl;
    cout << "Норма m5 (max - min): " << m5.norm() << endl;

    cout << "m4 == m2 ? " << (m4 == m2 ? "Так" : "Ні") << endl;
    cout << "m4 < m5 (за нормою) ? " << (m4 < m5 ? "Так" : "Ні") << endl;

    string s = (string)m5;
    cout << "m5 у вигляді string: \n" << s;

    Matrix arr[3] = { Matrix(2, 2, 1), Matrix(2, 2, 2), Matrix(2, 2, 3) };
    cout << "\nЕлемент масиву arr[1]: \n" << arr[1];

    return 0;
}