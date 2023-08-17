# 💭 Intuition
Let's think it this way, `mat` consists of water `[0]` and land `[1]` blocks. Each second the water floods neighbour _(top - left - down - right )_ land blocks. Calculate required time for every block to be flooded. 
- We will be using breadth first search to solve this problem in an efficient way.
- Instead of using a different array for the answer, we will be updating `mat` to avoid using extra space.
 
<hr/>

# 📝Approach
1. Take a queue of pairs `q`, commonly used in BFS algorithms to store the live nodes.
2. Push the position _(row and column)_ of each `0` in `q`.
3. Change all `1`'s to any integer that is greater than maximum possible distance, for the sake of simplicity we are taking `INF = 100000`. Later we can minimize it to exact value with ease.

### Now comes the BFS part :
4. Take out a live node from `q` and process it untill `q` is empty.
5. Check for all possible edge adjacent neighbours. 
6. Only push them in `q` if their distance can be minimized further.

<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(N^2)$

- 📦 Space complexity: $O(N^2)$
 
<hr/>

# ⌨️ Code
```cpp
class Solution {
public:
    const int INF = 1e5; // has to be greater than n + m
    // next two arrays are for traversing through edge adjacent neighbours
    const int x[4] = {-1, 0, 0, 1}; 
    const int y[4] = {0, -1, 1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q; // stores unprocessed cells
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]) mat[i][j] = INF; // change all 1s
                else q.push({i, j}); // add all 0s 
            }
        }
        while(q.size()) {
            auto ind = q.front(); q.pop();
            int r = ind.first, c = ind.second;
            int val = mat[r][c] + 1; // distance of neighbour cells
            for(int k=0; k<4; k++) {
                int nr = r + x[k];
                int nc = c + y[k];
                if(nr<0 || nr==n || nc<0 || nc==m || mat[nr][nc] <= val) 
                    continue; // bound check + minimizing condition
                mat[nr][nc] = val; // minimize distance
                q.push({nr, nc}); // add to q
            } 
        }   return mat;
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`01 Matrix`](https://leetcode.com/problems/01-matrix/)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $17/08/2023$
- :copyright: **Author :** _Siddharth Biswas_  
