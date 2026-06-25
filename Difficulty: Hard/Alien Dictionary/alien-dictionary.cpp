class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        vector<int> INdegree(26,0);
        vector<bool> present(26,false);
        
        for(auto &word:words){
            for(auto &ch:word){
                present[ch-'a'] = true;
            }
        }
        
        for(int i=1;i<words.size();i++){
            string word1 = words[i];
            string word2 = words[i-1];
            
            int size1 = word1.size();
            int size2 = word2.size();
            
            int len = min(size1,size2);
            
            bool ifPossible = false;
            
            for(int j=0;j<len;j++){
                if(word1[j]!=word2[j]){
                    ifPossible = true;
                    adj[word2[j]-'a'].push_back(word1[j]-'a');
                    INdegree[word1[j]-'a']++;
                    break;
                }
            }
            
            if(!ifPossible && size2>size1){
                return "";
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<26;i++){
            if(present[i] && INdegree[i]==0){
                q.push(i);
            }
        }
        
        int cnt=0;
        string result = "";
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result += char('a'+node);
        
            cnt++;
            
            for(auto neigh: adj[node]){
                INdegree[neigh]--;
                if(INdegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        int total=0;
        
        for(int i=0;i<26;i++){
            if(present[i]) total++;
        }
        
        return (total==cnt)? result : "";
        
    }
};