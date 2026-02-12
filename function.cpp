#include <iostream>
#include <ctime>

void happyBirthday(std::string name);

int main() {

    std::string name = "Bro";
    happyBirthday(name);
    return 0;
}

void happyBirthday(std::string name) {
    std::cout << "Happy Birthday " << name << '\n';
    std::cout << "Happy Birthday " << name << '\n';
    std::cout << "Happy Birthday dear " << name << '\n';
    std::cout << "Happy Birthday " << name << '\n';
}