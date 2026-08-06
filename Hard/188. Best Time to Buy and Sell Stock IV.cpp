struct Node{
    int mn;
    int mx;
    int val;
};

class SegmentTree{
    vector<Node> tree;
    int n;

    Node merge(Node left, Node right){
        Node res;
        res.mn = min(left.mn, right.mn);
        res.mx = max(left.mx, right.mx);
        res.val = max({left.val, right.val, right.mx - left.mn});
        return res;
    }

    void build(int node, int l, int r, vector<vector<int>>& arr){
        if(l==r){
            tree[node].mn = arr[l][0];
            tree[node].mx = arr[l][1];
            tree[node].val = arr[l][1]-arr[l][0];
            return;
        }

        int mid=(l+r)/2;

        build(node*2,l,mid,arr);
        build(node*2+1,mid+1,r,arr);

        tree[node]=merge(tree[node*2],tree[node*2+1]);
    }

    Node query(int node,int l,int r,int ql,int qr){
        if(ql<=l && r<=qr)
            return tree[node];

        int mid=(l+r)/2;

        if(qr<=mid)
            return query(node*2,l,mid,ql,qr);

        if(ql>mid)
            return query(node*2+1,mid+1,r,ql,qr);

        Node left=query(node*2,l,mid,ql,qr);
        Node right=query(node*2+1,mid+1,r,ql,qr);

        return merge(left,right);
    }

public:
    SegmentTree(vector<vector<int>>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(1,0,n-1,arr);
    }

    int rangeQuery(int l,int r){
        return query(1,0,n-1,l,r).val;
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> smllrg;
    vector<vector<int>> cost; 

    int solve(int start, int g, SegmentTree &st) {
        int m = smllrg.size();
        if (start >= m || g <= 0) return 0;
        if (g == 1) return cost[start][m - 1];
        if (dp[start][g] != -1) return dp[start][g];
        
        int ans = 0;
        for (int end = start; end <= m - g; end++) {
            ans = max(ans, cost[start][end] + solve(end + 1, g - 1, st));
        }
        return dp[start][g] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        smllrg.clear();
        
        int i = 0;
        while (i < n) {
            while (i + 1 < n && prices[i] >= prices[i + 1])
                i++;
            if (i == n - 1) break;
            int sml = prices[i];
            while (i + 1 < n && prices[i] < prices[i + 1])
                i++;
            int lrg = prices[i];
            smllrg.push_back({sml, lrg});
        }
        
        int m = smllrg.size();
        if (m == 0) return 0;
        
        if (k >= m) {
            int total = 0;
            for (auto& seg : smllrg) {
                total += (seg[1] - seg[0]);
            }
            return total;
        }

        k = min(k, m);
        SegmentTree st(smllrg);
        dp.assign(m + 1, vector<int>(k + 1, -1));
        
        cost.assign(m, vector<int>(m, 0));
        for (int l = 0; l < m; l++) {
            for (int r = l; r < m; r++) {
                cost[l][r] = st.rangeQuery(l, r);
            }
        }
        
        return solve(0, k, st);
    }
};