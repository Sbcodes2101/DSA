class Solution {
public:
    int digitSum(int number){
        int sum = 0;
        while(number>0){
            int n = number%10;
            sum += n;
            number = number/10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<vector<int>> sortedmaplist;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }

        for(int i=0;i<n;i++){
            int sum = digitSum(nums[i]);
            sortedmaplist.push_back({sum,nums[i],i});
        }

        sort(sortedmaplist.begin(),sortedmaplist.end());

        int i = 0;
        while(i<sortedmaplist.size()){
            int ele = sortedmaplist[i][1];
            
            if(mp[ele] == i){
                i++;
            }
            

            else{
                int curr_idx = mp[ele];
                swap(nums[i],nums[curr_idx]);
                mp[nums[curr_idx]] = curr_idx;
                mp[nums[i]] = i;
                count++;
            }
        }

        return count;
    }
};