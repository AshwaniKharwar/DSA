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

bool identicalTree(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL && r2 != NULL) return false;
    if(r1 != NULL && r2 == NULL) return false;

    bool left = identicalTree(r1->left, r2->left);
    bool right = identicalTree(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    Node* root1 = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root2 = createTree();

    cout<<"\n";

    cout<< "tree is indetical or not " <<identicalTree(root1, root2)<<"\n";

    
    
}

