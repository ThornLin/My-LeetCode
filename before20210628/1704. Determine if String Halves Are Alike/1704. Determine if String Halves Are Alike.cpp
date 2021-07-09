/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
Example 3:

Input: s = "MerryChristmas"
Output: false
Example 4:

Input: s = "AbCdEfGh"
Output: true
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowel = "aeiou";
        int slf = s.length()/2, count = 0;
        for(int i=0; i<slf; i++){
            if(s[i]-'A'>=0 and s[i]-'A'<=26){
                s[i] = s[i]-'A'+'a';
            }
            if(s[slf + i]-'A'>=0 and s[slf + i]-'A'<=26){
                s[slf + i] = s[slf + i]-'A'+'a';
            }
            for(int j=0; j<vowel.length(); j++){
                if(s[i]==vowel[j]){
                    count++;
                }
                if(s[slf + i]==vowel[j]){
                    count--;
                }
            }
        }
        return !bool(count);
    }
};
