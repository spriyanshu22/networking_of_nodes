#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
    vector<int> dis(n,-1);
    queue<int> myQue;
    vector<vector<int> > adj(n);
    
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    myQue.push(src);
    dis[src] = 0;
    
    while(!myQue.empty()){
        int front = myQue.front();
        myQue.pop();
        
        for(auto i: adj[front]){
            if(dis[i]==-1){
                dis[i] = 1+dis[front];
                myQue.push(i);
            }
        }
    
    }
    
    return dis;
    
}

int main()
{
    int n = 5;
    int m = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    int src = 0;
    vector<int> dis = shortestPath(edges,n,m,src);
    
    for(auto i: dis)
    {
        cout << i << " ";
    }
    return 0;
}