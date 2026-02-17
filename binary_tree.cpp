#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
//preorder(data, left, right)
//inorder(left, data, right)
//postorder(left, right, data)

void preOrder(Node* root) {  //RECURSIVE FUNCTION
    if (root == nullptr) return;

    cout<< root->data << ", " ;
    preOrder(root->left);
    preOrder(root->right);
   
}

void inOrder(Node* root) {  //RECURSIVE FUNCTION
    if (root == nullptr) return;
    
    inOrder(root->left);
    cout<< root->data << ", " ;
    inOrder(root->right);
}


int main(){
    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    preOrder(root);
    inOrder(root);

}