class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        int result = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vector<int> path;
                vis[i] = true;
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    path.push_back(curr);

                    for(int neigh : graph[curr]){
                        if(!vis[neigh]){
                            q.push(neigh);
                            vis[neigh] = true;
                        }
                    }
                }

                bool isComplete = true;
                for(int n : path){
                    if(graph[n].size() != path.size()-1){
                        isComplete = false;
                        break;
                    }
                }

                if(isComplete)  result++;

            }
        }

        return result;
    }
};