#include<bits/stdc++.h>
#include "implemantationOfTree.cpp"
using namespace std;

void preOrder(Node *root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    preOrder(root);
}