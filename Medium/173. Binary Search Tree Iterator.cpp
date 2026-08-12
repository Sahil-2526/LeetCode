class BSTIterator {
    stack<TreeNode*> st;
public:    
    BSTIterator(TreeNode* root) {
        TreeNode* p = root;
        while(p!=NULL){
            st.push(p);
            p=p->left;
        }
    }
    
    int next() {
        TreeNode* nxt = st.top();
        st.pop();
        if(nxt->right != NULL){
            TreeNode* p = nxt->right;
            while(p!=NULL){
                st.push(p);
                p=p->left;
            }
        }
        return nxt->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};