#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
{
    
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> distance(n,INT_MAX);
    
    pq.push({0,S});
    distance[S] = 0;
    
    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();
        int dist = front.first;
        int vertex = front.second;
            
        for(auto i: adj[vertex]){
            int neighbor = i[0];
            int weight = i[1];
            
            if(distance[vertex]+weight < distance[neighbor]){
                pq.push({distance[vertex]+weight,neighbor});
                distance[neighbor] = distance[vertex]+weight;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(distance[i]==INT_MAX){
            distance[i] = -1;
        }
    }
    
    return distance;
    
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
    
    vector<int> dis = dijkstra(n,adj,0);
    
    for(auto i: dis){
        cout<<i<<" ";
    }
    return 0;
}