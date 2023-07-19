#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the data : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter for the left of " << data << endl;
    root->left = createTree();

    cout << "Enter for the right of " << data << endl;
    root->right = createTree();

    return root;
}

void flatten(Node *root)
{
    Node *curr = root;

    while (curr != NULL)
    {

        if (curr->left != NULL)
        {

            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->right);
}

int main()
{
    Node *root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    flatten(root);
    preOrder(root);

}