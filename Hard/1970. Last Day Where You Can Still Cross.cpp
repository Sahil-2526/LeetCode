#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = cells.size();
        vector<vector<int>> pos(row, vector<int>(col, 0));
        
        auto canCross = [&](int day) {
            for(int r = 0; r < row; r++)
                for(int c = 0; c < col; c++)
                    pos[r][c] = 0;
            
            for(int i = 0; i < day; i++) {
                int r = cells[i][0] - 1;
                int c = cells[i][1] - 1;
                pos[r][c] = 1;
            }
            
            
            vector<vector<bool>> topVisited(row, vector<bool>(col,false));
            vector<vector<bool>> bottomVisited(row, vector<bool>(col,false));
            queue<pair<int,int>> topQ, bottomQ;
            
          
            for(int c = 0; c < col; c++)
                if(pos[0][c] == 0) {
                    topQ.push({0,c});
                    topVisited[0][c] = true;
                }
            
          
            for(int c = 0; c < col; c++)
                if(pos[row-1][c] == 0) {
                    bottomQ.push({row-1,c});
                    bottomVisited[row-1][c] = true;
                }
            
            vector<int> dr = {0,0,1,-1};
            vector<int> dc = {1,-1,0,0};
            
            while(!topQ.empty() || !bottomQ.empty()) {
             
                int topSize = topQ.size();
                while(topSize--) {
                    auto [r,c] = topQ.front(); topQ.pop();
                    if(bottomVisited[r][c]) return true; 
                    for(int k = 0; k < 4; k++) {
                        int nr = r + dr[k], nc = c + dc[k];
                        if(nr>=0 && nr<row && nc>=0 && nc<col && !topVisited[nr][nc] && pos[nr][nc]==0) {
                            topVisited[nr][nc] = true;
                            topQ.push({nr,nc});
                        }
                    }
                }
                
               
                int bottomSize = bottomQ.size();
                while(bottomSize--) {
                    auto [r,c] = bottomQ.front(); bottomQ.pop();
                    if(topVisited[r][c]) return true; 
                    for(int k = 0; k < 4; k++) {
                        int nr = r + dr[k], nc = c + dc[k];
                        if(nr>=0 && nr<row && nc>=0 && nc<col && !bottomVisited[nr][nc] && pos[nr][nc]==0) {
                            bottomVisited[nr][nc] = true;
                            bottomQ.push({nr,nc});
                        }
                    }
                }
            }
            
            return false;
        };
        
        while(left < right) {
            int mid = left + (right - left + 1)/2;
            if(canCross(mid)) left = mid;
            else right = mid-1;
        }
        
        return left;
    }
};