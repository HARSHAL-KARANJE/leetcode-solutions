class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.length();
        stack<int>st;
        for(int i=0 ;i< n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if still some k are remaining then for them 
        while(!st.empty()&& k>0){
            st.pop();
            k--;
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

// what is starting is the zero 
     int i=0;
     while(i<ans.size() && ans[i]=='0'){
        i++;
     }
     ans =ans.substr(i);
        if(ans==""){// if it get empty
            return "0";
        }

        return ans;
    }
};