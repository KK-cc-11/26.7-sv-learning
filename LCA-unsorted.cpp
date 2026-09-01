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
        return makeNewNode(add);
    if(parent->left == NULL)
        parent->left = insert(parent->left, add);
    else
        parent->right = insert(parent->right, add);
    return parent;
}

Node *findLCA(Node *root, int val1,int val2){
    if(root == NULL || root->data == val1 || root->data == val2)
        return root;
    Node *left_lca = findLCA(root->left, val1, val2);
    Node *right_lca = findLCA(root->right, val1, val2);
    if(left_lca != NULL && right_lca != NULL){
        return root;
    }
    return (left_lca != NULL) ? left_lca : right_lca;
}