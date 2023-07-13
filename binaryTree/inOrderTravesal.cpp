#include<bits/stdc++.h>
#include "implemantationOfTree.cpp"
using namespace std;

void inOrder(Node* root){
    if(root == NULL) return ;

    inOrder(root->left);
    cout<<root->data <<" ";
    inOrder(root->right);
}


int main()
{
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    inOrder(root);
}