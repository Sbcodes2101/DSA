class Solution {
  public:
    int check(vector<int> &arr,int k,int pages){
        int n=arr.size();
        int student=1;
        int noOfPages = 0;
        for(int i=0;i<n;i++){
            if(noOfPages+arr[i] <= pages){
                noOfPages += arr[i];
            }
            else{
                student++;
                noOfPages = arr[i];
            }
        }
        return student;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int lo=*max_element(arr.begin(),arr.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        int hi=sum;
        if(k>n) return -1;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            int students = check(arr,k,mid);
            
            if(students>k){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
    }
};