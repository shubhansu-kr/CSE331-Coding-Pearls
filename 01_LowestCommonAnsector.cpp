// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Find Path
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
};

class SolutionDiff {
    // Modified question to Find the LCA of a bst
public:
    TreeNode* lowestCommonAncestorOfBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;

        if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

int main () {
    
    return 0;
}