class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;

        int i=0;
        int j=0;

        while(j<nums.size()){
           while(!q.empty() && nums[j]>nums[q.back()]){
            q.pop_back();
            }

            q.push_back(j);

           
            if(i>q.front()){
                q.pop_front();
            }
           
           if(j-i+1==k){
            ans.push_back(nums[q.front()]);
            i++;
           }
           
           j++;
        }

        return ans;
    }
};