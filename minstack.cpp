class MinStack {
public:
struct ListNode{
    int val;
    int mini;
    ListNode* next;
    ListNode(int x, int m ){
        val=x;
        mini=m;
        next=NULL;
    }


};
ListNode* topi;
    MinStack() {
        topi=NULL;
        
    }
    
    void push(int val) {
        if(topi==NULL){
            topi=new ListNode(val,val);
        }else{
            int m=min(val,topi->mini);
            ListNode* temp= new ListNode(val,m);
            temp->next=topi;
            topi=temp;
        }
        
    }
    
    void pop() {
        ListNode* temp=topi;
        topi=topi->next;
        delete temp;
        
    }
    
    int top() {
        return topi->val;
        
    }
    
    int getMin() {
        return topi->mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
