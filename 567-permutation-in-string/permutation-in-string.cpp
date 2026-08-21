class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1>n2) return false;
        int hash[26] = {0};

        for(int i=0;i<n1;i++){
            hash[s1[i]-'a']++;
        }

        int left = 0;
        int right = 0;
        bool check=true;

        while(right<n2){
            check = true;
            hash[s2[right]-'a']--;

            while(right-left+1>n1){
                hash[s2[left]-'a']++;
                left++;
            }
            

            if(right-left+1==n1){
                for(int i=0;i<26;i++){
                    if(hash[i]!=0){
                        check = false;
                        break;
                    }
                    else{
                        check=true;
                    }
                }
                if(check==true) return true;
            }

            right++;
        }

        return check;
    }
};