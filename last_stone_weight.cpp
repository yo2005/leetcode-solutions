class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap;
        for(auto x:stones){
            maxheap.push(x);
        }

        while(maxheap.size()>1){
            int y=maxheap.top();
            maxheap.pop();
            int x=maxheap.top();
            maxheap.pop();
            if(x!=y){
                maxheap.push(y-x);
            }
        }
        return maxheap.empty()?0:maxheap.top();
        
    }
};
