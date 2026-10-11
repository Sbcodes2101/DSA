class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int operations = k1+k2;
        map<int,int> mp;
        long long ans = 0;

        for(int i=0;i<n;i++){
            int diff = abs(nums1[i]-nums2[i]);
            mp[diff]++;
        }

        while(operations>0 && !mp.empty()){
            auto it = mp.rbegin();
            int val = it->first;
            int freq = it->second;

            if(val==0) break;

            if(operations>freq){
                operations -= freq;
                mp.erase(val);
                mp[val-1] += freq;
            }

            else{
                mp[val] -= operations;
                mp[val-1] += operations;
                operations = 0;
            }
        }

        for(auto it:mp){
            long long val = it.first;
            long long freq = it.second;
            ans += 1LL*val*val*freq;
        }

        return ans;
    }
};