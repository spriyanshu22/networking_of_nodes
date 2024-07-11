#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

int timer = 0;
int dfs(int vertex,vector<int> &parent,vector<int> &low,vector<int> &dfn,vector<bool> &isVisited,vector<vector<int> > &adj,vector<vector<int> > &bridges){
    isVisited[vertex] = true;
    dfn[vertex] = timer++;
    low[vertex] = dfn[vertex];


    for(auto i: adj[vertex]){
        if(isVisited[i] && parent[vertex]==i)
        continue;
        else if(isVisited[i]){
            low[vertex] = min(low[vertex],low[i]);
        }
        else {
            parent[i] = vertex;
            int childLow = dfs(i,parent,low,dfn,isVisited,adj,bridges);

            low[vertex] = min(low[vertex],childLow);
            
            if(childLow > dfn[vertex])
            bridges.push_back({vertex,i});
        }
    }

    return low[vertex];

}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>  >adj(n);
    for(auto i :connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> parent(n,-1);
    vector<int> low(n,INT_MAX);
    vector<int> dfn(n);
    vector<bool> isVisited(n,false);
    vector<vector<int> > bridges;

    dfs(0,parent,low,dfn,isVisited,adj,bridges);

    return bridges;
}

// driver code
int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> bridges = criticalConnections(n,connections);

    for(auto i: bridges)
    {
        cout << i[0] << " " << i[1] << endl;
    }

    return 0;
}