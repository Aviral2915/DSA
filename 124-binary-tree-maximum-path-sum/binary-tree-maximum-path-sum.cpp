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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Step 1
        findMaxPathSum(root, maxi); // Step 2
        return maxi;
    }
private:
    int findMaxPathSum(TreeNode* node, int& maxi) {
        if (!node) return 0; 
        int leftSum = std::max(0, findMaxPathSum(node->left, maxi));
        int rightSum = std::max(0, findMaxPathSum(node->right, maxi));
        maxi = std::max(maxi, leftSum + rightSum + node->val);
        return node->val + std::max(leftSum, rightSum);
    }
};
