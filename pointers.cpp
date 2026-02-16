#include <iostream>
using namespace std;

int main (){
    int n = 9;

    cout << &n << endl;

    int * ptr = &n;

    cout << ptr << endl;
    cout << *ptr << endl;

    *ptr = 22;

    cout << *ptr << endl;
    

}