#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long total = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                total += grid[i][j];
                
        unordered_map<long long, int> topMap, bottomMap;
        long long topSum = 0, bottomSum = total;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                bottomMap[grid[i][j]]++;
        
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m; j++){
                int val = grid[i][j];
                topMap[val]++;
                bottomMap[val]--;
                if(bottomMap[val] == 0) bottomMap.erase(val);
                topSum += val;
                bottomSum -= val;
            }
            
            if(topSum == bottomSum) return true;
            
            long long diff = (topSum > bottomSum) ? (topSum - bottomSum) : (bottomSum - topSum);
            if(topSum > bottomSum){
                if(isValid(grid, diff, 0, i, 0, m - 1, topMap)) return true;
            } else {
                if(isValid(grid, diff, i + 1, n - 1, 0, m - 1, bottomMap)) return true;
            }
        }
        
        unordered_map<long long, int> leftMap, rightMap;
        long long leftSum = 0, rightSum = total;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                rightMap[grid[i][j]]++;
        
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                int val = grid[j][i];
                leftMap[val]++;
                rightMap[val]--;
                if(rightMap[val] == 0) rightMap.erase(val);
                leftSum += val;
                rightSum -= val;
            }
            
            if(leftSum == rightSum) return true;
            
            long long diff = (leftSum > rightSum) ? (leftSum - rightSum) : (rightSum - leftSum);
            if(leftSum > rightSum){
                if(isValid(grid, diff, 0, n - 1, 0, i, leftMap)) return true;
            } else {
                if(isValid(grid, diff, 0, n - 1, i + 1, m - 1, rightMap)) return true;
            }
        }
        
        return false;
    }

private:
    bool isValid(const vector<vector<int>>& grid, long long target, int rs, int re, int cs, int ce, const unordered_map<long long, int>& map) {
        if (map.find(target) == map.end()) return false;

        if (rs == re && cs == ce) return false;

        if (rs == re) {
            return (grid[rs][cs] == target || grid[rs][ce] == target);
        }
        if (cs == ce) {
            return (grid[rs][cs] == target || grid[re][cs] == target);
        }

        return true;
    }
};


// first we will make 2 partition , and find sum of both 
//  then check if equal both equal , if yes then true else  
// if not find diff and check if element present in bigger sum value
// if present find that if its present in invalidPlace or not 
// if present in invalid , then can remove move to next 
// else true  