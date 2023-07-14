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

void solve(Node* root, vector<int> &ans, int lvl){
    if(root == NULL){
        return ;
    }

    if(lvl == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right, ans, lvl+1);
    solve(root->left, ans, lvl+1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root,ans,0);

    return ans;
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout<<"\n";
    vector<int> ans = leftView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";

}