class Solution {
  public:
  void solve(string ip , string op,vector<string>& ans){
      if(ip.length()==0){
         ans.push_back(op);
         return;
      }
      string op1 = op;
      string op2 = op;
      op1.push_back(' ');
      op1.push_back(ip[0]);
      op2.push_back(ip[0]);
      
      ip.erase(ip.begin());
      
      solve(ip,op1,ans);
      solve(ip,op2,ans);
  }

    vector<string> permutation(string s) {
        // Code Here
        vector<string> ans;
        string op = "";
        op.push_back(s[0]);
        s.erase(s.begin());
        solve(s,op,ans);
        sort(ans.begin() , ans.end());
        return ans;
        
        
    }
};