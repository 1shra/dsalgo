#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        
        vector<int> min_cost(n+1,INT_MAX);
        for(int i=0;i<n;i++){
            min_cost[a[i]]=min(min_cost[a[i]],b[i]);
        }
        vector<int> vitamins_cost;
        for(int i=1;i<=n;i++){
            if(min_cost[i]!=INT_MAX){
                vitamins_cost.push_back(min_cost[i]);
            }
        }
        
        sort(vitamins_cost.begin(),vitamins_cost.end());
        
        int max_value = 0;
        int totalcost=0;
        for(int i=0;vitamins_cost.size();i++){
            totalcost+=vitamins_cost[i];
            int distinct = i+1;
            int current = c*distinct-totalcost;
            max_value=max(max_value,current);
        }
        cout<<max_value<<endl;
    }
    return 0;
}