class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int window = min((int)nums.size(), k);
        for(int i=0;i<window;i++){
            if(st.find(nums[i])!=st.end()) return true;
            st.insert(nums[i]);
        }

        for(int i=window;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()) return true;

            st.insert(nums[i]);
            st.erase(nums[i-window]);
        }

        return false;
    }
};