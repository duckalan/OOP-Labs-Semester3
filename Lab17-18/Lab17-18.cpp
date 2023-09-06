#include <iostream>
#include "String.h"
#include "Matrix.h"

int main()
{

    String* s = new String("aab");
    String s2 = *s;

    std::cout << *s << "\n";

    system("pause");
}