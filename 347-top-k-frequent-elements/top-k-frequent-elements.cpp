class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        while(k--){
            int maxi = INT_MIN;
            int ele = 0;
            for(auto& pair:mp){
                if(pair.second>maxi){
                    maxi = pair.second;
                    ele = pair.first;
                }
            }

            ans.push_back(ele);
            mp.erase(ele);
        }

        return ans;
    }
};