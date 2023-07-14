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

vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> nodes;
    queue<pair<Node*, int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        if(nodes.find(hd) == nodes.end()){
            nodes[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;

}

int main(){
    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    vector<int> ans = topView(root);
    cout<<"\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}