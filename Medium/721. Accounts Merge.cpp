#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent])
            parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent])
            parent[x_parent]=y_parent;
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU uf(n);
        unordered_map<string,int> email_to_id;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(email_to_id.find(email) == email_to_id.end())
                    email_to_id[email] = i;
                else uf.Union(i, email_to_id[email]);
            }
        }

        vector<vector<string>> res(n);
        for(int i=0;i<n;i++){
            int root = uf.find(i);
            if(res[root].empty()) res[root].push_back(accounts[i][0]); 
            for(int j=1;j<accounts[i].size();j++){ 
                res[root].push_back(accounts[i][j]); }
        }

        vector<vector<string>> ans;
        for(auto &v : res){
            if(v.empty()) continue;
            sort(v.begin()+1, v.end());
            v.erase(unique(v.begin()+1, v.end()), v.end());
            ans.push_back(v);
        }

        return ans;
    }
};

// first we will check all email and map them to the account id
// if its not fount we will assign it parents id
// if found we will UNION the parent index to the FIND index of the string that is found 
// after than we will combiine array with same parent index
// then we will sort the email and remove duplicates and return the answer