struct ListNode {
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode *next):val(val), next(next){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 

vector<int> DFS(vector<vector<int>> &list, int stNode)
{
    vector<int> visited(list.size(), 0), traversal;
    solveDFS(visited, traversal, list, stNode);
    return traversal;
}
void solveDFS(vector<int> &visited, vector<int> &traversal, vector<vector<int>> &list, int node)
{

    traversal.emplace_back(node);
    visited[node] = 1;

    for (int i = 0; i < list[node].size(); ++i)
    {
        if (visited[list[node][i]])
            continue;
        else
            solveDFS(visited, traversal, list, list[node][i]);
    }
}

// 

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

// 

