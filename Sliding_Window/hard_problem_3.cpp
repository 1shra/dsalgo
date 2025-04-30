#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.empty() || t.empty() || s.length() == 0 || t.length() == 0 || s.length() < t.length()) return "";
        
        int minLeft = 0;
        int minRight = 0;
        int min = s.length();
        bool flag = false;
        unordered_map<char, int> map;
        int count = t.length(); 
        for(char c : t) map[c]++;
        
        int i = 0;
        int j = 0;
        while(j < s.length()){
            char c = s[j];
            if(map.count(c)){
                map[c]--;
                if(map[c] >= 0) count--; 
            }
            
            while(count == 0 && i <= j){
                
                flag = true;
                int curLen = j + 1 - i;
                if(curLen <= min){
                    minLeft = i;
                    minRight = j;
                    min = curLen;
                }
                
                char leftC = s[i];
                if(map.count(leftC)){
                    map[leftC]++;
                    if(map[leftC] > 0) count++;
                }
                
                i++;
            }
            j++;
        }
        
        if(flag) return s.substr(minLeft, minRight - minLeft + 1);
        else return "";
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << solution.minWindow(s, t) << endl;
    return 0;
}
