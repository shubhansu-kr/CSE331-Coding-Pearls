// Given a complete binary tree, fill the next pointer. Initially all the next pointers are null.

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *next) : val(x), left(left), right(right), next(next) {}
};

class Solution2 {
public:     
    void fillNext(TreeNode *root) {
        if (!root) return;

        if (root->left) root->left-next = root->right;
        if (root->next) root->right->next = root->next->left;

        fillNext(root->left);
        fillNext(root->right);
        return;
    }
};

class Solution1 {
    // Using DFS
public: 
    void link(TreeNode *left, TreeNode*right) {
        if (!left || !right) return;
        left->next = right;
        link(left->left, left->right);
        link(left-right, right->left);
        link(right->left, right->right);
        return;
    }
    void fillNext(TreeNode *root) {
        if (!root) return;
        link(root->left, root->right);
        return;
    }
};

class Solution {
public: 
    void fillNext(TreeNode *root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            q.push(nullptr);
            for(int i = 0; i < width; ++i){
                TreeNode *p = q.front();
                q.pop();
                p->next = q.front();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            q.pop();
        }
        return;
    }
};

int main () {
    
    return 0;
}