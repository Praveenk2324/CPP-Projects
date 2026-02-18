#include <iostream>

int main() {
    long standard = __cplusplus;

    #ifdef _MSVC_LANG
        // MSVC defaults __cplusplus to 199711L unless /Zc:__cplusplus is set
        // So we check _MSVC_LANG if available
        standard = _MSVC_LANG;
    #endif

    if (standard == 202302L) std::cout << "C++23";
    else if (standard == 202002L) std::cout << "C++20";
    else if (standard == 201703L) std::cout << "C++17";
    else if (standard == 201402L) std::cout << "C++14";
    else if (standard == 201103L) std::cout << "C++11";
    else if (standard == 199711L) std::cout << "C++98";
    else std::cout << "Pre-standard C++";

    std::cout << " (" << standard << "L)" << std::endl;
    return 0;
}