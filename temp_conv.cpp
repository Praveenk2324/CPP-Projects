#include <iostream>
#include <cmath>

int main(){

    double temp;
    char unit;

    std::cout << "************** Temp Conv *********************\n";

    std::cout << "F = Fahrenheit\n";
    std::cout << "C = Celsius\n";
    std::cout << "Select Unit: ";
    std::cin >> unit;

    if(unit == 'F' || unit =='f'){
        std::cout << "Enter Celsius: ";
        std::cin >> temp;

        temp = (1.8 * temp) + 32;
        std::cout << "Temp is :"<<temp<<"F\n";

    }
    else if(unit == 'C' || unit =='c'){
        std::cout << "Enter Fahrenheit: ";
        std::cin >> temp;

        temp = (temp-32)/1.8;;
        std::cout << "Temp is :"<<temp<<"F\n";
    }
    else{
        std::cout << "Invalid Input";
    }

    std::cout  << "**********************************************";

    return 0;
}