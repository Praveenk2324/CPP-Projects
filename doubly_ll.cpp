#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* previous;

};

void printForward(Node*head){
    Node* traverser = head;
    while(traverser != nullptr){
        cout << traverser->value << endl;
        traverser = traverser->next;
    }
}

void printBackwards(Node*tail){
    Node* traverser = tail;
    while(traverser != nullptr){
        cout << traverser->value << endl;
        traverser = traverser->previous;
    }
}

int main() {
    Node* head;
    Node* tail;

    Node* node = new Node;
    node->value = 4;
    node->next = nullptr;
    node->previous = nullptr;
    head = node;
    tail = node;

    node = new Node();
    node->value = 1;
    node->next =nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    node = new Node();
    node->value = 2;
    node->next =nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    node = new Node();
    node->value = 3;
    node->next =nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    printBackwards(tail);






}