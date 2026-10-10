class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        map<int, int> mp;
        long long ans = 0;

        int k = k1 + k2;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            mp[diff]++;
        }

        while (k > 0 && !mp.empty()) {
            auto it = mp.rbegin();
            int val = it->first;
            int freq = it->second;

            if (val == 0)
                break;

            if (k > freq) {
                k -= freq;
                mp.erase(val);
                mp[val - 1] += freq;
            }

            else {
                mp[val] -= k;
                mp[val - 1] += k;
                k = 0;
            }
        }

        for (auto it : mp) {
            ans += 1LL * it.first * it.first * it.second;
        }

        return ans;
    }
};