#include <iostream>

#include "LogicalElement.h"

int main()
{
    auto a = LogicalElement::OutputCount;
    LogicalElement el("A", 1);
    LogicalElement el2(el);

    system("pause");
}