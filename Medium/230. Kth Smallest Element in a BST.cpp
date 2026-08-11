// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     int lChild;  

//     TreeNode() : val(0), left(nullptr), right(nullptr), lChild(0) {}

//     TreeNode(int x) : val(x), left(nullptr), right(nullptr), lChild(0) {}

//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right), lChild(0) {}
// };

// class Solution {
// public:
//     unordered_map<TreeNode*, int> leftCount;
//     int solve(TreeNode* root) {
//         if (root == NULL) return 0;
//         int leftCount = solve(root->left);
//         solve(root->right);
//         root->lChild = leftCount;
//         return leftCount + 1;
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         solve(root);
//         TreeNode* curr = root;
//         while (curr != NULL) {
//             int leftCount = curr->lChild;
//             if (k == leftCount + 1) return curr->val;
//             if (k <= leftCount) curr = curr->left;
//             else {
//                 k -= leftCount + 1;
//                 curr = curr->right;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    unordered_map<TreeNode*, int> lChild;
    int solve(TreeNode* root) {
        if (root == NULL)  return 0;

        int leftCount = solve(root->left);
        int rightCount = solve(root->right);

        lChild[root] = leftCount;

        return leftCount + rightCount + 1;
    }

    int kthSmallest(TreeNode* root, int k) {
        solve(root);

        TreeNode* curr = root;

        while (curr != NULL) {
            int leftCount = lChild[curr];

            if (k == leftCount + 1)
                return curr->val;

            if (k <= leftCount) {
                curr = curr->left;
            }
            else {
                k -= leftCount + 1;
                curr = curr->right;
            }
        }

        return -1;
    }
};
