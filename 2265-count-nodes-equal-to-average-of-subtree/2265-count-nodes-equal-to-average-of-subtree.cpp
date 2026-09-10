/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int ans = 0;

private:
    // sum numberOfElements
    pair<int, int> helper(TreeNode* root) {
        if (root == nullptr)
            return{0, 0};
        pair<int, int> leftData = helper(root->left);
        pair<int, int> rightData = helper(root->right);
        int currentSum = leftData.first + rightData.first + root->val;
        int totElements = leftData.second + rightData.second + 1;
        if (currentSum / totElements == root->val)
            ans++;
        return {currentSum, totElements};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};