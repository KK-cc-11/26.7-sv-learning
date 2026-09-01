#include<bits/stdc++.h>
using namespace std;
struct Node{
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
    else if (add >= parent->data)
        parent->left = insert(parent->left, add);
    else
        parent->right = insert(parent->right, add);
    return parent;
}

int LCA(Node *parent, int val1,int val2){
    while (parent->data>val1&&parent->data>val2)
    {
        parent = parent->right;
    }
    while (parent->data < val1 && parent->data < val2)
    {
        parent = parent->left;
    }
    return parent->data;
}

int main () {
    
    int a, n;
    Node * root;
    root = NULL;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> a;
        root = insert(root, a);
    }
    
    int v1, v2;
    cin >> v1 >> v2; // Values for LCA
    cout << LCA(root, v1, v2) << endl;
    
}