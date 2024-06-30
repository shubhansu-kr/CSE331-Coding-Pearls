vector<int> BFS(int stNode, vector<vector<int>> &list) {
    queue<int> q;
    q.push(stNode);

    int n = list.size();
    vector<int> v(n, 0), bfs;
    v[stNode] = 1;

    while (q.size()) {
        int node = q.front();
        bfs.emplace_back(node);

        for (auto &it: list[node]) {
            if (!v[it]) q.push(it), v[it] = 1;
        }
        q.pop();
    }
    return bfs;
}