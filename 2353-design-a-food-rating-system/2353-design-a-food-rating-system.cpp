class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> ratting;
    unordered_map<string, pair<int, string>> mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            mp[foods[i]] = {-ratings[i], cuisines[i]};
            ratting[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = mp[food].second;
        int i = mp[food].first;
        mp[food] = {-newRating, cuisine};
        ratting[cuisine].erase({i, food});
        ratting[cuisine].insert({-newRating, food});

    }
    
    string highestRated(string cuisine) {
        return ratting[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */