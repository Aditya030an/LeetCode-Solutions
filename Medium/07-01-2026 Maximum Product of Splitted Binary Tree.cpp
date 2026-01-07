class Solution {
public:
long long totalSum = 0 , maxProductSum =0 ;
const int MOD = 1e9 + 7;
    void getTotalSum(TreeNode* root){
        if(!root) return;
        totalSum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }
    long long dfs(TreeNode* root){
        if(!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = left + right + root->val;

        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProductSum = max(maxProductSum , product);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        getTotalSum(root);
        dfs(root);
        return maxProductSum % MOD;
    }
};