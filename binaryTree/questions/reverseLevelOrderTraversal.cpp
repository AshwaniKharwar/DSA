#include<bits/stdc++.h>
#include<stack>
#include<queue>
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


vector<int> reverseLevelOrderTraversal(Node* root){
    queue<Node*> q;
    stack<Node*> st;
    vector<int>ans;

    q.push(root);
    while(!q.empty()){
        Node* root = q.front();
        q.pop();
        st.push(root);

        if(root->left){
            q.push(root->left);
        }
        if(root->right){
            q.push(root->right);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top()->data);
        st.pop();
    }
    return ans;
}


int main(){

    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     vector<int> ans = reverseLevelOrderTraversal(root);

     for(auto it:ans){
        cout<<it<<" ";
     }
}

