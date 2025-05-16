#include <iostream>
#include <vector>
using namespace std;
// recursive
int climbing(vector<int>& a)
{
    int n=a.size();
    vector<int> dp(n+1);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;i+j<dp.size()&&j<=a[i];j++){
            dp[i]+= dp[i+j];
        }
    }
    return dp[0];
}

int main()
{
    vector<int> a = {1,2,3};
    cout << "recursion" << endl;
    cout << climbing(a) << endl;
    return 0;
}