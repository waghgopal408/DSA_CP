class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        //best solution    
        //sliding window O(n+m)
        int m = nums1.size(), n = nums2.size();
        int i=0, j=0, ans = 0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j - i);
                j++;
            }
            else{
                i++;
                j = max(j,i);
            }
        }

        // binary search O(nlong(m))
        // int m = nums1.size(), n = nums2.size(), ans = 0;
        // for(int i=0;i<m;i++){
        //     int left = i+1, right = n-1, best = i-1;

        //     while(left <= right){
        //         int mid = (left + right) / 2;
        //         if(nums1[i] <= nums2[mid]){
        //             best = mid;
        //             left = mid + 1;
        //         }
        //         else{
        //             right = mid - 1;
        //         }
        //     }
        //     if(best > i) ans = max(ans, best - i);
        // }
        
        return ans;

    }
};