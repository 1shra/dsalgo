#include<iostream>
using namespace std;
int main(){

/*    
    string s = "today is a match ";
    string a ="between inda vs australia";
    cout<<s<<endl;
    // 
    // // it does not read aftter space ,tab , enter
    // string s;
    // cin>>s;
    // cout<<s;
    // 

   // to resolve this we use getline(cin,s) but it is not valid for enter
//    getline(cin,s);
//    cout<<s;

    // to find the size of the string
    cout<<s.size()<<endl;
    // to add string concaticate
    // string b=s+a;
    string b=s.append(a);
    cout<<b<<endl;
    //push at last element
    s.push_back('p');
    cout<<s<<endl;
    //delete last element
    s.pop_back();
    cout<<s<<endl;

    //to print " " in between the string we use \ operator
    string k = "Ashraf is a \"good\" boy";
    cout<<k;    
*/


// reverseing the string
string s = "Nitin is a good boy";
int start =0;
int end =s.size()-1;
while(start<end){
    swap(s[start],s[end]);
    start++;
    end--;
}
cout<<s<<endl;

//calcute size without use size function
int i=0;
while(s[i] != '\0'){
    i++;
}
cout<<i<<endl;
//check if the string is palindrome

string s2 = "nitn";
start =0;
end =s2.size()-1;
while(start<end){
    if(s2[start]!=s2[end]){
        cout<<"is not a palindrom";
        return 0;
    }
    start++;end--;
}
cout<<"String is a palindrome";

}
