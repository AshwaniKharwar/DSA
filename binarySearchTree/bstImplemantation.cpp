#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if( data > root->data){
        root->right = insertInBST(root->right, data);
    }
    else{
        root->left = insertInBST(root->left, data);
    }

    return root;
}

void buildBST(Node* &root){
    int d;
    cout<<"Enter data for root node "<<"\n";
    cin>>d;
    while(d != -1){
        root = insertInBST(root,d);
        cin>>d;
    }
}

void levelOrderTravesal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node* deleteFromBST(Node* root, int key){
    if(root == NULL)
        return root;

    if(root->data == key){
        
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;

        }
    }
    else if(root->data > key){
        root->left = deleteFromBST(root->left, key);
        return root;
    }
    else {
        root->right = deleteFromBST(root->right, key);
        return root;
    }
    
}

void preOrder(Node *root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL) return ;

    inOrder(root->left);
    cout<<root->data <<" ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root == NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root =  NULL;

    buildBST(root);
    // 10 8 21 7 27 5 4 3 -1
    cout<<"printing BST "<<"\n";
    levelOrderTravesal(root);
    cout<<"Print preOrder "<<"\n";
    preOrder(root);cout<<"\n";
    inOrder(root);cout<<"\n";

    root = deleteFromBST(root, 3);
    cout<<"printing BST "<<"\n";
    levelOrderTravesal(root);cout<<"\n";
    cout<<"Print preOrder "<<"\n";
    preOrder(root);cout<<"\n";
    inOrder(root);



}