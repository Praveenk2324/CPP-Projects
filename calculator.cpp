#include <iostream>
#include <cmath>

int main(){
    
    double num1;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    double num2;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    char op;
    std::cout << "Enter operator: (+,-,*,/) ";
    std::cin >> op;
    double result;

    switch (op)
    {
    case '+':
        result =  num1 + num2;
        break;

    case '-':
         result = num1 - num2;
        break;
    
    case '*':
        result = num1 * num2;
        break;

    case '/':
        result = num1 / num2;
        break;
    
    // case '%':
    //     result = num1 % num2;
    //     break;
    
    default:
        std::cout << "Invalid Operator";
        return 0;
    }
std::cout << "Result: " << result;
   
}