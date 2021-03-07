class RLEIterator {
private:
        vector<int> A;
        int sz;
        int i;
public:
    RLEIterator(vector<int> A) : A(A), sz(A.size()), i(0) { }
    
    int next(int n) {
        while(i < sz)
        {
            if(A[i] > n)
            {
                A[i] -= n;
                return A[i+1];
            }
            else if(A[i] == n)
            {
                A[i] = 0;
                i += 2;
                return A[i-1];
            }
            else    // A[i] < n
            {
                n -= A[i];
                i += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */