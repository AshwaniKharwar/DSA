#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
template <typename T>

class graph{
public:
    unordered_map<T,list<T>>adj;

    void addEdge(T u, T v, bool direction){
        // direction=0 undirected graph
        // direction = 1 directed graph

        // create edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    int m;
    cout<<"Enter number of edges: ";
    cin>>m;

    graph<int> g;

    int d;
    cout<<"enter 0 for indirected and 1 for directed";
    cin>>d;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,d);
    }

    g.printGraph();
}