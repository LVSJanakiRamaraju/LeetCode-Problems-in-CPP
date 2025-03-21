class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> recipes_mp;
        unordered_set<string> supp;
        unordered_map<string, int> index;
        int n = recipes.size();

        vector<int> inDegree(n, 0);

        for(int i=0; i<n; i++){
            index[recipes[i]] = i;
        }

        for(string str : supplies){
            supp.insert(str);
        }

        for(int i=0; i<n; i++){
            for(string str : ingredients[i]){
                if(!supp.count(str)){
                    recipes_mp[str].push_back(recipes[i]);
                    inDegree[i]++;
                }
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0)    q.push(i);
        }

        vector<string> result;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            string rec = recipes[idx];
            result.push_back(rec);
            if(!recipes_mp.count(rec)) continue;

            for(string str : recipes_mp[rec]){
                inDegree[index[str]]--;
                if(inDegree[index[str]] == 0){
                    q.push(index[str]);
                }
            }
        }


        return result;
    }
};