// Bell Man Ford

#include <bits/stdc++.h>
using namespace std ;

struct edge{
    int src, dst, wt;
} edges[8];

int v = 6, cnt = 0; 

void addEdge(int u, int v, int wt) {
    edges[cnt].src = u;
    edges[cnt].dst = v;
    edges[cnt++].wt = wt;
}

void bellManFord(int src) {
    int distance[v];
    for(int i = 0; i < v; ++i) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0;
    for(int i = 0; i < v-1; ++i) {
        for(int j = 0; j < 8; ++j) {
            int u = edges[j].src;
            int v = edges[j].dst;
            int wt = edges[j].wt;
            if (distance[u] != INT_MAX && distance[v] > distance[u]+wt){
                distance[v] = distance[u] + wt;
            }
        }
    }
    for(int j = 0; j < 8; ++j) {
        int u = edges[j].src;
        int v = edges[j].dst;
        int wt = edges[j].wt;
        if (distance[u] != INT_MAX && distance[v] > distance[u]+wt){
            cout << "Negative edge cycle exists.";
            return;
        }
    }

    for(int i = 0; i < v; ++i) {
        cout << distance[i] << " ";
    }
    cout << endl;

    return;
}

int main() {
    addEdge(0, 1, 10);
    addEdge(0, 5, 8);
    addEdge(1, 2, 2);
    addEdge(3, 1 ,2);
    addEdge(3, 2, -2);
    addEdge(4, 1, -4);
    addEdge(5, 4, 1);
    addEdge(4, 3, -1);

    bellManFord(0);

    return 0;
}
