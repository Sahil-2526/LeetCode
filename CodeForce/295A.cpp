#include<iostream>
#include<vector>
using namespace std;

void operation(int a,int b,long long c,vector<long long> &add){
    add[a-1] += c;
    add[b] -= c;
}

vector<long long> prefixSum(vector<long long> &arr,int n){
    vector<long long> ans(n,0);
    ans[0] = arr[0];
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1] + arr[i];
    }
    return ans;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<long long> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<long long>> oper(m,vector<long long>(3,0));
    for(int i=0;i<m;i++){
        cin>>oper[i][0]>>oper[i][1]>>oper[i][2];
    }

    vector<long long> qry(m+1,0);
    int a,b;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        qry[a-1]++;
        qry[b]--;
    }
    
    vector<long long> pfxSm = prefixSum(qry, m);

    vector<long long> add(n+1,0);

    for(int i=0;i<m;i++){
        operation(oper[i][0], oper[i][1], oper[i][2]*pfxSm[i], add);
    }

    vector<long long> finalAdd = prefixSum(add, n);

    for(int i=0;i<n;i++){
        finalAdd[i] += arr[i];
        cout << finalAdd[i] << " ";
    }

    return 0;
}