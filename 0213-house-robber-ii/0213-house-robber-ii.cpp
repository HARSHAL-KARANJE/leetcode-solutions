class Solution {
public:
    int helper(vector<int>& nums , int st, int end){
        int n = nums.size();
        //dp vector to store the answer for each ith house
        vector<int>dp(n-1); //dp only will have n-1 elements becz of circular
        dp[0]=nums[st];
        dp[1]=max(nums[st],nums[st+1]);

        for(int i=st+2, j=2 ;i<=end ; i++,j++){
            dp[j]= max(dp[j-2]+nums[i],dp[j-1]);
        }
        return dp[n-2];//n-1 size element is there and started form 0 we have n-2 as our last element totoal n in nums but we know we  will take n-1 at a time becs for the circular
    }
    int rob(vector<int>& nums) {
    if(nums.size()==1) return  nums[0];
    if(nums.size()==2) return max(nums[0], nums[1]);

        return  max(helper(nums,0,nums.size()-2),
        helper(nums,1 ,nums.size()-1));
    }
};