#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    
    vector<int> vec1{-3,0,1,2,-1,1,-2};
    
        sort(vec1.begin(),vec1.end());
        int right = vec1.size();
        vector<vector<int>> result;
        for(int i=0;i<right-2;i++){
            int j = i+1;
            if (i > j && vec1[i] == vec1[i - 1]){
                continue;
            }
            int n=right-1;
            while(j<n){
                int sum = vec1[i]+vec1[j]+vec1[n];
                if(sum==0){
                    result.push_back({vec1[i],vec1[j],vec1[n]});
                    
                    while(j<n&&vec1[j]==vec1[j+1]){
                        j++;
                    }
                    while(j<n&&vec1[n]==vec1[n-1]){
                        n--;
                    }
                    j++;
                    n--;
                }
                else if(sum>0){
                    n--;
                }
                else{
                    j++;
                }
            }
        }
//printing 2D vector
    for(int i=0;i<result.size();i++){
        cout<<"[";
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<", ";
        cout<<"]";
        cout<<endl;
    }
    return 0;

}