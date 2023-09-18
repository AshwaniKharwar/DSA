#include<iostream>
#include<vector>
using namespace std;

void dfs(int n, vector<int>edges[], int node, int visited[], vector<int>&ans){
  visited[node] = 1;
  ans.push_back(node);

  // call for all other nodes
  for(auto it:edges[node]){
    if(!visited[it]){
      dfs(n, edges, it, visited, ans);
    }
  }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int> edges[e];
    for(int i=0; i<e; i++){
      int u,v;
      cin>>u>>v;

      // for undirected graph
      // edges[u].push_back(v);
      // edges[v].push_back(u);

      // for directed graph
      edges[u].push_back(v);

    }
    // visited
    int visited[n] = {0};
    // starting index
    int start = 0;
    // ans list
    vector<int>ans;
    dfs(n, edges, start, visited, ans);

    for(auto it:ans){
      cout<<it<<", ";
    }

}
