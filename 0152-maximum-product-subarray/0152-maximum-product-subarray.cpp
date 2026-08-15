class Solution {
public:
    int maxProduct(vector<int>& nums){
        int maxPro = nums[0];
        int minPro = nums[0];
        int ans= maxPro;

        for(int i=1; i<nums.size();i++){
            int newMax=max({nums[i],nums[i]*minPro,
                          nums[i]*maxPro});
            int newMin=min({nums[i],nums[i]*minPro, 
            nums[i]*maxPro});   

            maxPro=newMax;
            minPro=newMin;

            ans= max(maxPro,ans); 
        }
        return ans;
    }
};