#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

bool dfs(int vertex,vector<int> &color,int currColor,vector<vector<int>>& adj){
    if(color[vertex]!=0)
    return  true;
    else color[vertex] = currColor;

    bool ans = true;

    for(auto i: adj[vertex]){
        if(color[i]==0){
            int counterColor = currColor == 1?2:1;
            ans = ans && dfs(i,color,counterColor,adj);
            
        }
        else if(color[i] == color[vertex])
        ans = false;
    }

    return ans;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n= graph.size();

    vector<int> color(n,0);
    int currColor = 1;

    for(int i=0;i<n;i++){
        if(color[i]==0){
            if(dfs(i,color,currColor,graph)==false)
            return false;
        }
    }

    return true;
}

// driver code
int main()
{
    // example 1
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << isBipartite(graph) << endl;

    // example 2
    vector<vector<int>> graph2 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << isBipartite(graph2) << endl;

    return 0;
}