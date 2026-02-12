#include <iostream>
#include <stack>
using namespace std;

void printStackElements(stack<int> stack) {
    while (!stack.empty()) {
        cout<<stack.top()<<endl;
        stack.pop();
    }
}

int main()
{   // empty, size, push, pop, top
    stack<int>numberStack;

    numberStack.push(1);
    numberStack.push(2);
    numberStack.push(3);

    
    printStackElements(numberStack);

    // if(numberStack.empty())
    //     cout << "Stack is empty"<< endl;
    // else   
    //     cout << "Not empty"<< endl;

    // cout << "Stack size is "<< numberStack.size() << endl;

}