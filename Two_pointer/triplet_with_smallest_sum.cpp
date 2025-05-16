#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={-1,0,2,3};
    int sum=3;
    int n=4;
    long long count=0;
	sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        int k=n-1;
        int j=i+1;
        while(j<k){
            long long su=arr[i]+arr[j]+arr[k];
            if(su<sum){
                count+=k-j;
                j++;
            }
            else{
                 k--;
            }
        }
    }
    cout<< count;
}