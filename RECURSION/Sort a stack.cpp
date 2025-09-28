class Solution {
  public:
  void insertSorted(stack<int> &st,int x){
       // If stack is empty OR top is smaller, push directly
      if(st.empty() || st.top() <= x){
          st.push(x);
          return;
      }
       // Otherwise, pop top and recurse
      int temp = st.top();
      st.pop();
      insertSorted(st,x);
      
      // Put the popped element back
      st.push(temp);
      
  }
  // Step 2: Recursive function to sort the stack
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
         // Pop the top element
        int x = st.top();
        st.pop();
        
            // Sort the remaining stack
        sortStack(st);
        
            // Step 3: Insert popped element back in sorted order

        insertSorted(st,x);
        
    }
};
