class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;

        vector<int> hash(26,0);

        for(int i=0;i<n1;i++){
            hash[s1[i]-'a']++;
        }

        int i=0;
        int j=0;

        while(j<n2){
            hash[s2[j]-'a']--;

            if(j-i+1>n1){
                hash[s2[i]-'a']++;
                i++;
            }

            if(j-i+1==n1){
                bool flag = true;
                for(int i=0;i<26;i++){
                    if(hash[i]!=0){
                        flag=false;
                        break;
                    }
                }
                if(flag==true) return true;
            }

            j++;
        }

        return false;
    }
};