#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

int timer = 0;
int mainRoot = 0;
int mainRootChildren= 0;

void dfs(int vertex,vector<bool> &isVisited,vector<int> &parent,vector<int> &dfn,vector<int> &low,vector<int> &articulationPoints,vector<int>adj[]){
    isVisited[vertex] = true;
    dfn[vertex] = low[vertex] = timer++;
    
    bool isArticulationPoint = false;
    
    for(auto i: adj[vertex]){
        if(isVisited[i] == true && parent[vertex]==i)
        continue;
        else if(isVisited[i] == false){
            dfs(i,isVisited,parent,dfn,low,articulationPoints,adj);
            low[vertex] = min(low[vertex],low[i]);
            
            if(low[i] >= dfn[vertex])
            isArticulationPoint = true;
            
            if(vertex == mainRoot)
            mainRootChildren ++;
        }
        else if(isVisited[i] == true){
            low[vertex] = min(low[vertex],dfn[i]);
        }
    }
    
    if(isArticulationPoint == true && vertex != mainRoot)
    articulationPoints.push_back(vertex);
    
    return;
}

vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector<int> parent(n,-1);
    vector<int> dfn(n);
    vector<int> low(n);
    vector<bool> isVisited(n,false);
    vector<int> articulationPoints;
    
    dfs(mainRoot,isVisited,parent,dfn,low,articulationPoints,adj);
    
    if(mainRootChildren > 1)
    articulationPoints.push_back(mainRoot);
    
    if(articulationPoints.size() == 0)
    return {-1};
    
    sort(articulationPoints.begin(),articulationPoints.end());
    return articulationPoints;
}


// driver code
int main()
{
    int n = 5;
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    vector<int> ans = articulationPoints(n,adj);
    
    for(auto i: ans)
    cout << i << " ";
    
    return 0;
}