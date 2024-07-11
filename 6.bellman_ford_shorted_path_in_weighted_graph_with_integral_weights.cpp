#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth relaxation to check negative cycle
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return { -1};
        }
    }


    return dist;
}


int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 4}, {2, 3, 1}, {3, 4, 3}, {0, 4, 7}};
    int src = 0;
    vector<int> dis = bellman_ford(n, edges, src);

    for (auto i : dis)
    {
        cout << i << " ";
    }
    return 0;
}