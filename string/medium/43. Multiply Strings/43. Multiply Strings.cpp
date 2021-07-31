/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

/*class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0"){return "0";}
        string res="";
        int i=0;
        while(i<num2.size()){
            string sub_res="";
            int j=0, carry=0;
            while(j<i){sub_res+="0"; j++;}
            j=0;
            while(j<num1.size()){
                carry=((num1[num1.size()-j-1]-'0')*(num2[num2.size()-i-1]-'0')+carry);
                sub_res+=carry%10+'0';
                carry/=10;
                j++;
            }
            if(carry){sub_res+=carry+'0';}
            
            j=0; carry=0;
            string tmp="";
            while(j<res.size()){
                carry=res[j]-'0'+sub_res[j]-'0'+carry;
                tmp+=carry%10+'0';
                carry/=10;
                j++;
            }
            while(j<sub_res.size()){
                carry=sub_res[j]-'0'+carry;
                tmp+=carry%10+'0';
                carry/=10;
                j++;
            }          
            if(carry){tmp+=carry+'0';}
            res=tmp;
            i++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0"){return "0";}
        int m=num1.size(), n=num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> v(m+n+2, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=0; i<m+n; i++){
            v[i+1]+=v[i]/10;
            v[i]%=10;
        }
        int b=m+n+1;
        while(b>0 and v[b]==0){b--;}
        string res="";
        for(int i=b; i>=0; i--){
            res+=(char)(v[i]+'0');
        }
        return res;
    }
};
