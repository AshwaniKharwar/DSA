#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
         this->data = data;
         this->left = NULL;
         this->right = NULL; 
    }
};

Node *createTree()
{
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"Enter for the left of "<<data<<endl;
    root->left = createTree();

    cout<<"Enter for the right of "<<data<<endl;
    root->right = createTree();

    return root;

}

void preOrder(Node *root, int &count){
    if(root == NULL) return ;

    if(root->left == NULL && root->right == NULL){
        count++;
    }
    preOrder(root->left, count);
    preOrder(root->right, count);
}

int countLeafNode(Node* root){
    int count = 0;

    preOrder(root,count);

    return count;
}


int main(){

    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<endl;

    int ans = countLeafNode(root);
    cout<<" leaf node is "<<ans<<endl;

}