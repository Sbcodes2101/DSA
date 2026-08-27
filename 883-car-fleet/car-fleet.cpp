class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> ans;

        for(int i=0;i<n;i++){
            double time = double(target-position[i])/double(speed[i]);
            ans.push_back({position[i],time});
        }

        sort(ans.begin(),ans.end());

        int carfleet = 1;
        double maxTime = ans[n-1].second;
        for(int i=n-2;i>=0;i--){
            if(ans[i].second>maxTime){
                carfleet++;
                maxTime = ans[i].second;
            }
            if(ans[i].second<=maxTime) continue;
        }

        return carfleet;
    }
};