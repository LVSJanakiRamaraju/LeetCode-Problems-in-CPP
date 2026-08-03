class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        if(planks.size() == 1)  return 1;

        unordered_map<int, int>freq;
        for(int x:planks)   freq[x]++;

        vector<int> val;
        for(auto&[h,c]:freq)    val.push_back(h);

        unordered_map<int, int> pars;
        int n=val.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=val[i]+val[j];
                if(i==j){
                    pars[sum]+=freq[val[i]]/2;
                }else{
                    pars[sum]+=min(freq[val[i]],freq[val[j]]);
                }
            }
        }
        int ans=0;
        for(auto &[h,cnt]:pars){
            ans=max(ans,cnt+freq[h]);
        }
         for(auto &[h,cnt]:freq)    ans=max(ans,cnt);
        

        return ans;
    }
};