class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans;
        stack<int> st;
        vector<int> nge(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
            if(!st.empty() && temperatures[st.top()]>temperatures[i]) nge[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            if(nge[i]==-1) ans.push_back(0);
            else ans.push_back(nge[i]-i);
        }

        return ans;
    }
};