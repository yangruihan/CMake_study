#include <iostream>

#include "TutorialConfig.h"
#include "include/mmath.h"

int main()
{
    std::cout 
    << "Hello World" << std::endl;
    std::cout << "Major version number: " << Tutorial_VERSION_MAJOR << std::endl;
    std::cout << "Minor version number: " << Tutorial_VERSION_MINOR << std::endl;

#ifdef USE_MMATH
    std::cout << "1 + 2 = " << mmath::add(1, 2) << std::endl;
#endif

    return 0;
}