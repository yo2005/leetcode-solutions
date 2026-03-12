class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>right(n,0),left(n,0);
        //right nearest small
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()? n :st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //left nearest small
        for(int i=0;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()?-1 :st.top();
            st.push(i);
        }
        //computer max area
        int res=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int areaz=heights[i]*width;
            res=max(res,areaz);

        }
        return res;
     
        
    }
};
