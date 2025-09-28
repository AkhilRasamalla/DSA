class Solution {
  public:
  void insertBottom(stack<int> &st,int x){
      if(st.empty()){
          st.push(x);
          return;
      }
      int top = st.top();
      st.pop();
      insertBottom(st,x);
      st.push(top);
  }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int top = st.top();
        st.pop();
        reverseStack(st); //reverse remaining
        insertBottom(st,top);
        
    }
};