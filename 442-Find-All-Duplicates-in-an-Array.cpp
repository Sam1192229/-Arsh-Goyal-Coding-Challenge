class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //cyclic sort -you are good bro
        for(int i=0;i<nums.size();i++){
            while(nums[i]!= nums[nums[i]-1]){
                //its asking the desired place whether you got the correct number, if not take it because i have it so this will stop if a duplicate is at the current location and at desired location

                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};