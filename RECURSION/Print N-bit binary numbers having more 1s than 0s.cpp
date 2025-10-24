// User function template for C++
class Solution {
  public:
  void solve(int ones , int zero,int n,string op,vector<string>& ans){
        if(n==0){
            ans.push_back(op);
            return;
        }
        
        // 1's
        string op1 = op;
        op1.push_back('1');
        solve(ones+1,zero,n-1,op1,ans);
        
        if(ones > zero){
            string op2 = op;
            op2.push_back('0');
            solve(ones,zero+1,n-1,op2,ans);
        }
        return;
    }
    vector<string> NBitBinary(int n) {
        // Your code goes here
        string op = "";
        int ones = 0;
        int zero = 0;
        vector<string> ans;
        solve(ones,zero,n,op,ans);
        return ans;
        
    }
    
};