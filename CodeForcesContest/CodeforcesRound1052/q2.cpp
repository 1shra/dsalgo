  #include <bits/stdc++.h>
  using namespace std;

  int main() {
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int> vec(n);
      for(int &i:vec) cin>>i;
      string s;
      cin>>s;
      if(s[0]=='1'||s[n-1]=='1'){
        cout<<-1<<endl;
        continue;;
      }
      vector<int> leftmin(n),leftmax(n),rightmin(n),rightmax(n);
      leftmin[0]=0;
      leftmax[0]=0;
      for(int i=1;i<n;i++){
        if(vec[leftmin[i-1]]>vec[i]){
          leftmin[i]=i;
        }
        else{
          leftmin[i]=leftmin[i-1];
        }
        if(vec[leftmax[i-1]]<vec[i]){
          leftmax[i]=i;
        }
        else{
          leftmax[i]=leftmax[i-1];
        }
      }
      rightmin[n-1]=n-1;
      rightmax[n-1]=n-1;
      for(int i=n-2;i>=0;i--){
        if(vec[rightmin[i+1]]>vec[i]){
          rightmin[i]=i;
        }else{
          rightmin[i]=rightmin[i+1];
          
        }
        if(vec[rightmax[i+1]]<vec[i]){
          rightmax[i]=i;
        }else{
          rightmax[i]=rightmax[i+1];
        }
      }
      // for(int i:rightmax) cout<<i<<" ";
      // cout<<endl;
      int flag=1;
      vector<pair<int,int>> ans;
      int cnt=0;
      for(int i=1;i<n-1;i++){
        if(s[i]=='1'){
          cnt++;
          if(vec[leftmin[i]]<vec[i] && vec[rightmax[i]]>vec[i]){
            ans.push_back({leftmin[i],rightmax[i]});
          }
          else if(vec[leftmax[i]]>vec[i] && vec[rightmin[i]]<vec[i]){
            ans.push_back({leftmax[i],rightmin[i]});
          }
          else{
            flag=0;
            break;
          }
          if(cnt==6){
            flag=0;
            break;
          }
        }
      }
      if(flag){
        cout<<ans.size()<<endl;
        for(pair<int,int> i:ans){
          cout<<i.first+1<<" "<<i.second+1<<endl;
        }
      }
      else{
        cout<<-1<<endl;
      }
    }
    return 0;
  }