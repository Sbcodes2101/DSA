class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, c3 = costBoth;
        long long n1 = need1, n2 = need2;
        long long ans = 0;

        if(c3<c1 && c3<c2){
            return max(n1,n2)*c3;
        }

        if(n1<n2){
            int rem = n2-n1;
            ans += n1*min(c1+c2,c3);
            ans += rem*min(c2,c3);
        }

        else{
            int rem = n1-n2;
            ans += n2*min(c1+c2,c3);
            ans += rem*min(c1,c3);
        }

        return ans;
    }
};