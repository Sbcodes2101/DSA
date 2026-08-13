class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();

        vector<int> lis(n, 1);
        vector<int> parent(n, -1);

        // Calculate LIS ending at every index
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                    parent[i] = j;
                }
            }
        }

        // Find index where LIS is maximum
        int idx = 0;

        for(int i = 1; i < n; i++) {
            if(lis[i] > lis[idx]) {
                idx = i;
            }
        }

        // Reconstruct LIS
        vector<int> ans;

        while(idx != -1) {
            ans.push_back(arr[idx]);
            idx = parent[idx];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};