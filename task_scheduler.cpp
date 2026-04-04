class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto z:tasks){
            freq[z-'A']++;
        }
        int maxfreq=0;
        for(auto j:freq){
            maxfreq=max(j,maxfreq);
        }
        int countmaxfreq=0;
        for(auto s:freq){
            if(s==maxfreq){
                countmaxfreq++;
            }
        }
        int k=(maxfreq-1)*(n+1)+countmaxfreq;
        return max((int)tasks.size(),k);
        
    }
};
