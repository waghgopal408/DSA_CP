class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int low = 0, high = n-1, max_water = 0;

        while(low < high){
            int curr_water = min(height[(low)], height[(high)]) * (high - low);
            max_water = max(max_water, curr_water);
            if(height[(low)] <= height[(high)]) low++;
            else high--;
        }
        return max_water;
    }
};
