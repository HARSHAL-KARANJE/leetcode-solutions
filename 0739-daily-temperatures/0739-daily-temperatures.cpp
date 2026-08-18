class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st ; // tp store the index
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i =0 ; i< n ;i++){
        while(!st.empty() &&  temp[i]>temp[st.top()]){
            int prev=st.top();
            st.pop();
            ans[prev]=i-prev;//difference of the number of days

        }
        st.push(i);
        }
        return ans;
    }
};