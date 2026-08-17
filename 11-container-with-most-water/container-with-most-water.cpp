class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;int j=n-1;
        int maximumArea = INT_MIN;
        while(j>i){
            if(height[j]>height[i]){
                maximumArea = max(maximumArea,height[i]*(j-i));
                i++;
            }
            else{
                maximumArea = max(maximumArea,height[j]*(j-i));
                j--;
            }
        }

        return (maximumArea==INT_MIN)? 0:maximumArea;
    }
};