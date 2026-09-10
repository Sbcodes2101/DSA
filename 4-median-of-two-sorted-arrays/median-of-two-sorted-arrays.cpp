class Solution {
public:
    double findMedian(vector<int>& nums1,vector<int>& nums2){
        int lo = 0;
        int hi = nums1.size();   
        int len = nums1.size()+nums2.size();         
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            int p =  (len+1)/2-mid;
            int l1 = (mid==0)? INT_MIN:nums1[mid-1];
            int r1 = (mid==nums1.size())? INT_MAX:nums1[mid];
            int l2 = (p==0)? INT_MIN:nums2[p-1];
            int r2 = (p==nums2.size())? INT_MAX:nums2[p];
            if(l1<=r2 && l2<=r1){
                if((nums1.size()+nums2.size())%2 == 0){
                    return ((double)(max(l1,l2)+min(r1,r2))/2);
                }
                else{
                    return (double)max(l1,l2);
                }
            }

            else if(l2>r1){
                lo=mid+1;
            }

            else if(l1>r2){
                hi=mid-1;
            }
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int len =n1+n2;
        if(n2>n1){
            return findMedian(nums1,nums2);
        }
        else{
            return findMedian(nums2,nums1);
        }
        return 0.0;
    }
};