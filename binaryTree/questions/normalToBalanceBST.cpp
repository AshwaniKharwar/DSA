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

void inOrder(Node* root, vector<int>&in){
    if(root == NULL)
        return ;
    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}

Node* inOrderToBST(int s, int e, vector<int> &in){
    if(s<e)
        return NULL;
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inOrderToBST(s,mid-1, in);
    root->right = inOrderToBST(mid+1,e,in);
    return root;
}

Node* normalToBalance(Node* root){
    vector<int> in;
    inOrder(root, in);
    return inOrderToBST(0,in.size()-1, in);
}

void inOrder(Node* root){
    if(root == NULL)
        return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    inOrder(root);
    cout<<"hello"<<endl;
    root = normalToBalance(root);
    inOrder(root);
    cout<<endl;


    

}