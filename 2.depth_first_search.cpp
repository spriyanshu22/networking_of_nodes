#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

void dfs(int vertex,vector<bool> &isVisited,vector<int>adj[]){
    isVisited[vertex] = true;
    cout << vertex << " ";
    
    for(auto i: adj[vertex]){
        if(isVisited[i] == false){
            dfs(i,isVisited,adj);
        }
    }
    
    return;
}

// driver code
int main()
{
    int n = 5;
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    
    vector<bool> isVisited(n,false);
    
    for(int i=0;i<n;i++){
        if(isVisited[i] == false){
            dfs(i,isVisited,adj);
        }
    }
    
    return 0;
}