class Solution {
public:
    vector<string> result;
    unordered_set<string> words;
    unordered_map<string, string> cap, vow;
    string vowel(string& w){
        string ans = "";
        for(auto ch : w){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')   ans += "*";
            else    ans += ch;
        }
        return ans;
    }

    string solve(string q){
        if(words.find(q) != words.end())    return q;

        transform(q.begin(), q.end(), q.begin(), ::tolower);
        
        if(cap.find(q) != cap.end())    return cap[q];

        string x = vowel(q);
        if(vow.find(x) != vow.end())    return vow[x];

        return "";
    }


    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        

        for(auto w : wordlist){
            words.insert(w);
            string l = w;
            transform(l.begin(), l.end(), l.begin(), ::tolower);
            cout<<w<<l<<endl;
            string v = vowel(l);
            if(cap.find(l) == cap.end())    cap[l] = w;
            if(vow.find(v) == vow.end())    vow[v] = w;
        }

        for(string q : queries){
            string ele = solve(q);
            result.push_back(ele);
        }

        return result;
    }
};