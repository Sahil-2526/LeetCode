class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < n - k; i++) {
            sum += cardPoints[i];
        }
        int mn = sum;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[n - k + i];
            sum -= cardPoints[i];
            mn = min(mn, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - mn;
    }
};