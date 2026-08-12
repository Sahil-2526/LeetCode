class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ptr = root;

        int low = min(p->val, q->val);
        int high = max(p->val, q->val);

        while(ptr!=p && ptr!=q){
            if(ptr->val <= low) ptr=ptr->right;
            else if(ptr->val >= high) ptr=ptr->left;
            else break;
        }

        return ptr;
    }
};