// https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        color[0] = 0;
        for(int i = 0; i < n; ++i) {
            if (color[i] == 0);
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                for(int i = 0; i < graph[curr].size(); ++i) {
                    if (color[graph[curr][i]] == -1) {
                        color[graph[curr][i]] = !(color[curr]);
                        q.push(graph[curr][i]);
                    }
                    else {
                        if (color[graph[curr][i]] == color[curr]) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main () {
    
    return 0;
}