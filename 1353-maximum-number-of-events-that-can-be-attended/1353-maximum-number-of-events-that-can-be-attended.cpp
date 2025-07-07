class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int maxDay = 0;
        for(auto e : events){
            maxDay = max(maxDay, e[1]);
        }
        int attend = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int j =0;
        for(int i=1; i<=maxDay; i++){
            while(j < n && events[j][0] <= i){
                pq.push(events[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }


            if(!pq.empty()){
                pq.pop();
                attend++;
            }
        }

        return attend;
    }
};