#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> vec1{1,0,2,1,0};
    int low=0;
    int high=vec1.size()-1;
    int mid=0;
    while(mid<high){
        if(vec1[mid]==0){
            int temp=vec1[mid];
            vec1[mid]=vec1[low];
            vec1[low]=temp;
            low++;
            mid++;
        }
        else if(vec1[mid]==1){
            mid++;
        }
        else{
            int temp=vec1[high];
            vec1[high]=vec1[mid];
            vec1[mid]=temp;
            high--;
        }
    }
    for(int i=0;i<vec1.size();i++){
        cout<<vec1[i]<<endl;
    }


}