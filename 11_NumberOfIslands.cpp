// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // DFS Solution
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        vector<int> shiftCol = {0, +1, 0, -1}, shiftRow = {-1, 0, +1, 0};

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                if (grid[i][j] == '1') {
                    ++count;

                    // Start BFS From (i, j);
                    int row = i, col = j;
                    stack<pair<int, int>> s;
                    s.push({row, col});
                    grid[row][col] = '2';
                    while(!s.empty()) {
                        pair<int, int> p = s.top();
                        s.pop();

                        row = p.first, col = p.second;
                        for(int k = 0; k < 4; ++k) {
                            int newRow = row + shiftRow[k];
                            int newCol = col + shiftCol[k];

                            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) {
                                // Invalid index
                                continue;
                            }

                            if (grid[newRow][newCol] == '1') {
                                s.push({newRow, newCol});
                                grid[newRow][newCol] = '2';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

class Solution {
    // BFS Solution
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        vector<int> shiftCol = {0, +1, 0, -1}, shiftRow = {-1, 0, +1, 0};

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                if (grid[i][j] == '1') {
                    ++count;

                    // Start BFS From (i, j);
                    int row = i, col = j;
                    queue<pair<int, int>> q;
                    q.push({row, col});
                    grid[row][col] = '2';
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();

                        row = p.first, col = p.second;
                        for(int k = 0; k < 4; ++k) {
                            int newRow = row + shiftRow[k];
                            int newCol = col + shiftCol[k];

                            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) {
                                // Invalid index
                                continue;
                            }

                            if (grid[newRow][newCol] == '1') {
                                q.push({newRow, newCol});
                                grid[newRow][newCol] = '2';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main () {
    
    return 0;
}