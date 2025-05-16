#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
int long_subarray(int k,const vector<int>& arr){
    int window_start=0, maxfreq = 0;
    int maxcount = 0;
    cout<<arr.size()<<endl;
    unordered_map<int,int> freq;
    for(int window_end=0;window_end<arr.size();window_end++){
        int a;
        a = arr[window_end];
        freq[a]++;
        maxfreq=max(maxfreq,freq[a]);
        
        if(window_end-window_start+1-maxfreq>k){
            int b=arr[window_end];
            freq[b]--;
            window_start++;
        }
        maxcount=max(maxcount,window_end-window_start+1);
    }
    return maxcount;
}

int main(){
    cout<<"Longest Subarray with ones after Replacement: "<< long_subarray(2,vector<int>{0,1,1,0,0,0,1,1,1,1});
    return 0;
}