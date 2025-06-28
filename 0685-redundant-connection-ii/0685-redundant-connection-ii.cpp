class Solution {
public:
    bool checkCycle( unordered_map<int,unordered_set<int>>mp,int n)
    {
        vector<int>indegree(n+1,0);
        vector<int>ans;
        for(int i=1;i<=n;i++){
          for(auto it:mp[i])
              indegree[it]++;
        }
        
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0)  q.push(i);         
            if(indegree[i]>=2)  return false; 
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:mp[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);  
            }  
        }
        
        if(ans.size()!=n)   return false;
        
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,unordered_set<int>>mp;
        for(auto it:edges)  mp[it[0]].insert(it[1]);
        
        for(int i=n-1;i>=0;i--){
            mp[edges[i][0]].erase(edges[i][1]);
            if(checkCycle(mp,n)==true)  return edges[i];
            else    mp[edges[i][0]].insert(edges[i][1]);
        }
        return {};
    }
};