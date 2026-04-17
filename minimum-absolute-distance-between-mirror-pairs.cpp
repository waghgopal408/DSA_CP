class Solution {
public:

    int rev(int n){
        int ans = 0;
        while(n){
            ans = ans*10 + n%10;
            n/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int val = rev(nums[i]);

            if(mp.contains(nums[i])){
                ans = min(ans,abs(i-mp[nums[i]]));
            }
            mp[val] = i;
        }
        return ans==INT_MAX ? -1:ans ;
    }
};