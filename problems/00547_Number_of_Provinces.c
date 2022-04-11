// dfs search
// Runtime: 56 ms, faster than 16.81% of C online submissions for Number of Provinces.
// Memory Usage: 7.7 MB, less than 5.31% of C online submissions for Number of Provinces.
void mark_x(int** isConnected, int n, int row, int col)
{
    for (int i = col; i < n; i++) {
        if (isConnected[row][i] == 1) {
            isConnected[row][i] = 2;
            if (row != i) {
                // search isConnected[i][0~n-1]
                mark_x(isConnected, n, i, 0);
            }
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int row_cnt = isConnectedSize;
    int col_cnt = row_cnt;
    int result = 0;
    for (int row = 0; row < row_cnt; row++) {
        for (int col = 0; col < col_cnt; col++) {
            if (isConnected[row][col] == 1) {
                result++;
                mark_x(isConnected, row_cnt, row, col);
            }
        }
    }
    return result;
}

// dfs search with memory of visited row
// Runtime: 24 ms, faster than 97.35% of C online submissions for Number of Provinces.
// Memory Usage: 7.3 MB, less than 12.39% of C online submissions for Number of Provinces.
void mark_x(int** isConnected, int n, int row, int col, bool *visited)
{
    for (int i = col; i < n; i++) {
        if (isConnected[row][i] == 1) {
            visited[row] = true;
            isConnected[row][i] = 2;
            if ((row != i) && (visited[i] == false)) {
                // search isConnected[i][0~n-1]
                mark_x(isConnected, n, i, 0, visited);
            }
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int row_cnt = isConnectedSize;
    int col_cnt = row_cnt;
    int result = 0;
    bool *visited; // memory map for row visited
    visited = (bool *)malloc(sizeof(bool) * row_cnt);
    memset(visited, false, sizeof(bool) * row_cnt);
    for (int row = 0; row < row_cnt; row++) {
        for (int col = 0; col < col_cnt; col++) {
            if (isConnected[row][col] == 1) {
                result++;
                mark_x(isConnected, row_cnt, row, col, visited);
            }
        }
    }
    free(visited);
    return result;
}