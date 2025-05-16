// at most 2 time buy and sell operation

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
vector<int> right(int arr[], int n)
{
    vector<int> r(n);
    int least = arr[0];
    r[0]=0;
    for (int i = 1; i < n; i++)
    {
        if(least>arr[i]){
            least = arr[i];
        }
        if(r[i-1]>arr[i]-least){
            r[i]=r[i-1];
        }
        else{
            r[i]=arr[i-1]-least;
        }
    }
    return r;
}
vector<int> left(int arr[], int n)
{
    vector<int> r(n);
    int ma = arr[n-1];
    r[n-1]=0;
    for (int i = n-2; i>=0; i--)
    {
        
        if(ma<arr[i]){
            ma=arr[i];
        }
        if(r[i+1]<ma-arr[i]){
            r[i]=ma-arr[i];
        }
        else{
            r[i]=r[i+1];
        }
    }
    return r;
}
int buyandsell(int arr[], int n)
{
    vector<int> r = right(arr, n);
    vector<int> l = left(arr,n);
    int m=0;
    for(int i=0;i<n;i++){
        if(m<r[i]+l[i]){
            m=r[i]+l[i];
        }
        cout<<r[i]<<" "<<l[i]<<endl;
    }
    return m;
}
int main()
{
    int n = 8;
    int arr[n] = {3,3,5,0,0,3,1,4};
    cout << buyandsell(arr, n);
    return 0;
}