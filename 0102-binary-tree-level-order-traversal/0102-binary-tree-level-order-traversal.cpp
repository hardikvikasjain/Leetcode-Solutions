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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == NULL)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            vector<int> level;

            for(int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Current node ki value level mein
                level.push_back(node->val);

                // Left child ko queue mein daalo
                if(node->left != NULL)
                    q.push(node->left);

                // Right child ko queue mein daalo
                if(node->right != NULL)
                    q.push(node->right);
            }

            // Pura current level answer mein
            ans.push_back(level);
        }

        return ans;
    }
};
/* 
while (!q.empty()) {

    int n = q.size();

    vector<int> level;

    for(int i = 0; i < n; i++) {

        // queue se node nikalo

        // node ki value level mein daalo

        // left child queue mein

        // right child queue mein
    }

    // level ko ans mein daalo
} 
*/