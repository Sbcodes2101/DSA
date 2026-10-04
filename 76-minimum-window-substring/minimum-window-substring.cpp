class Solution {
public:
    bool validWindow(unordered_map<char,int> &mp){
        for(auto it:mp){
            if(it.second>0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        unordered_map<char,int> mp;
        int min_len = INT_MAX;
        int start_index=-1;

        if(n2>n1) return "";

        for(int i=0;i<n2;i++){
            mp[t[i]]++;
        }

        int i=0;
        int j=0;

        while(j<n1){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;

                while(validWindow(mp)){
                    if(j-i+1<min_len){
                        min_len = min(min_len,j-i+1);
                        start_index = i;
                    }
                    
                    if(mp.find(s[i])!=mp.end()) mp[s[i]]++;
                    i++;
                }
            }

            j++;
        }

        return (min_len==INT_MAX)? "":s.substr(start_index,min_len);
    }
};