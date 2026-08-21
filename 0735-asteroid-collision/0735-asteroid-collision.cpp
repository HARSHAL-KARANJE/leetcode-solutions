class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int i=0; i<asteroids.size();i++){
            int curr= asteroids[i];
          while(!st.empty() && st.top()>0 && curr<0){//they will collide
                if(st.top()<abs(curr)){
                    st.pop();
                }else if(st.top()==abs(curr)){
                         curr=0;
                         st.pop();
                         break; // need  to proceed further
                }else{
                    curr=0;
                    break;
                }
          }
          if(curr!=0){
           st.push(curr);
          };

        }

        // now we have stack that is reaming so we nned to print that 
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};