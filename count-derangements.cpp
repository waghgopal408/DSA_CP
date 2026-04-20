class Solution {
  public:
  
    int fun_recursion(int n){
        if(n==1) return 0;
        if(n==2) return 1;
        
        // 0 swap with i fun(n-2) + 0 not swap with i fun(n-1)
        int ans = (n-1) * (fun_recursion(n-1) + fun_recursion(n-2));
        
        return ans;
    }
    
    int fun_memorization(int n, vector<int> &dp){
        if(n==1) return 0;
        if(n==2) return 1;
        
        if(dp[n] != -1) return dp[n];
        // 0 swap with i fun(n-2) + 0 not swap with i fun(n-1)
        dp[n] = (n-1) * (fun_memorization(n-1, dp) + fun_memorization(n-2, dp));
        
        return dp[n];
    }
    
    int fun_tabulation(int n, vector<int> &dp){
        dp[1] = 0;
        dp[2] = 1;
        
        // if(dp[n] != -1) return dp[n];
        // 0 swap with i fun(n-2) + 0 not swap with i fun(n-1)
        
        for(int i=3;i<=n;i++){
            dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
        }
        
        return dp[n];
    }
    
    int fun_tabulation_Optimized_Space(int n, vector<int> &dp){
        if(n==1) return 0;
        int pre2 = 0;
        int pre1 = 1;
        
        // if(dp[n] != -1) return dp[n];
        // 0 swap with i fun(n-2) + 0 not swap with i fun(n-1)
        
        for(int i=3;i<=n;i++){
            int ans = (i-1) * (pre1 + pre2);
            pre2 = pre1;
            pre1 = ans;
        }
        
        return pre1;
    }
    
    int derangeCount(int n) {
        // code here
        //using recursion
        // int ans = fun_recursion(n);
        
        
        //using memorization
        // vector<int> dp(n+1,-1);
        // int ans = fun_memorization(n,dp);
        
        //using tabulation
        // vector<int> dp(n+1,-1);
        // int ans = fun_tabulation(n,dp);
        
        // tabulation optimized space use prev1 and prev2 for dp[i-1] and dp[i-2]
        vector<int> dp(n+1,-1);
        int ans = fun_tabulation_Optimized_Space(n,dp);
        
        return ans;
    }
}; 

/*
🔴 1. Recursion (fun_recursion)
⏱ Time Complexity: O(2ⁿ) (Exponential)
Each call branches into two recursive calls
Many overlapping subproblems → recomputation
🧠 Space Complexity: O(n) (recursion stack)

👉 Worst among all — not practical for large n

🟡 2. Memoization (fun_memorization)
⏱ Time Complexity: O(n)
Each state n computed only once
Stored in dp[]
🧠 Space Complexity: O(n)
dp[] array → O(n)
recursion stack → O(n)

👉 Much better than recursion

🟢 3. Tabulation (fun_tabulation)
⏱ Time Complexity: O(n)
Iterative loop from 3 → n
🧠 Space Complexity: O(n)
Uses dp[] array

👉 Eliminates recursion overhead → cleaner and faster in practice

🔵 4. Space Optimized Tabulation (fun_tabulation_Optimized_Space)
⏱ Time Complexity: O(n)
Same single loop
🧠 Space Complexity: O(1)
Only two variables (pre1, pre2)
*/