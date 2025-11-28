class Solution {
public:
    vector<vector<int>> adj;
    int res = 1;

    long dfs(int u, int p, vector<int>& values, int k) {
        long sum = values[u];
        
        for(int v : adj[u]) {
            if(v == p)
                continue;

            long sub = dfs(v, u, values, k);

            if(sub % k == 0)
                res += 1;

            else
                sum += sub;
        }

        return sum;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, values, k);
        return res;
    }
};