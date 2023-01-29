/*
 * @Author: QDX
 * @Date: 2023-01-28 16:56:53
 * @Description: 
 */
#include "utils.h"

class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
        row_n = grid.size();
        if (!row_n) return 0;
        col_n = grid[0].size();

        int cnt = 0;
        for (int r = 0; r < row_n; ++r) {
            for (int c = 0; c < col_n; ++c) {
                if (grid[r][c] == '1') {
                    ++cnt;
                    dfs(grid, r, c);
                }
            }
        }
        return cnt;
    }

  private:
    bool in_area(const int& r, const int& c) {
        if (0 <= r && r < row_n && 0 <= c && c < col_n) {
            return true;
        } else {
            return false;
        }
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (!in_area(r, c)) return;
        if (grid[r][c] != '1') return;
        grid[r][c] = '2';
        for (auto it = directions.begin(); it != directions.end(); it++) {
            int dr = get<0>(*it);
            int dc = get<1>(*it);
            dfs(grid, r + dr, c + dc);
        }
    }

  private:
    int row_n = 0, col_n = 0;
    const vector<tuple<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'1','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    auto ans = Solution().numIslands(grid);
    cout << ans << endl;
}

