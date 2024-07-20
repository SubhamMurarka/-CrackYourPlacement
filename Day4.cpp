// Q10: Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // i = 0, j=0->col-1
        // i = 1->ro-1, j=col-1
        // i = ro-1, j=col-2->0
        // i = ro-2, j = 0->col-2
        //i -> ro     j -> col
        //in first left to right and up to down  -> +++
        //in right to left and down to up -> ---
        vector<int>ans;
        int ro = 0, col = -1;
        int n_ro = matrix.size(), n_col = matrix[0].size();
        int dir = 1;
        while(n_ro>0 && n_col>0) {
            // for horizontal traversal
            for(int j=0; j<n_col; j++) {
                col += dir;
                ans.push_back(matrix[ro][col]);
            }
            n_ro--; // 0 -> n_ro-2; n_ro -> 3  = n_ro -> 2
            // for vertical traversal
            for(int i=0; i<n_ro; i++) {
                ro += dir;
                ans.push_back(matrix[ro][col]);
            }
            n_col--;
            dir = dir * -1;
        }
        return ans;
    }
};


// Q11 : count no. of islands

class Solution {
public:
    void dfs(vector<vector<int>>&visited, vector<vector<char>>& grid, int ro, int col) {
        int n_ro = grid.size();
        int n_col = grid[0].size();
        if(ro >= n_ro || ro < 0) return;
        if(col >= n_col || col < 0) return;
        visited[ro][col] = 1;
        // ro-1, col... ro+1, col... ro, col-1.... ro,col+1
        // ro+1, ro+0, ro-1   col+1, col+0, col-1
        if(ro+1 < n_ro && visited[ro+1][col] == 0 && grid[ro+1][col]=='1') dfs(visited, grid, ro+1, col);
        if(ro-1 >= 0 && ro-1 < n_ro && visited[ro-1][col] == 0 && grid[ro-1][col]=='1') dfs(visited, grid, ro-1, col);
        if(col-1 >=0 && col-1 < n_col && visited[ro][col-1] == 0 && grid[ro][col-1]=='1') dfs(visited, grid, ro, col-1);
        if(col+1 >= 0 && col+1 < n_col && visited[ro][col+1] == 0 && grid[ro][col+1]=='1') dfs(visited, grid, ro, col+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n_ro = grid.size();
        int n_col = grid[0].size();
        int cnt = 0;
        vector<vector<int>>visited(n_ro, vector<int>(n_col, 0));
        for(int i=0; i<n_ro; i++) {
            for(int j=0; j<n_col; j++) {
                if(visited[i][j]!=1 && grid[i][j]!='0') {
                    dfs(visited, grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

Q12 : 