class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans;
        
        int count = 0;

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                ans.push_back(count%2);
                count++;
            }
            else{
                count--;
                ans.push_back(count%2);
            }
        }

        return ans;
    }
};