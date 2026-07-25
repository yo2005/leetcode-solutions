class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int rq=nums[i-1]+1;
                op+=rq-nums[i];
                nums[i]=rq;
            }
        }
        return op;

        
    }
};
