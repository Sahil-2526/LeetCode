class Solution {
public:
    void insert(TreeNode* root, int val){
        TreeNode* curr = root;
        TreeNode* new_node = new TreeNode(val);
        TreeNode* prev = nullptr;
        bool left;
        while(1){
            prev = curr;
            if(curr->val < val){
                curr = curr->right;
                left = false; 
            }
            else{
                curr = curr->left;
                left = true;
            }
            if(curr == NULL){
                if(left) prev->left = new_node;
                else prev->right = new_node;
                break;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++){
            insert(root, preorder[i]);
        }

        return root;
    }
};