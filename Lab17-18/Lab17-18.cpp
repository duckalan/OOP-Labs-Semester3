#include "String.h"
#include "Matrix.h"
#include <windows.h>
#include <fcntl.h>
#include <io.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    String s1("������1");
    String s2 = "������2";

    std::cout << s1 << " " << s2 << '\n';
    std::cout << s1 << " == " << s2 << " = " << (s1 == s2) << '\n';
    std::cout << s1 << " + " << s2 << " = " << (s1 + s2) << '\n';

    const size_t rowsCount = 4;
    const size_t colsCount = 4;

    Matrix m1(rowsCount, colsCount);
    Matrix m2(rowsCount, colsCount);

    srand((unsigned int)time(0));

    for (size_t i = 0; i < rowsCount; i++)
    {
        for (size_t j = 0; j < colsCount; j++)
        {
            m1(i, j) = rand() % 20 - 10;
            m2(i, j) = rand() % 10 - 5;
        }
    }

    std::cout << "m1:\n";
    m1.Print();

    std::cout << "!m1:\n";
    (!m1).Print();

    std::cout << "m1 % 4:\n";
    (m1 % 4).Print();

    std::cout << "m2:\n";
    m2.Print();

    std::cout << "m1 & m2:\n";
    (m1 & m2).Print();

    std::cout << "m1 + m2:\n";
    (m1 + m2).Print();

    std::cout << "m1 * m2:\n";
    (m1 * m2).Print();

    std::cout << "m1 / m2:\n";
    (m1 / m2).Print();

    (m1 * 1.2f).Print();
    Matrix m3 = m1 * .5f - m2;

    std::cout << "m3:\n";
    m3.Print();

    system("pause");
}

/*
����������� �������� ^, ������� ��������� ������������ ����� ���� ������

int x = mat1 ^ mat2;
*/

/*
������� �������� !, ������� ���������� ����������������� �������
�������� �������� & ������� ���������� ��������� ������������� ��������� ���� ������
�������� �������� % ������� ���������� ������������ ��������� ������� �� �������

*/

