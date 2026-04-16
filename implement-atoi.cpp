class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int sign = 1;
        long ans = 0;
        
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '+' || s[i] == '-'){
            sign = (s[i]=='-' ? -1:1);
            i++;
        }
        while(s[i]>='0' && s[i]<='9'){
            ans = ans * 10 + (s[i]-'0');
            i++;
            if(sign*ans >= INT_MAX) return INT_MAX;
            if(sign*ans <= INT_MIN) return INT_MIN;
        }
        
        return (int)sign*ans;
        
    }
};
