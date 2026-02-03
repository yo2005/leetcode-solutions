class Solution {
public:
int findmax(vector<int>&v){
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++){
        maxi=max(v[i],maxi);
    }
    return maxi;
}
long long calculatehours(vector<int>&v,int hour){
    long long total=0;
    for(int i=0;i<v.size();i++){
        total+=ceil((double)v[i]/(double)hour);
    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long res=calculatehours(piles,mid);
            if(res<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

            
        }
        return low;
        
    }
};
