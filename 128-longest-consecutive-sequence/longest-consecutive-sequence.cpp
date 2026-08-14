class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());

        int ans = INT_MIN;
        for (int num : st) {
    if (st.find(num - 1) == st.end()) {
        int currentele = num;
        int currentStreak = 1;

        while (st.find(currentele + 1) != st.end()) {
            currentele += 1;
            currentStreak += 1;
        }
        ans = max(ans, currentStreak);
    }
}

        return (ans==INT_MIN)? 0:ans;
    }
};