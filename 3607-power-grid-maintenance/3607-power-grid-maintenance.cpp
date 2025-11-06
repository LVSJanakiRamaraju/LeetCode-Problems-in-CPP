class DSU {
public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=1; i<=n; i++)  parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)  
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py)  parent[py] = px;
    }
    

};





class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for(const auto& conn : connections){
            dsu.unite(conn[0], conn[1]);
        }
        unordered_map<int, set<int>> map;
        for(int i=1; i<= c; i++){
            int root = dsu.find(i);
            map[root].insert(i);
        }

        vector<bool> online(c+1, true);
        vector<int> result;
        for(const auto&q : queries){
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if(type == 1){
                if(online[x]){
                    result.push_back(x);
                }
                else{
                    auto& ops = map[root];
                    if(ops.empty()) result.push_back(-1);
                    else result.push_back(*ops.begin());
                }
            }
            else if(type == 2){
                if(online[x]){
                    online[x] = false;
                    map[root].erase(x);
                }
            }
        }

        return result;









        
    }
};