class Solution {
public:
    int sumOfRoots(TreeNode* root, string s) {
        if(!root) return 0;
        s += to_string(root->val);
        if(!root->left && !root->right) {
            return stoi(s, nullptr, 2);
        }
        int leftSum = sumOfRoots(root->left, s);
        int rightSum = sumOfRoots(root->right, s);
        return leftSum + rightSum; 
    }

    int sumRootToLeaf(TreeNode* root) {
        return sumOfRoots(root, ""); 
    }
};