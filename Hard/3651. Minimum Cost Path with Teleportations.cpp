class Solution(object):
    def minCost(self, grid, k):
        m, n = len(grid), len(grid[0])
        max_val = max(max(row) for row in grid) + 1
        leastCost = [float('inf')] * max_val
        dp = [[[float('inf') for _ in range(n)] for _ in range(m)] for _ in range(k+1)]
        for i in range(k+1):
            dp[i][m-1][n-1] = 0
        for i in range(k+1):
            currentLeast = [float('inf')] * max_val
            for j in range(m-1, -1, -1):
                for l in range(n-1, -1, -1):
                    if j == m-1 and l == n-1:
                        dp[i][j][l] = 0
                    else:
                        val = float('inf')
                        if j+1 < m:
                            val = min(val, dp[i][j+1][l] + grid[j+1][l])
                        if l+1 < n:
                            val = min(val, dp[i][j][l+1] + grid[j][l+1])
                        if i > 0:
                            val = min(val, leastCost[grid[j][l]])
                        dp[i][j][l] = val
                    currentLeast[grid[j][l]] = min(currentLeast[grid[j][l]],dp[i][j][l])
            leastCost[0] = currentLeast[0]
            for q in range(1, max_val):
                leastCost[q] = min(currentLeast[q], leastCost[q-1])
        return dp[k][0][0]