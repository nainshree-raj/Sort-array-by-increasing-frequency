class Solution {
public:
     static bool cmp(pair<int,int>&a,pair<int,int>&b)
        {
          if(a.first==b.first)
          {
              return a.second>b.second;
          }
          return a.first < b.first;
        }
    vector<int> frequencySort(vector<int>& nums) {
       unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int n = nums.size();
        vector<pair<int,int>> pr;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pr.push_back({it->second,it->first});
        }
        sort(pr.begin(),pr.end(),cmp);
        
        vector<int>ans;
        for(auto j=0;j<pr.size();j++)
        {
            pair<int,int>p = pr[j];
            while(p.first>0)
            {
                ans.push_back(p.second);
                p.first--;
            }  
        }
        return ans;
    }
};
