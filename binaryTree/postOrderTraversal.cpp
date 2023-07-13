#include<bits/stdc++.h>
#include "implemantationOfTree.cpp"
using namespace std;

void postOrder(Node *root){
    if(root == NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    postOrder(root);
}