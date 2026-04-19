class Solution {
public:
    int numberOfSubstrings(string s) {
        // brute force
        // int count = 0;
        // int n=s.size();
        // for(int i=0;i<n;i++){
        //     int hash[3] ={0};
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'a'] = 1;
        //         if(hash[0]+hash[1]+hash[2]==3){
        //             count += n-(j);
        //             break;
        //         }
        //     }
        // }
        // return count;

        int count = 0;
        int lastseen[3] = {-1,-1,-1};
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                count += n-max(lastseen[0],max(lastseen[1],lastseen[2]));
            }
        }
        return count;
    }
};