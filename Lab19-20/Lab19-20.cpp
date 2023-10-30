#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>

#include "LogicalElement.h"
#include "Memory.h"
#include "Register.h"

void WorkWithLogicalElement() 
{
    std::cout << "Введите значения четырёх входов (0 или 1): \n";
    bool* input = new bool[4];

    for (size_t i = 0; i < 4; i++)
    {
        bool tempInput;
        std::cin >> tempInput;
        input[i] = tempInput;
    }

    LogicalElement le("AND", 4);
    le.SetInputValues(input);
    std::cout << "Результат И = " << le.CalculateOutput() << '\n';
    delete[] input;
}

void WorkWithMemory() 
{
    Memory dTrigger;

    dTrigger.SetInputValues(1, 0, 0, 0);
    dTrigger.CalculateState();
    std::cout << "Текущее состояние прямого выхода триггера: " << dTrigger.GetStraightOutput() << '\n';

    std::cout << "Введите значения входов D-триггера через пробел в порядке: R D C S: \n";
    int r, d, c, s;
    std::cin >> r >> d >> c >> s;

    dTrigger.SetInputValues(r, d, c, s);
    dTrigger.CalculateState();
    std::cout << "Вычисленное состояние прямого выхода триггера: " << dTrigger.GetStraightOutput() << '\n';
}


void WorkWithRegister() 
{
    Register reg("Reg");

    /*
        1,0,0,0,  1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0,
        1,0,0,0,  1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0
    */
    int** testInput = new int* [Register::MemorySize];
    for (size_t i = 0; i < Register::MemorySize; i++)
    {
        testInput[i] = new int[Memory::InputCount];
        testInput[i][0] = 1;
        testInput[i][1] = 0;
        testInput[i][2] = 0;
        testInput[i][3] = 0;
    }

    reg.SetInputValues(testInput);
    reg.CalculateState();

    std::cout << "Изначальное состояние триггера: ";
    for (size_t i = 0; i < Register::MemorySize; i++)
    {
        std::cout << reg.CheckStraightOutput(i);
    }
    std::cout << '\n';

    /*
        0,1,1,0,  0,1,1,0, 1,0,0,0, 1,0,0,0, 1,0,0,0,
        1,0,0,0,  1,0,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0
    */
    testInput[0][0] = 0;
    testInput[0][1] = 1;
    testInput[0][2] = 1;
    testInput[0][3] = 0;

    testInput[1][0] = 0;
    testInput[1][1] = 1;
    testInput[1][2] = 1;
    testInput[1][3] = 0;

    reg.SetInputValues(testInput);
    reg.CalculateState();

    std::cout << "Изменённое состояние триггера: ";
    for (size_t i = 0; i < Register::MemorySize; i++)
    {
        std::cout << reg.CheckStraightOutput(i);
    }
    std::cout << '\n';

    for (size_t i = 0; i < Register::MemorySize; i++)
    {
        delete[] testInput[i];
    }
    delete[] testInput;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    //WorkWithLogicalElement();
    //WorkWithMemory();
    WorkWithRegister();
    
    system("pause");
}