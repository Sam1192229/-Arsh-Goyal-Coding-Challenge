class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        if(n==k)return sum;
        int l=k-1;
        int r=nums.size()-1;
        int maxsum=sum;
        while(l>=0){
       sum+= nums[r]-nums[l];
       r--;
       l--;
       maxsum=max(sum,maxsum);  //initialize maxsum with sum to accoutn for the
       // first window if you do this in the top you will miss the last window
        }
        return maxsum;
    }
};