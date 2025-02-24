class Solution {
private:
    
   
    int maxAlice(int curr, int par, int time, int bob, vector<int>& amount){
        int maxIncome =0, maxNode = INT_MIN;

        if(curr == bob) sourceToBob[curr] = 0;
        else sourceToBob[curr] = n;

        for(int nei : adj[curr]){
            if(nei != par){
                maxNode = max(maxNode, maxAlice(nei, curr, time+1, bob, amount));

                sourceToBob[curr] = min(sourceToBob[curr], sourceToBob[nei] + 1);
            }
        }

         if(sourceToBob[curr] == time)  maxIncome += amount[curr]/2;
         if(sourceToBob[curr] > time)   maxIncome += amount[curr];

         if(maxNode == INT_MIN)     return maxIncome;
         return maxIncome + maxNode;
    }

public:

    int n;
    vector<vector<int>> adj;
    vector<int> sourceToBob;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size();
        adj.resize(n);
        sourceToBob.resize(n);
       

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return maxAlice(0, 0, 0, bob, amount);

    }
};