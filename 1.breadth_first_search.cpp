// including files
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map <int , vector<int> > adj;
    int len = edges.size();
    for(int i=0;i<len;i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    vector<int> bfs;
    unordered_map<int, bool> isVisited;

    for(int i=0;i<vertex;i++)
    {
        if(!isVisited[i]){
            queue<int> myQue;
            myQue.push(i);
            isVisited[i] = true;

            while(!myQue.empty())
            {
                int temp = myQue.front();
                bfs.push_back(temp);
                myQue.pop();

                for(auto j: adj[temp])
                {
                    if(!isVisited[j])
                    {
                        isVisited[j] = true;
                        myQue.push(j);
                    }
                }
            }
        }
    }

    return bfs;

}

int main()
{
    int vertex = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    vector<int> bfs = BFS(vertex, edges);

    for(auto i: bfs)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
