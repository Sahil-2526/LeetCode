class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);

        int farthest = 0;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (idx == n - 1) return true;

            int start = max(idx + minJump, farthest);
            int end = min(idx + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    q.push(j);
                }
            }

            farthest = max(farthest, idx + maxJump + 1);
        }

        return false;
    }
};