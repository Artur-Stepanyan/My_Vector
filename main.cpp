#include <iostream>
#include "Vector.h"

int main()
{
    Vector obj1;
    obj1.push_back(3);
    obj1.push_back(4);
    obj1.push_back(5);
    obj1.insert(2, 8);
    obj1.insert(2, 9);
    obj1.pop();

    Vector obj2(5);
    //obj2 = obj1;

    std::cout << std::endl << obj1 << std::endl;
    std::cout << "obj1 size is: " << obj1.Size() << " \n";
    std::cout << "obj1 capacity is: " << obj1.Capacity() << " \n";

    std::cout <<  std::endl << obj2 << std::endl;
    std::cout << "obj2 size is: " << obj2.Size() << " \n";
    std::cout << "obj2 capacity is: " << obj2.Capacity() << " \n";

    std::cout << "4 in obj1 is in index: " << obj1.find_by_value(4) << "\n";

    return 0;
}