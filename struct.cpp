#include<iostream>

struct Car{
    std::string model;
    int year;
    std::string color;
};
void printcar(Car car);
void paintcar(Car &car, std::string color);
int main()
{
    Car car1;
    Car car2;

    car1.model="BE 6";
    car1.year = 2025;
    car1.color = "Black";

    car2.model="Sierra";
    car2.year=2025;
    car2.color = "Green";

    paintcar(car1, "Red");

    printcar(car1);
    printcar(car2);
    return 0;

}

void printcar(Car car){
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';

}
void paintcar(Car &car, std::string color){
    car.color = color;
}