class Solution {
public:
    int digitSum(int number){
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
        vector<vector<int>> sortedlist;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            int sum = digitSum(nums[i]);
            sortedlist.push_back({sum,nums[i],i});
        }

        sort(sortedlist.begin(),sortedlist.end());

        int count=0;

        for(int i=0;i<n;i++){

            if(visited[i] || sortedlist[i][2]==i){
                continue;
            }

            int curr_idx = i;
            int windowsize = 0;

            while(!visited[curr_idx]){
                visited[curr_idx] = true;
                curr_idx = sortedlist[curr_idx][2];
                windowsize++;
            }

            if(windowsize>0){
                count += windowsize-1;
            }
        }

        return count;
    }
};