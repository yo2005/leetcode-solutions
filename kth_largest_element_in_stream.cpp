class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>>h;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
   
        for(auto x:nums){
            h.push(x);
            if(h.size()>k){
                h.pop();
            }
        }
        
    }
    
    int add(int val) {
        h.push(val);
        if(h.size()>k){
            h.pop();
        }
        return h.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
