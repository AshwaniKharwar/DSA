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

Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *ans = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            ans = front;
        }

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return ans;
}

int burningTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    int ans = 0;

    queue<Node *> q;
    map<Node *, bool> visited;

    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {

        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++)
        {

            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }

        if (flag)
        {
            ans++;
        }
    }

    return ans;
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createMapping(root, target, nodeToParent);
    int ans = burningTree(targetNode, nodeToParent);

    return ans;
}

int main()
{
    Node *root = createTree();
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    int ans = minTime(root, 11);
    cout<<"\n"<<ans<<"\n";
}