class Solution {
public:
    int countPrimes(int n) {
        bool primes[n+1];
        memset(primes, true, sizeof(primes));
        
        for(int i=2; i*i<=n; i++)
            if(primes[i] == true)
                for(int j = i*2; j <= n; j += i)
                    primes[j] = false;
         
        int c = 0;
        for(int i=2; i<n; i++)
            if(primes[i] == true)
                c++;
        
        return c;
    }
};
