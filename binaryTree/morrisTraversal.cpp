#include<bits/stdc++.h>
#include "implemantationOfTree.cpp"
using namespace std;


// void morrisTraversal(Node* root){
//     if(root == NULL) return;
//     while(root != NULL){
//         if(root->left == NULL){
//             cout<<root->data<<" ";
//             root = root->right;
//         }
//         else{
//             Node* current = root->left;
//             while(current->right && current->right != root){
//                 current = current->right;
//             }

//             if(current->right == root){
//                 current->right = NULL;
//                 root = root->right;
//             }
//             else{
//                 cout<<root->data<<" ";
//                 current->right = root;
//                 root = root->left;
//             }
//         }
//     }
// }


// for inOrder Traversal
void morrisTraversal(Node* root){
    Node *current, *predecessor;

    if(root == NULL) return ;

    current = root;
    while(current != NULL){

        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
                predecessor->right = current;
                current = current->left;
            }
            else{
                predecessor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    } 
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    morrisTraversal(root);
}