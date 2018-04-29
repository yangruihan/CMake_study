#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TutorialConfig.h"
#include "include/mmath.h"

int main(int argc, char* argv[])
{
    std::cout 
    << "Hello World" << std::endl;
    std::cout << "Major version number: " << Tutorial_VERSION_MAJOR << std::endl;
    std::cout << "Minor version number: " << Tutorial_VERSION_MINOR << std::endl;

#ifdef USE_MMATH
    std::cout << "1 + 2 = " << mmath::add(1, 2) << std::endl;
#endif

#if defined (HAVE_LOG) && defined (HAVE_EXP)
    std::cout << exp(log(4) * 0.5) << std::endl;
#endif

    return 0;
}
