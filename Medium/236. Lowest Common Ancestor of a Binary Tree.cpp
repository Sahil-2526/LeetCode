class Solution {
public:
    TreeNode* res = NULL;
    pair<bool,bool> trav(TreeNode* node, TreeNode* p, TreeNode* q){
        if (node == NULL) return {false, false};
        pair<bool, bool> l, r;
        if(node->left) l = trav(node->left, p, q);
        if(node->right) r = trav(node->right, p, q);
        bool hasP = (l.first||r.first||node==p);
        bool hasQ = (l.second||r.second||node==q);
        if(hasP && hasQ && res==NULL){
            res = node;
        }
        return {hasP, hasQ};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        trav(root, p, q);
        return res;
    }
};