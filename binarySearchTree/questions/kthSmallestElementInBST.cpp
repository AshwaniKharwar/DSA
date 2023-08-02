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

int solve(Node* root, int &i, int k){
    if(root == NULL)
        return -1;
    
    int left = solve(root->left, i, k);

    if(left != -1)
        return left;
    
    i++;
    if(i == k){
        return root->data;
    }

    return solve(root->right, i, k);
}

int kThSmallestElementInBST(Node* root, int k){
    int i=0;

    int ans = solve(root, i, k);
    return ans;
}

int main(){
    Node* root = NULL;
    buildBST(root);
    //  10 8 21 7 27 5 4 3 -1
    inOrder(root);
    cout<<"\n";

    int ans = kThSmallestElementInBST(root, 3);
    cout<<"Ans : "<<ans<<endl;


}