#include<bits/stdc++.h>
#include "implemantationOfTree.cpp"

using namespace std;

void levelOrderTravesal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<" Level order Traversal "<<endl;
    levelOrderTravesal(root);
}