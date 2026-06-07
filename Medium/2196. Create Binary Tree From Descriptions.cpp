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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;
        for (auto& arr : descriptions) {
            int parent = arr[0];
            int kimd = arr[1];
            int isLeft = arr[2];
            if (!mp.count(parent)) mp[parent] = new TreeNode(parent);
            if (!mp.count(kimd)) mp[kimd] = new TreeNode(kimd);
            if (isLeft) mp[parent]->left = mp[kimd];
            else mp[parent]->right = mp[kimd];
            child.insert(kimd);
        }
        for (auto& arr : descriptions) {
            if (!child.count(arr[0])) return mp[arr[0]];
        }
        return nullptr;
    }
};