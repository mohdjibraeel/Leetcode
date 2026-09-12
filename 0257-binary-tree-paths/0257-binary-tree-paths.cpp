class Solution {
private:
    void helper(TreeNode* root, string currPath, vector<string>& result) {
        if (root == nullptr) {
            return;
        }

        currPath += to_string(root->val);

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(currPath);
            return;
        }

        currPath += "->";

        helper(root->left, currPath, result);
        helper(root->right, currPath, result);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper(root, "", result);
        return result;
    }
};