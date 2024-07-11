#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

// PRIMS ALGORITHM
int spanningTree(int n, vector<vector<int>> adj[])
{
    vector<bool> isCut(n,false);
    
    priority_queue< pair<int,int>, 
    vector< pair<int,int> >,
    greater< pair<int,int> > > pq;
    int mstWeight =0;
    
    
    for(auto i: adj[0]){
        pq.push({i[1],i[0]});
    }
    // auto front = pq.top();
    // pq.pop();
    isCut[0] = true;
    
            
    
    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();
        int node = front.second;
        int wt = front.first;
        
        if(!isCut[node]){
            isCut[node] = true;
            mstWeight+= wt;
            
            for(auto i: adj[node]){
                if(!isCut[i[0]])
                pq.push({i[1],i[0]});
            }
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