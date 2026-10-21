class Solution {
public:
    bool helper(int k, vector<int>& nums) {
        int n = nums.size();
        int prev_max = INT_MIN;

        for (int i = 0; i < n; i += k) {
            int drops = 0;
            int first_ele = nums[i];
            int last_ele = nums[i + k - 1];

            int curr_min = INT_MAX;
            int curr_max = INT_MIN;

            for (int j = i; j < i + k; j++) {
                curr_min = min(curr_min,nums[j]);
                curr_max = max(curr_max,nums[j]);

                if (j<i+k-1 && nums[j] > nums[j + 1]) {
                    drops++;
                }
            }

            if (drops > 1)
                return false;

            if (drops == 1 && last_ele > first_ele)
                return false;

            if(prev_max>curr_min) return false;

            prev_max = curr_max;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int final_ans = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (helper(i, nums)) {
                    final_ans += i;
                }
            }
        }

        return final_ans;
    }
};