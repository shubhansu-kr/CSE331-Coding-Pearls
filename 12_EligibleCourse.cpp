// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        int count = numCourses;

        for(int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i][0]]++;
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {q.push(i); --count;};
        }

        while(!q.empty()) {
            int temp = q.front();
            q.pop();

            for(int i = 0; i < adjList[temp].size(); ++i) {
                inDegree[adjList[temp][i]]--;
                if (inDegree[adjList[temp][i]] == 0) {
                    q.push(adjList[temp][i]);
                    --count;
                }
            }
        }

        return count == 0;
    }
};

int main () {
    
    return 0;
}