class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9+7;
        vector<vector<pair<int, int>>> graph(n);

        for(auto road : roads){
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;

        vector<long long> time(n, LLONG_MAX);
        vector<int> path(n);

        time[0] = 0;
        path[0] = 1;

        minHeap.emplace(0, 0);

        while(!minHeap.empty()){
            long long currTime = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();

            if(currTime <= time[currNode]){
                for(auto [adj, t] : graph[currNode]){
                    if(currTime + t < time[adj]){
                        time[adj] = currTime + t;
                        path[adj] = path[currNode];
                        minHeap.emplace(currTime + t, adj);
                    } 
                    else if(currTime + t == time[adj]){
                        path[adj] = (path[adj] + path[currNode])%MOD;
                    }
                }
            }
        }
        return path[n-1];
    }
};