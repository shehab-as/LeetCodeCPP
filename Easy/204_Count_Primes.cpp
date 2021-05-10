class Solution {
public:
    int countPrimes(int n) {
        //Sieve of Erantothoses
        vector<bool> primes(n+1,true); 

      primes[0]=false;
      primes[1]=false;

      for(int i = 2; i * i <= n; i++) 
      {
        if(primes[i]==false) continue;

        int j=i*i;
        while(j <= n) 
        {
            primes[j]=false;
            j = j+i;
        }

      }
        
      int count=0;
      for(int i = 1; i < n; i++)
          count += primes[i];
        
        return count;
    }
};