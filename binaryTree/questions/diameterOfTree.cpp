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

pair<int,int> fastDiameter(Node* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = fastDiameter(root->left);
        pair<int,int> right = fastDiameter(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans ;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
}

int diameter(Node* root){
    return fastDiameter(root).first;
}



int main(){

    Node* root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    int ans = diameter(root);
    cout<<"\n";
    cout<<"Diameter of tree is "<<ans<<"\n";
    
}

