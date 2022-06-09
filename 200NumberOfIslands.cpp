class Solution {
public:
    void mark(vector<vector<char>>& grid,int i, int j, int rows, int cols){
        // base case
        if(i<0 or i>=rows or j<0 or j>=cols or grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        
        // recursive call
        mark(grid,i+1,j,rows,cols);
        mark(grid,i-1,j,rows,cols);
        mark(grid,i,j+1,rows,cols);
        mark(grid,i,j-1,rows,cols);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0) return 0;
        
        int cols = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // if grid is 1 then mark it and its neighbors visited
                if(grid[i][j]=='1'){
                    mark(grid,i,j,rows,cols);
                    ans++;
                }
            }
        }
        return ans;
    }
};