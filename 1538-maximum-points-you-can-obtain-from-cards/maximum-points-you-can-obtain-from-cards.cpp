class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        int maxSum = INT_MIN;

        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
        }

        maxSum = max(maxSum,lsum);
        int rightIdx = n-1;
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIdx];
            rightIdx--;
            maxSum = max(maxSum,lsum+rsum);
        }

        return maxSum;
    }
};