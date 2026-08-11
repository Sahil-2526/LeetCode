class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* p = root;
        TreeNode* newNode = new TreeNode(val);
        while(p != NULL) {
            if(p->val > val) {
                if(p->left == NULL) {
                    p->left = newNode;
                    break;
                }
                p = p->left;
            }
            else {
                if(p->right == NULL) {
                    p->right = newNode;
                    break;
                }
                p = p->right;
            }
        }
        return root;
    }
};