#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* Next;
};

void printList(Node*n) {
    while(n!=NULL){
        cout << n->value << endl;
        n=n->Next;
    }
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->Next = second;

    second->value = 2;
    second->Next = third;

    third->value = 3;
    third->Next = NULL;

    printList(head);

}