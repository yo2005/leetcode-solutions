class Solution {
    int bfs(int row,int col, vector<vector<int>>&vis,vector<vector<int>>&grid){
    vis[row][col]=1;
    int w=1;
    int m=grid[0].size();
    int n=grid.size();
    queue<pair<int,int>>q;
    q.push({row,col});
    int delrow[]={-1,1,0,0};
    int delcol[]={0,0,-1,1};

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    w++;
                    q.push({nrow,ncol});
                }
        }
        
    }
    return w;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col]&& grid[row][col]==1){
                    
                   
                    res=max(res, bfs(row,col,vis,grid));
                }
            }
        }
        return res;

        
    }
        
    };
