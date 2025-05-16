#include<iostream>
#include<vector>
using namespace std;

int longsubarray(int k,const vector<int> &vec){
    int window_start = 0;
    int a;
    int maxfreq = 0;
    int maxcount = 0;
    for(int window_end = 0; window_end<vec.size();window_end++){
        a = vec[window_end];
        if( a == 1){
            maxfreq++;
        }
        if(window_end-window_start+1-maxfreq>k){
            if(vec[window_start]==1){
                maxfreq--;
            }
            window_start++;
        }
        maxcount=max(maxcount,window_end-window_start+1);

    }
    return maxcount;
}


int main(){
    cout<<"Longest subarray after replacing 0 to 1: "<<longsubarray(2,vector<int>{0,1,1,1,0,1,1,0,1});
}