#include "String.h"
#include "Matrix.h"

int main()
{
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

    std::cout << "m2:\n";
    m2.Print();

    std::cout << "m1 + m2:\n";
    (m1 + m2).Print();

    std::cout << "m1 * m2:\n";
    (m1 * m2).Print();

    std::cout << "m1 / m2:\n";
    (m1 / m2).Print();

    Matrix m3 = m1 * .5f - m2;

    std::cout << "m3:\n";
    m3.Print();

    system("pause");
}