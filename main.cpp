#include <format>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#ifdef HAVE_POW
    #include <math.h>
#else
    #include "math/math_functions.h"
#endif

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << std::format(
            "{} version: {}.{}\n",
            argv[0],
            learning_cmake_VERSION_MAJOR,
            learning_cmake_VERSION_MINOR);
        std::cout << std::format("Usage: {} base exponent\n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    double exponent = atoi(argv[2]);

#ifdef HAVE_POW
    std::cout << "Now we use the standard library\n";
    double result = pow(base, exponent);
#else
    std::cout << "Now we use our own Math Library\n";
    double result = power(base, exponent);
#endif
    std::cout << std::format("{} ^ {} is {}\n", base, exponent, result);
    return 0;
}
