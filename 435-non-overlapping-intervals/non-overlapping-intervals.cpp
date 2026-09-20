class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int ans = 0;
        int prev_end = intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev_end){
                ans++;
                prev_end = min(intervals[i][1],prev_end);
            }
            else{
                prev_end = intervals[i][1];
            }
        }  

        return ans;
    }
};