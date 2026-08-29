class Solution {
  public:
      int check(string &s,int left,int right){
          int ans=0;
            while(left>=0 && right<s.size()){
                if(s[left]==s[right]){
                    ans++;
                    left--;
                    right++;
                }
                else break;
            }
            
        return ans;
      }
  
    int countPS(string &s) {
        int n = s.size();
        
        int ans = 0;
        for(int i=1;i<n;i++){
            ans += check(s,i-1,i+1);
            ans += check(s,i-1,i);
        }
        
        
        return ans;
    }
};