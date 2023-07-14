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
 // iterative methed
vector<int> diagonalTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int, vector<int>> nodes;
    queue<pair<Node*, int> >q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        nodes[hd].push_back(frontNode->data);
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd+1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd));
        }

    }


    for(auto i: nodes){

        for(auto j: i.second){
            ans.push_back(j);
        }
    }

    return ans;
}

// recursive method

void solve(Node* root, map<int, vector<int> > &nodes, int hd){
    if(root == NULL){
        return;
    }
    nodes[hd].push_back(root->data);
    solve(root->left, nodes, hd+1);
    solve(root->right, nodes, hd);
}

vector<int> diagonalTraversalRecursive(Node* root){
    vector<int> ans;
    
    map<int,vector<int> > nodes;
    solve(root, nodes, 0);

    for(auto i:nodes){
        for(auto j:i.second){
            ans.push_back(j);
        }
    }

    return ans;
}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    cout<<"\n";
    vector<int> ans = diagonalTraversalRecursive(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";

}