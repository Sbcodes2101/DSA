class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> prefix(n);
        int cnt=0;

        prefix[0] = nums[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
        }

        for(int i=0;i<n;i++){
            if(prefix[i]==k) cnt++;
            int remove = prefix[i]-k;
            if(mp.find(remove)!=mp.end()){
                cnt += mp[remove];
            }   
            mp[prefix[i]]++;         
        }
        return cnt;
    }
};