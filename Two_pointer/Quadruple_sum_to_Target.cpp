#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> vec{4,1,2,-1,1,-3};
    vector<vector<int> vec1;
    int target=1;;
    int n=vec.size();
    for(int i=0;i<n-3;i++){
        for(int j=i+1;i<n-2;j++){
            int k=j+1;
            int l=n-1;
            int sum=vec[i]+vec[j]+vec[k]+vec[l];
            if(sum==target){
                vec1.push_back(vec[i],vec[j],vec[k],vec[l]);
                k++;
            }
            else if(sum<target){
                k++;
            }
            else{
                l--;
            }
        }
    }
    for(int i=0;i<vec1.size();i++){
        cout<<vec1[i]<<endl;
    }
    return 0;
}
