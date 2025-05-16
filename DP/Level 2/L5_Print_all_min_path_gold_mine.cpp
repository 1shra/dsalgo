#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class step{
    public:
    int n;
    int m;
    int rem;
    string sf;
    step(int n1,int m1,int rem1,string psf){
        n=n1;
        m=m1;
        rem=rem1;
        sf=psf;
    }
};
void printPath(vector<vector<int>>& dp,vector<vector<int>> &vec,int k){
    int n = dp.size();
    int m = dp[0].size();
    for(int i=0;i<m;i++){
        if(dp[n-1][i]==k){
            queue<step*> q;
            string sf="";
            q.push(new step(n-1,i,dp[n-1][i],sf));
            while(!q.empty()){
                step* bloc = q.front();
                q.pop();
                int rem = bloc->rem;
                int l = bloc->n;
                int o = bloc->m;
                rem-=vec[l][o];
                
                string psf = bloc->sf;
                if(l==0){
                     psf=to_string(vec[l][o])+psf;
                    cout<<psf<<endl;
                    continue;
                }
                if(rem==dp[l-1][o]){
                    psf = "->" + to_string(vec[l][o])+psf;
                    q.push(new step(l-1,o,rem,psf));
                }
                if(0<(o-1) && rem==dp[l-1][o-1]){
                    psf = "->" + to_string(vec[l][o])+psf;
                    q.push(new step(l-1,o-1,rem,psf));
                }
                if(m>(o+1)&& rem == dp[l-1][o+1]){
                    psf = "->" + to_string(vec[l][o])+psf;
                    q.push(new step(l-1,o+1,rem,psf));

                }

            }
        }
    }
}
void goldmine(vector<vector<int>>& vec,int n,int m){
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<m;i++){
        dp[0][i]=vec[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int k=dp[i-1][j];
            if(j-1>0){
                k=max(k,dp[i-1][j-1]);
            }
            if(j+1<m){
                k=max(k,dp[i-1][j+1]);
            }
            dp[i][j]=vec[i][j]+k;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int k=dp[n-1][0];

    for(int i=1;i<n;i++){
        m=max(k,dp[n-1][i]);
    }

    cout<<"Result: "<<k<<endl;
    printPath(dp,vec,k);
}
int main(){
    vector<vector<int>> vec={
        {3,2,5,9},
        {2,4,0,1},
        {3,6,1,5},
        {1,0,3,1}
    };
    int n = vec.size();
    int m = vec[0].size();
    goldmine(vec,n,m);
    return 0;
}

