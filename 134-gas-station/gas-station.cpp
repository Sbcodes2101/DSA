class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int netcost = 0;

        for(int i=0;i<n;i++){
            netcost += gas[i]-cost[i];
        }

        if(netcost<0) return -1;

        int start_index=0;
        int current_tank = 0;

        for(int i=0;i<n;i++){
            current_tank += gas[i]-cost[i];
            if(current_tank<0){
                current_tank = 0;
                start_index=i+1;
            }
        }

        return start_index;
    }
};