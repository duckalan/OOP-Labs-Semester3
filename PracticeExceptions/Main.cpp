#include <iostream>
#include "Queue.h"

// ОФОРМИТЬ КАК ПРАКТИЧЕСКУЮ РАБОТУ №2

void PrintMenu()
{
    std::cout 
        << "Выберите действие: \n"
        << "  1 - добавить элемент в очередь;\n"
        << "  2 - убрать элемент из очереди и вывести его;\n"
        << "  3 - вывести всю очередь;\n"
        << "  0 - выход из программы.\n";
}

int main()
{
    Queue<int, 3> queue;
    bool isContinue = true;
    int userChoise = 0;

    while (isContinue)
    {
        PrintMenu();
        std::cin >> userChoise;

        switch (userChoise)
        {
        // Добавить элемент в очередь
        case 1:
        {
            std::cout << "Введите элемент: ";
            int input = 0;
            std::cin >> input;

            try
            {
                queue.Enqueue(input);
            }
            catch (const std::runtime_error& e)
            {
                std::cout << e.what();
            }
            break;
        }
        // Убрать элемент из очереди и вывести его
        case 2:
            try
            {
                int output = queue.Dequeue();
                std::cout << "Извлечённый элемент: " << output << '\n';
            }
            catch (const std::runtime_error& e)
            {
                std::cout << e.what();
            }
            break;

        // Вывести всю очередь
        case 3:
            queue.PrintAll();
            break;

        // Выход из программы
        case 0:
            isContinue = false;
            break;

        default:
            break;
        }
        std::cout << '\n';
    }

    system("pause");
}
