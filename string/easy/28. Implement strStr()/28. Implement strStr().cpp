/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
 

Constraints:

0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
*/

/*class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle==""){return 0;}
        if(haystack.size()<needle.size()){return -1;}
        for(int i=0; i<haystack.size()-needle.size()+1; i++){
            if(haystack.substr(i, needle.size())==needle){
                return i;
            }
        }
        return -1;
    }
};*/

class Solution {
public:
    bool cmp(string a, string b, int i){
        for(int j=0; j<b.size(); j++){
            if(a[i+j]!=b[j]){return false;}
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int h_size=haystack.size(), n_size=needle.size(), h=0, n=0;
        if(h_size<n_size){return -1;}
        for(int i=0; i<n_size; i++){h+=haystack[i]; n+=needle[i];}
        for(int i=0; i<h_size-n_size+1; i++){
            if(h==n and cmp(haystack, needle, i)){return i;}
            if(i<h_size-n_size){h+=haystack[i+n_size]-haystack[i];}
        }
        return -1;
    }
};
