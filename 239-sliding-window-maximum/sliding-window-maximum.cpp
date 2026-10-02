class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          vector<int> ans;
          deque<int> dq;
          int i=0;
          int j=0;
          int n = nums.size();

          while(j<n){
            while(!dq.empty() && nums[j]>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);

            if(j-i+1>k){
                i++;
                if(i>dq.front()) dq.pop_front();
            }

            if(j-i+1==k){
                ans.push_back(nums[dq.front()]);
            }

            j++;
          }

        return ans;
    }
};