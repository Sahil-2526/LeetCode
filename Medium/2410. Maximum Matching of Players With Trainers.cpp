class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Sorting players and trainer array
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p_size = players.size();
        int t_size = trainers.size();

        // Assign the smallest timed trainer that is >= players time
        int pp = 0;
        int tp = 0;
        int plyrs = 0;
        while( pp<p_size && tp<t_size){
            if(players[pp] <= trainers[tp]){
                plyrs++;
                pp++;
                tp++;
            }
            else tp++;
        } 

        return plyrs;
    }
};