#include<bits/stdc++.h>
using namespace std;

int a[100005], seg[4+100005];

int build(int ind,int low,int high){
  if(low==high){
    seg[ind] = a[low]; 
    return a[low];
  }
  int mid = (low+high)/2;
  int left = build(2*ind+1,0,mid);
  int right = build(2*ind+2,mid+1,high);
  seg[ind]=max(left,right);
  return seg[ind];
}
int query(int ind,int low,int high,int l,int r){
  if(low>=l&&high<=r){
    //COMPLETELY LIE INTO THE RANGE
    return seg[ind];
  }
  if(high<l||low>r){
    return INT_MIN;
  }
  int mid = (low+high)/2;
  int left = query(2*ind+1,low,mid,l,r);
  int right = query(2*ind+2,low,mid,l,r);
  return max(left,right);
}


void pointUpdate(int ind,int low,int high, int node,int val){
  if(low==high){
    seg[low]+=val;
  }
  else{
    int mid = (low+high)>>1;
    if(node<=mid&&node>=low) pointUpdate(2*ind+1,low,mid,node,val);
    else{
      pointUpdate(2*ind+2,mid+1,high,node,val);
    }
    seg[ind]= max(seg[2*ind+1],seg[2*ind+2]);
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  build(0, 0,n-1);
  for(int i=0;i<n;i++){
    cout<<seg[i]<<" ";
  }
  int q;
  cin>>q;
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<query(0,0,n-1,l,r);
  }
}