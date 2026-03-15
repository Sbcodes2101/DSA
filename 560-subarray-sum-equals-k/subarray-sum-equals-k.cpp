class Solution {
public:
    // it is subarray and not subsequence
    // int subsum(vector<int>& nums,int k,int i,int count){
    //     int n=nums.size();
    //     if(i>=n-1) return count;
    //     if(nums[i]==k) {
    //         count++;
    //     }

    //     int select = subsum(nums,k-nums[i],i+1,count);
    //     int notselect = subsum(nums,k,i+1,count);

    //     return select+notselect;
    // }

    int subarraySum(vector<int>& nums, int k) {
        // brute force using exra space maps
        // int n=nums.size();
        // unordered_map<int,int> mp;
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==k) count++;
        //     if(k>nums[i]){
        //         if(mp.find(k-nums[i])==mp.end()){
        //             mp[nums[i]]=i;
        //         }
        //         else if(mp.find(k-nums[i])!=mp.end()) count++;
        //     }
        // }
        // return count;
        // using recursion
            // int count=0;
            // return subsum(nums,k,0,count);
            // return count;

        // using prefix sum(most oprimized)
        int n=nums.size();
        int count=0;
        vector<int> prefix(n);

        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        unordered_map<int,int> mp;

        for(int j=0;j<n;j++){
            if(prefix[j]==k) count++;
            int val=prefix[j]-k;

            if(mp.find(val)!=mp.end()){
                count += mp[val];
            }
            mp[prefix[j]]++;
        }
        return count;
    }
};