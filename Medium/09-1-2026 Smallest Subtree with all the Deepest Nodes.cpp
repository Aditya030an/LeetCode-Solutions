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

//  by dfs
class Solution {
    int maxDepth =0;
    TreeNode* lca = NULL;
    int dfs(TreeNode* root , int depth){
        maxDepth = max(maxDepth , depth);
        if(!root) return depth;
        int l = dfs(root->left , depth+1);
        int r = dfs(root->right , depth+1);
        if(l == maxDepth && r == maxDepth) lca = root;
        return max(l , r);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            dfs(root , 0);
            return lca;
    }
};


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


// by bfs + dfs
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {


        if(!root) return nullptr;

        unordered_map<TreeNode* , TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> lastLevel;

        while(!q.empty()){
            int size = q.size();
            lastLevel.clear();

            for(int i =0 ; i<size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                lastLevel.push_back(temp);

                if(temp->left){
                    parent[temp->left] = temp;
                    q.push(temp->left);
                }

                if(temp->right){
                    parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }

        unordered_set<TreeNode*> deepest(lastLevel.begin() , lastLevel.end());

        while(deepest.size() > 1){
            unordered_set<TreeNode*> next;
            for(auto node : deepest){
                next.insert(parent[node]);
            }
            deepest = next;
        }

        return *deepest.begin();
    }
};