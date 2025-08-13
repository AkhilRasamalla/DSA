// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

*/
vector<int> displayList(Node *tail) {
    vector<int>ans;
    Node* curr = tail;
    while(curr != nullptr){
        ans.push_back(curr->data);
        curr = curr -> next;
        
    }
    return ans;
}
