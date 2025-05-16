#include <iostream>
#include <map>
using namespace std;
// void print(map<int,string> &m){
//     cout<< m.size()<<endl;
//     for(auto &pr : m){
//         cout << pr.first<<" "<<pr.second<<endl;
//     }
// }
int main(){
    //declaring ordered map
    map<int, string> m;
    //inserting value int the map
    m[1]= "abc"; // O(log(n))
    m[2]= "cdcc";
    m[6]= "acd";
    // m.insert({4, "afg"});


    //printing the ṇoutput of the map
     
    map<int,string> :: iterator it;
    for(it = m.begin();it != m.end(); ++it)
    {
        cout<<(*it).first<<" "<< (*it).second<<endl;
    }
    
   
   /* prefer funtion for output
   for(auto &pr :m){
        cout<<pr.first<<" "<<pr.second<<endl;
   }
    */
    auto it = m.find(6);
/*
   // for finding the element in the map
   if(it == m.end())
   {
    cout<<"NO VALUE";
    }
    else{
        cout<< (*it).first<<" "<<(*it).second<<endl;    }

*/

   //for erase
   if(it != m.end()){
    m.erase(it);
   }

 /*
   // clear 
   m.clear();
 */  
   print(m);

    return 0;
}