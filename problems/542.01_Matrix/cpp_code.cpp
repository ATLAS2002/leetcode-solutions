class Solution {
public:
    const int INF = 1e5;
    const int x[4] = {-1, 0, 0, 1};
    const int y[4] = {0, -1, 1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]) mat[i][j] = INF;
                else q.push({i, j});
            }
        }
        while(q.size()) {
            auto ind = q.front(); q.pop();
            int r = ind.first, c = ind.second;
            int val = mat[r][c] + 1;
            for(int k=0; k<4; k++) {
                int nr = r + x[k];
                int nc = c + y[k];
                if(nr<0 || nr==n || nc<0 || nc==m || mat[nr][nc] <= val) continue;
                mat[nr][nc] = val;
                q.push({nr, nc});
            } 
        }   return mat;
    }
};