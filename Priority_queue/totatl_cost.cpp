#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int,vector<int>,greater<>> pql;
    priority_queue<int,vector<int>,greater<>> pqr;
    int j=costs.size()-1;
    int i=0;
    for(i=0;i<candidates;i++){
        pql.push(costs[i]);
        pqr.push(costs[j]);
        j--;
        if(i>=j){
            if(i==j){
                pql.push(costs[i]);
                i++;
            }
            break;
        }
    }
    int ans=0;
    while(k){
        if(pql.top()>pqr.top()){
            cout<<pqr.top()<<" r"<<endl;
            ans+=pqr.top();
            pqr.pop();
            if(i<=j){
                pqr.push(costs[j]);
                j--;
            }
        }
        else{
            cout<<pql.top()<<" l"<<endl;
            ans+=pql.top();
            pql.pop();
            if(i<=j){
                pql.push(costs[i]);
                i++;
            }
        }
        k--;
    }
    return ans;
}
int main(){
    vector<int> cost ={18,64,12,21,21,78,36,58,88,58,99,26,92,91,53,10,24,25,20,92,73,63,51,65,87,6,17,32,14,42,46,65,43,9,75};
    int k = 13;
    int candidates =23;
    cout<<totalCost(cost,k,candidates)<<endl;
    return 0;
}