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

void solve(Node* root, int k, int &count, vector<int> path){
    if(root == NULL){
        return ;
    }

    path.push_back(root->data);
    solve(root->left, k, count, path);
    solve(root->right, k, count, path);
    int sum =0;
    for(int i=path.size()-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }

    path.pop_back();
}

int kSumPaths(Node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    int ans = kSumPaths(root,7);
    cout<<"\n"<<ans<<"\n";


}