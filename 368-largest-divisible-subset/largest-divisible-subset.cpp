class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {nums[0]};
        vector<int> LDS(n,1);
        vector<int> parent(n,-1);
        vector<int> ans;
        sort(nums.begin(),nums.end());

        int maxlen = INT_MIN;
        int idx=-1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && LDS[i]<1+LDS[j]){
                    LDS[i] = 1+LDS[j];
                    parent[i] = j;
                }
            }

            if(LDS[i]>maxlen){
                maxlen = LDS[i];
                idx = i;
            }
        }

        while(idx!=-1){
            ans.push_back(nums[idx]);
            idx = parent[idx];
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};