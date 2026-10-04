class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int max_open = 0;
        int min_open = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                max_open++;
                min_open++;
            }

            else if(s[i]=='*'){
                max_open++;
                min_open--;
                if(min_open<0) min_open = 0;
            }

            else{
                max_open--;
                if(max_open<0) return false;
                min_open--;
                if(min_open<0) min_open = 0;
            }
        }

        return (min_open==0);

    }
};