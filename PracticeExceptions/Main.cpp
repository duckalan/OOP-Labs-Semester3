#include <iostream>
#include "Queue.h"

int main()
{
    Queue<int, 3> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    
    q.PrintAll();
    
    try
    {
        q.Enqueue(4);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    
    q.Dequeue();
    q.PrintAll();
    
    q.Dequeue();
    q.PrintAll();
    
    q.Dequeue();
    // ТУТ ОШИБКА ОБРАЩЕНИЯ К NEXT == NULLPTR
    q.PrintAll();
    
    try
    {
        q.Dequeue();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what();
    }
}
