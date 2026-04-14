class Solution {
  public:
    vector<int> sieve(int n) {
        vector<int> prime(n + 1, 1);   // all assumed prime initially
        prime[0] = prime[1] = 0;       // 0 and 1 are not prime

        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == 1) {                    // if i is prime
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = 0;                   // mark multiples as not prime
                }
            }
        }

        vector<int> ans;
        for (int i = 2; i <= n; i++) {  // <= n to include n itself
            if (prime[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};