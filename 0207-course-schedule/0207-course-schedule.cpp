class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<bool> vis(n, false);
        for(auto & pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i : adj[curr]){
                indegree[i]--;
                if(indegree[i] == 0){
                    if(vis[i] == false){
                    q.push(i);
                    vis[i] = true;
                }
                }
            }
        }

        for(bool i : vis){
            if(i == false)  return false;
        }

    return true;

    }
};