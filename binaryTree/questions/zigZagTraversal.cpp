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

vector<int> zigZag(Node* root){
    vector<int>result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            int index = leftToRight?i:size-i-1;
            ans[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }
    }

    return result;
}


int main(){

    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans = zigZag(root);
    cout<<"\n";

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<"\n";
   
    
    
}

