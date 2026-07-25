class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            return n;
        }
        unordered_set<int>s;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=k){
                s.insert(nums[i]);
            }
            if(s.size()==k){
                return n-i;//formula fo number of iterations to complete till k
            }
        }
        return n;//this will never execute
      
        
    }
};
