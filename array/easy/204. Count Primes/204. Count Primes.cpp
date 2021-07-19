/*
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/

/*class Solution { // TLE
public:
    int countPrimes(int n) {
        int res = 0;
        for(int i=0; i<n; i++){
            bool is_prime = false;
            if(i%2){ // odd
                for(int j=i-1; j>1; j--){
                    is_prime=true;
                    if(!(i%j)){is_prime=false; break;}
                }
            }else{ // even
                if(i==2){res++;}
            }
            if(is_prime){res++;}
        }
        return res;
    }
};*/

/*class Solution { // TLE
public:
    int countPrimes(int n) {
        vector<int> primes = {2};
        for(int i=2; i<n; i++){
            bool is_primes = true;
            for(auto x: primes){
                if(i%x==0){is_primes=false; break;}
            }
            if(is_primes){primes.push_back(i);}
        }
        return primes.size();
    }
};*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;
        for(int i=2; i*i<=n; i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j] = false;
                }
            }
        }
        int res=0;
        for(int i=2; i<n; i++){
            if(primes[i]){res ++;}
        }
        return res;
    }
};
