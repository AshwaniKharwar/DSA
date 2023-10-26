#include <iostream>
#include <vector>
using namespace std;

bool detect(pair<int, int> src, int vis[], vector<int> adj[])
{
    vis[src.first] = 1;

    for (auto it : adj[src.first])
    {
        if (!vis[it])
        {
            pair<int, int> i = {it, src.first};
            if (detect(i, vis, adj))
            {
                return true;
            }
        }
        else if (it != src.second)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{

    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            pair<int, int> src = {i, -1};
            if (detect(src, vis, adj))
            {
                return true;
            }
        }
    }
    return false;
}