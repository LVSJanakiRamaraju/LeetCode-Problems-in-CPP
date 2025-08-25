class Solution {
private:
unordered_map<char, vector<char>> graph;
 bool conn(char start, char target){
    unordered_set<char> visited;
    stack<char> st;
    st.push(start);

    while (!st.empty()) {
        char node = st.top(); st.pop();
        if (node == target) return true;
        if (visited.count(node)) continue;
        visited.insert(node);
        for (auto &nei : graph[node]) {
            if (!visited.count(nei)) st.push(nei);
        }
    }
    return false;
 }



public:
    bool equationsPossible(vector<string>& equations) {
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                char u = eq[0], v = eq[3];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        for (auto &eq : equations) {
            if (eq[1] == '!') {
                char u = eq[0], v = eq[3];
                if (u == v) return false;
                if (conn(u, v)) return false;
            }
        }
        return true;
    }
};
