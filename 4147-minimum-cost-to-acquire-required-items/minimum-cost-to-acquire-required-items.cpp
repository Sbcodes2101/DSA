class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        if (cb < c1 && cb < c2) {
            return max(n1, n2) * cb;
        }
       
        long long ans = 0;

        if (n1 < n2) {
            long long rem = n2 - n1;
            ans += n1 * min(c1 + c2, cb);
            ans += rem * min(c2, cb);
        } else {
            long long rem = n1 - n2;
            ans += n2 * min(c1 + c2, cb);
            ans += rem * min(c1, cb);
        } 

        return ans;  
    }
};