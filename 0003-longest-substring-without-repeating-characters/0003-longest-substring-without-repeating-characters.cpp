class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int ans = 0;

        vector<int> freq(256, 0) ;// size 25t6 size all intialize to zero

            while (right < s.size()) {
            // push right to freq array (only 1 char at a time pushing)
            freq[s[right]]++;

            while (freq[s[right]]>1){
                freq[s[left]]--;
                left++;// remove until we have the freq of the right equal to 1 as we are moving left pointer it can aslo reach left=right at last 
            }
            ans=max(ans, right-left+1);

            right++;
        }
        return ans;
    }
};