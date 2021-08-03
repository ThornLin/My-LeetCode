/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){string tmp=a; a=b; b=tmp;}
        vector<int> v(a.size()+1, 0);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<a.size(); i++){v[i]+=a[i]-'0';}
        for(int i=0; i<b.size(); i++){v[i]+=b[i]-'0';}
        for(int i=0; i<v.size()-1; i++){
            v[i+1]+=v[i]/2;
            v[i]%=2;
        }
        string res="";
        for(auto x: v){res+=x+'0';}
        reverse(res.begin(), res.end());
        if(res[0]=='0'){return res.substr(1, res.size());}
        else{return res;}
    }
};
