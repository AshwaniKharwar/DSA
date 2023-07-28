#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if( data > root->data){
        root->right = insertInBST(root->right, data);
    }
    else{
        root->left = insertInBST(root->left, data);
    }

    return root;
}

void buildBST(Node* &root){
    int d;
    cout<<"Enter data for root node "<<"\n";
    cin>>d;
    while(d != -1){
        root = insertInBST(root,d);
        cin>>d;
    }
}

void inOrder(Node* root){
    if(root == NULL) return ;

    inOrder(root->left);
    cout<<root->data <<" ";
    inOrder(root->right);
}

bool isValidBST(Node* root, int min, int max){
    if(root == NULL) return true;

    if(root->data > min && root->data < max){
        bool left = isValidBST(root->left, min, root->data);
        bool right = isValidBST(root->right, root->data, max);
        return left && right;
    }
    else 
        return false;
}

bool isValid(Node* root){
    return isValidBST(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root = NULL;
    buildBST(root);
     // 10 8 21 7 27 5 4 3 -1

    inOrder(root);
    bool ans = isValid(root);
    cout<<"\n"<<ans<<"\n";

}