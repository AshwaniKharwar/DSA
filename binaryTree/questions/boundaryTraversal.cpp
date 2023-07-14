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

void traverseLeft(Node* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return ;

    ans.push_back(root->data);

    if(root->left){
        traverseLeft(root->left, ans);
    }
    else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return ;

    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->data);

    // left traversal
    traverseLeft(root->left, ans);

    // leaf Node
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // right traversal
    traverseRight(root->right, ans);


    return ans;

}


int main(){

    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans = boundary(root);
    cout<<"\n";

    for(auto i: ans){
        cout<<i<<" ";
    }
   
    
}

