class Solution {
public:
int n,m;
void dfs(int r, int c, vector<vector<int>>&heights, vector<vector<int>>&vis){
    vis[r][c]=1;
    int drow[]={-1,1,0,0};
    int dcol[]={0,0,-1,1};
    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
        && heights[nrow][ncol]>=heights[r][c]){
            dfs(nrow,ncol,heights,vis);
        }
        
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        //pac
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pac);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,heights,pac);
        }
        //atlantic
        for(int i=0;i<n;i++){
            dfs(i,m-1,heights,atlantic);
        }
        for(int j=0;j<m;j++){
            dfs(n-1,j,heights,atlantic);
        }
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }

        }
        return res;

        
    }
};
