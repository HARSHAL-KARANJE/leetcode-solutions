class Solution {
public:
    bool canCross(vector<int>& stones) {
        // we will use the unorder_set to map the store a stones and their previous jump to calculate all posible next jumps 
        unordered_map<int,unordered_set<int>>mp;
        mp[1]={1};
        for(int i=1;i<stones.size(); i++){
            // started from 1 becz we knwo the previous to reach the 1st posiion from zeroth
            for(auto jumpSize : mp[stones[i]]){
              mp[stones[i]+jumpSize].insert(jumpSize);
              mp[stones[i]+jumpSize+1].insert(jumpSize+1);
              mp[stones[i]+jumpSize-1].insert(jumpSize-1);
              
            }
        }
        return mp[stones.back()].size()!=0;
    }
};