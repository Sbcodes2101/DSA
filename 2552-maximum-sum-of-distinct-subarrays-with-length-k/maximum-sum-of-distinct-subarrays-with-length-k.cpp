class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // long long ans = INT_MIN;
        // long long sum = 0;
        // int n = nums.size();

        // for(int i=0;i<=n-k;i++){
        //     unordered_set<int> st;
        //     bool isDuplicate = false;
        //     sum=0;
        //     for(int j=i;j<=i+k-1;j++){
        //         if(st.find(nums[j])!=st.end()){
        //             isDuplicate = true;
        //             break;
        //         }

        //         st.insert(nums[j]);
        //         sum += nums[j];
        //     }

        //     if(!isDuplicate){
        //         ans = max(ans,sum);
        //     }
        // }

        // return (ans==INT_MIN)? 0:ans;

        // USING TWO POINTERS

        int n = nums.size();
        long long sum = 0;
        long long ans = INT_MIN;
        int i=0; int j=0;
        int isDuplicate = 0;
        unordered_map<int,int> mp;

        for(int j=0;j<k;j++){
            if(mp.find(nums[j])==mp.end()){
                mp[nums[j]] = 0;
            }

            mp[nums[j]]++;

            sum += nums[j];


            if(mp[nums[j]]>1){
                isDuplicate++;
            }
        }

        if(isDuplicate==0){
            ans = max(ans,sum);
        }

        for(int i=k;i<n;i++){
            int numToAdd = nums[i];
            int numToRemove = nums[i-k];

            if(mp.find(numToAdd) == mp.end()){
                mp[numToAdd] = 0;
            }

            mp[numToAdd]++;

            if(mp[numToAdd]>1){
                isDuplicate++;
            }

            sum += numToAdd;


            if(mp[numToRemove]>1){
                isDuplicate--;
            }

            mp[numToRemove]--;

            sum -= numToRemove;

            if(isDuplicate == 0){
                ans = max(ans,sum);
            }
        }
        
        return (ans==INT_MIN)? 0:ans;
    }
};