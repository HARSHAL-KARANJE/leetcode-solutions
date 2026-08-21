class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int fleet=0;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        }); // postion sorted and get assigned with their time

        vector<double> time;

        for(auto car: cars){
            int pos = car.first;
            int speed =car.second;
            double t= double(target-pos)/speed;
            time.push_back(t);
        }

        stack<double> st;

        for (int i = 0; i < time.size(); i++) {
          if( st.empty() || time[i]>st.top()){
            fleet++;
            st.push(time[i]);
          }else{
            //st.push(time[i]); it catches the fleet no need to do anything 
          }
        }
        return fleet;
    }
};