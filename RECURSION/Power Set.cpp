class Solution {
  public:
  void solve(string ip , string op, vector<string>& ans){
      if(ip.empty()){
          ans.push_back(op);
          return;
      }
      string op1 = op;
      string op2 = op;
      
      op2.push_back(ip[0]);
      
      ip.erase(ip.begin());
      
      solve(ip,op1,ans);
      solve(ip,op2,ans);
  }
    vector<string> AllPossibleStrings(string s) {
        // Code here
         vector<string> ans;
         string op ="";
         solve(s,op,ans);
         sort(ans.begin(),ans.end());
         return ans;
         
        
    }
};