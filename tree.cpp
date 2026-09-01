#include<bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *makeNewNode(int newData){
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *parent, int add){
    if(parent == NULL)
        parent = makeNewNode(add);
    else if(add>=parent->data)
        parent->right = insert(parent->right, add);
    else
        parent->left = insert(parent->left, add);
    return parent;
}

bool search(Node *parent, int key){
    if(parent == NULL)
        return false;
    else if (parent->data == key) 
        return true;
    else if(parent->data<key)
        return search(parent->right, key);
    else
        return search(parent->left, key);
}

void printTree(Node *root){
    cout << root->data << " ";
    if(root->left !=NULL)
        printTree(root->left);
    if(root->right !=NULL)
        printTree(root->right);
}

int main(){
    int a, n;
    Node *root;
    root = NULL;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a;
        root = insert(root, a);
    }
    printTree(root);
}