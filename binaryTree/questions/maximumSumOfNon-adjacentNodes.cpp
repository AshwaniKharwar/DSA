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

pair<int,int> solve(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> result;
    result.first = root->data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);
    return result;

}

int maximumSumOfAdjancentNonNodes(Node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    int ans = maximumSumOfAdjancentNonNodes(root);
    cout<<"\n"<<ans<<"\n";


}