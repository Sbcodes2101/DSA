class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Brute force approach
        // int maxlen=INT_MIN;
        // for(int i=0;i<fruits.size();i++){
        // set<int> st;
        //     for(int j=i;j<fruits.size();j++){
        //         st.insert(fruits[j]);
        //         if(st.size()<=2) maxlen=max(maxlen,j-i+1);
        //     }
        // }
        // return maxlen;
        // sliding window
        int n=fruits.size();
        unordered_map<int,int> mp;
        int maxlen = INT_MIN;
        int l=0;int r=0;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
                }
            }
            
            maxlen=max(maxlen,r-l+1);
            r++;
        }

        return maxlen;
    }
};