#include <iostream>
#include "text.h"

int main()
{
    Text text;
    std::string fileName = "text.txt";
    text.decode(fileName);
    text.print();
    return 0;
}
