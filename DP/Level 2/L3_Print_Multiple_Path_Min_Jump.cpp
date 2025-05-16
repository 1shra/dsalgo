#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int d=0;

void genratePath(int i,int n,vector<int>& path,vector<int> &vec,vector<int>& dp){
    d++;
    if(i==n-1){
        
        string pf = "";
        for(int i=0;i<path.size();i++){
            pf+=to_string(path[i])+"->";
        }
        pf=pf.substr(0,pf.length()-2);
        cout<<pf<<endl;
        return;
    }
    int steps = vec[i];
    int d = dp[i];
    for(int j=1;i+j<vec.size()&&j<=steps;j++){
        if(dp[i+j]==d-1){
            path.push_back(i+j);
            genratePath(i+j,n,path,vec,dp);
            path.pop_back();
        }
    }
}

void findPath(vector<int> & vec,vector<int>& dp){
    vector<int> path;
    int n=vec.size();
    path.push_back(0);
    genratePath(0,n,path,vec,dp);
}

void pmp(vector<int> vec)
{
    int n = vec.size();
    
    vector<int> dp(n,0);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int step = vec[i];
        int j = 1;
        int mi = INT_MAX;
        while (j <= step && (i + j) < n)
        {
            if (mi > dp[i + j])
            {
                mi = dp[i + j];
            }
            j++;
        }
        if (mi == INT_MAX)
        {
            dp[i] = INT_MAX;
            continue;
        }
        dp[i] = mi + 1;
    }
    for (int i : dp)
    {
        cout << i << " ";
    }
    cout << endl;


    findPath(vec,dp);
}
int main()
{
    vector<int> vec = {3,3,3,2,2,1,4,2,0,0};
    pmp(vec);
    cout<<endl<<d;
    return 0;
}