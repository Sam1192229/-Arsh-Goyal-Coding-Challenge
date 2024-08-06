class Solution {
    void perms(vector<vector<int>>&ans, vector<int>temp, vector<int>&nums, unordered_map<int,int>&mp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }

        for(int i=0;i<nums.size();i++){
         if(i>0 && nums[i]==nums[i-1] && mp[i-1]==0){continue;}
            if(mp[i]==0){
                mp[i]=1;
                temp.push_back(nums[i]);
                perms(ans, temp, nums, mp);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_map<int,int>mp;
        perms(ans,temp, nums,mp );
        return ans;
    }
};