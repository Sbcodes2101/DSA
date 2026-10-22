class Solution {
public:
    int digitsum(int number){
        int ans = 0;
        while(number>0){
            int n = number%10;
            ans += n;
            number = number/10;
        }

        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sorted_list;
        vector<bool> visited(n,false);
        int ans = 0;

        for(int i=0;i<n;i++){
            int num = digitsum(nums[i]);
            sorted_list.push_back({num,nums[i],i});
        }

        sort(sorted_list.begin(),sorted_list.end());

        for(int i=0;i<n;i++){
            if(visited[i]==true || sorted_list[i][2] == i){
                continue;
            }

            int curr_index = i;
            int window_size = 0;

            while(!visited[curr_index]){
                visited[curr_index] = true;
                curr_index = sorted_list[curr_index][2];
                window_size++;
            }

            if(window_size>0){
                ans += window_size-1;
            }
        }

        return ans;
    }
};