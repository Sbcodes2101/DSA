class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //  int n=nums.size();
        //  int i=0;
        //  int j=1;
        //  if(n==2){
        //     if(nums[i]==0) swap(nums[i],nums[j]);
        //     else if(nums[j]!=0) return;
        //  }
        //  if(n==3) {
        //       while(j<=n-1){
        //  if(nums[i]==0 && nums[j]!=0){
        //      swap(nums[i],nums[j]);
        //      i++;
        //      j++;
        //    }
        //    else if(nums[j]==0 ){
        //        i++;
        //        j++;
        //    }
        //  }
        //  }
        //  if(n==1) return;
        //  while(j<=n-1){
        //  if(nums[i]==0 && nums[j]!=0){
        //      swap(nums[i],nums[j]);
        //      i++;
        //      j++;
        //    }
        //   else if(nums[j]==0 ) j++;
        //  }
        
        int j=-1;
        if(nums.size()==1) return;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};