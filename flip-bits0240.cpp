class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        int sum = 0, ans = 0, total_one = 0;
        
        for(int i=0;i<n;i++){
            
            // consider 0-> +1 and 1-> -1 while flipping
            if(arr[i] == 0) sum++;
            else {
                sum--;
                total_one++;
            }

            sum = max(sum,0);
            ans = max(sum,ans);
        }
        // adding total_one to answer bacause we have minus all ones from subarray but its value in ans is 0
        return ans + total_one;
    }
};