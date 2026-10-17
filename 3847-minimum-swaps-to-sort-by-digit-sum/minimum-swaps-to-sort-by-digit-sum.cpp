class Solution {
public:
    int digitsum(int number) {
        int ans = 0;
        while (number > 0) {
            int n = number % 10;
            ans += n;
            number = number / 10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> sortedlist;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int sum = digitsum(nums[i]);
            sortedlist.push_back({sum, nums[i], i});
        }

        sort(sortedlist.begin(), sortedlist.end());

        for (int i = 0; i < n; i++) {
            int window_size = 0;
            int curr_idx = i;

            if (visited[i] || sortedlist[i][2] == i)
                continue;

            while (!visited[curr_idx]) {
                visited[curr_idx] = true;
                curr_idx = sortedlist[curr_idx][2];
                window_size++;
            }

            if (window_size > 0) {
                count += window_size - 1;
            }
        }

        return count;
    }
};