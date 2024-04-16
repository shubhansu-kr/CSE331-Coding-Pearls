// Check if graph is Eulerain

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int u) {
        vis[u] = true;
        for(int i = 0; i < graph[u].size(); ++i){
            if(!vis[graph[u][i]]) dfs(graph, vis, graph[u][i]);
        }
    }
    int isEulerian(vector<vector<int>> &graph){
        vector<bool> visited(graph.size(), false);
        int v = -1;
        for(int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() > 0) {
                v = i;
                break;
            }
        }
        if (v == -1) return 0;
        dfs(graph, visited, v);
        for(int i = 0; i < graph.size(); ++i) {
            if (!visited[i] && graph[i].size() > 0){
                return 0;
            }
        }
        int oddCount = 0;
        for(int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() % 2){
                ++oddCount;
            }
        }
        if (oddCount == 0) return 1;
        if (oddCount == 2) return 2;
        return 0; 
    }
};

void addEdge(vector<vector<int>> &graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main () {
    int vertices;
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>());
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);

    cout << isEulerian(graph);
    return 0;
}