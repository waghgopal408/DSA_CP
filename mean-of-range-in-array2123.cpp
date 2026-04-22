// prefix sum logic
// tc = O(n+m)
// sc = O(n)

class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int> prefix_sum(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            prefix_sum[i] = sum;
            sum+= arr[i];
        }
        
        int m = queries.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            ans[i] = (prefix_sum[r] - prefix_sum[l] + arr[r]) / (r-l + 1);
        }
        return ans;
        
    }
};