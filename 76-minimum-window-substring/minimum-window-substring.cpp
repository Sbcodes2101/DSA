class Solution {
public:
    bool isValidWindow(unordered_map<char,int> &mp){
        for(auto it:mp){
            if(it.second > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if (n2>n1) return "";
 
        unordered_map<char,int> mp;

        for(int i=0;i<n2;i++){
            mp[t[i]]++;
        }

        int i=0;
        int j=0;
        int minWindow = INT_MAX;
        int start_idx = 0;

        while(j<n1){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                while(isValidWindow(mp)){
                    if(j-i+1<minWindow){
                        minWindow = min(minWindow,j-i+1);
                        start_idx = i;
                    }
                    
                    if(mp.find(s[i])!=mp.end()) mp[s[i]]++;
                    i++;
                }
            }

            j++;
        }

        return (minWindow==INT_MAX)? "":s.substr(start_idx,minWindow);
    }
};