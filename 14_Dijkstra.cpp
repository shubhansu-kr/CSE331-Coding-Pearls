// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
    }

    int minIndex(vector<bool> &vis, vector<int> &dis){
        int minDis = INT_MAX, index = -1;
        for(int i = 0; i < vis.size(); ++i) {
            if (!vis[i]){
                if (dis[i] < minDis) {
                    minDis = dis[i];
                    index = i;
                }
            }
        }
        return i;
    }

    vector<int> dijkstra(vector<vector<int>> &graph, int source) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> distance(n, INT_MAX);

        distance[source] = 0;
        for(int i = 0; i < n-1; ++i) {
            int u = minIndex(visited, distance);
            visited[u] = true;
            for(int v = 0; v < n; ++v) {
                if (graph[u][v]) {
                    // There is an edge between u and v;
                    distance[v] = min(distance[v], distance[u] + graph[u][v]);
                }
            }
        }

        return distance;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends