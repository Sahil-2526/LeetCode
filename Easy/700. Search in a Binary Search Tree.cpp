class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* p = root;
        while(p != NULL){
            if(p->val == val) return p;
            else if(p-> val > val) p = p->left;
            else p = p->right;
        }
        return NULL;
    }
};