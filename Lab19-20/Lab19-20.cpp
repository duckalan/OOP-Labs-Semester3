#include <iostream>

#include "Memory.h"

int main()
{
    Memory mem("Dtr");

    mem.SetInputValues(1, 0, 0, 0);
    mem.CalculateState();

    mem.SetInputValues(0, 1, 1, 0);
    mem.CalculateState();
    
    system("pause");
}