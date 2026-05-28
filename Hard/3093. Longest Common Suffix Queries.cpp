class Solution {
public:

    struct Node {
        int child[26];
        int minm, idx;

        Node() {
            memset(child, -1, sizeof(child));
            minm = INT_MAX;
            idx = INT_MAX;
        }
    };

    class Tree {
    public:
        vector<Node> tree;

        Tree() {
            tree.push_back(Node());
        }

        void insert(string &word, int index) {
            int curr = 0;
            int n = word.length();

            if(n < tree[curr].minm) {
                tree[curr].minm = n;
                tree[curr].idx = index;
            }
            else if(n == tree[curr].minm) {
                tree[curr].idx = min(tree[curr].idx, index);
            }

            for(int i = n - 1; i >= 0; i--) {
                int c = word[i] - 'a';

                if(tree[curr].child[c] == -1) {
                    tree[curr].child[c] = tree.size();
                    tree.push_back(Node());
                }

                curr = tree[curr].child[c];

                if(n < tree[curr].minm) {
                    tree[curr].minm = n;
                    tree[curr].idx = index;
                }
                else if(n == tree[curr].minm) {
                    tree[curr].idx = min(tree[curr].idx, index);
                }
            }
        }

        int lcp(string &word) {
            int curr = 0;

            for(int i = word.length() - 1; i >= 0; i--) {
                int c = word[i] - 'a';

                if(tree[curr].child[c] == -1)
                    break;

                curr = tree[curr].child[c];
            }

            return tree[curr].idx;
        }
    };

    vector<int> stringIndices(
        vector<string>& wordsContainer,
        vector<string>& wordsQuery) {

        Tree tree;

        for(int i = 0; i < wordsContainer.size(); i++) {
            tree.insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(string &q : wordsQuery) {
            ans.push_back(tree.lcp(q));
        }

        return ans;
    }
};