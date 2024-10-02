/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int NOTBALANCED = -100;
class Solution
{
    int recurrsion(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = recurrsion(root->left);
        int r = recurrsion(root->right);
        if (l == NOTBALANCED || r == NOTBALANCED || abs(l - r) > 1)
            return NOTBALANCED;
        return max(l, r) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        int ans = recurrsion(root);
        if (ans == NOTBALANCED)
            return false;
        return true;
    }
};
// @lc code=end
