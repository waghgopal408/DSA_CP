// leetcode 3488
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size(), m = nums.size();
        vector<int> ans(n,-1);
        unordered_map<int, vector<int>> mp;
        

        //store index of each element in nums
        for(int i = 0;i<m;i++){
            mp[nums[i]].push_back(i);
        }
        for(int i = 0;i<n;i++){
            int idx = queries[i];
            int val = nums[idx];

            if(mp[val].size()==1) continue;

            // int prev_idx = -1, next_idx = -1;
             
            auto &arr = mp[val];
            int low = 0, high = arr.size() - 1, sz = high+1;
            
            // binary search to find required index and then minimum distance will either next or previous index, handle edge element properly
            while(low <= high){
                int mid = low + (high - low)/2;
                if(arr[mid] == idx){
                    ans[i] = INT_MAX;
                    // if(mid-1 > 0){
                    //     ans[i] = min(abs(arr[mid-1 ]- idx), m- abs(arr[mid-1] - idx));
                    // }
                    // if(mid+1 < sz-1){
                    //     ans[i] = min(ans[i], min(abs(arr[mid+1] - idx), m- abs(arr[mid+1] - idx)));
                    // }
                    // if(mid == 0){
                    //     ans[i] = min(abs)
                    // }

                    int pre = (mid-1 + sz) % sz;
                    int next = (mid + 1 + sz) % sz;

                    ans[i] = min(abs(arr[pre] - idx), m - abs(arr[pre] - idx));
                    ans[i] = min(ans[i], min(abs(arr[next] - idx), m - abs(arr[next] - idx)));
                    
                    break;
                }
                else if(arr[mid] > idx) high = mid-1;
                else low = mid+1;
            }
        }
        return ans;
    }
};


//brute force
// vector<int> ans(n,-1);
        // for(int i=0;i<n;i++){
        //     int idx = queries[i];
        //     for(int j = idx + 1;j<m;j++){
        //         if(nums[j] == nums[idx]){
        //             if(ans[i] != -1){
        //                 ans[i] = min(ans[i], min(abs(j-idx),m-abs(j-idx)));
        //             }
        //             else  ans[i] = min(abs(j-idx),m-abs(j-idx));
        //         }
        //     }
        //     for(int j = idx - 1;j>=0;j--){
        //         if(nums[j] == nums[idx]){
        //             if(ans[i] != -1){
        //                 ans[i] = min(ans[i], min(abs(j-idx),m-abs(j-idx)));
        //             }
        //             else  ans[i] = min(abs(j-idx),m-abs(j-idx));
        //         }
        //     }
        // }