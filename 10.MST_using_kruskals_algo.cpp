#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

int findParent(vector<int> &parent,int x){
    if(parent[x]!=x)
    parent[x] = findParent(parent,parent[x]);
    
    return parent[x];
}

void unio(vector<int> &parent,vector<int> &rank,int x,int y){
    int parentX = findParent(parent,x);
    int parentY = findParent(parent,y);
    
    if(rank[parentX] < rank[parentY]){
        parent[parentX] = parentY;
    }
    else if(rank[parentX] > rank[parentY]){
        parent[parentY] = parentX;
    }
    else {
        parent[parentX] = parentY;
        rank[parentX]++;
    }
    
    return ;
}

bool isSameSet(vector<int> &parent,int x,int y){
    int parentX = findParent(parent,x);
    int parentY = findParent(parent,y);
    
    return parentX == parentY;
}


int spanningTree(int n, vector<vector<int>> adj[])
{
    priority_queue< pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
    int mstWeight=0;
    
    for(int i=0;i<n;i++){
        for(auto j: adj[i]){
            pq.push({j[1],{i,j[0]}});
        }
    }
    
    vector<int> rank(n,0);
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    
    
    
    
    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();
        
        if(!isSameSet(parent,front.second.first,front.second.second)){
            unio(parent,rank,front.second.first,front.second.second);
            mstWeight += front.first;
        }
    }
    
    return mstWeight;
    
}

int main()
{
    int n = 5;
    vector<vector<int>> adj[n];
    adj[0].push_back({1,2});
    adj[1].push_back({2,4});
    adj[2].push_back({3,1});
    adj[3].push_back({4,3});
    adj[0].push_back({4,7});
    
    cout<<spanningTree(n,adj);
    return 0;
}