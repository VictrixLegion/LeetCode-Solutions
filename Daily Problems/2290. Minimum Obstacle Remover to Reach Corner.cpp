int minimumObstacles(vector<vector<int>>& grid) {
    int rows = grid.size();          // Number of rows in the grid
    int cols = grid[0].size();       // Number of columns in the grid

    // Distance array to track minimum obstacles removed to reach each cell
    vector<vector<int>> minObstacles(rows, vector<int>(cols, INT_MAX));

    // Deque for 0-1 BFS
    deque<pair<int, int>> bfsDeque;

    // Directions for movement: right, left, down, up
    vector<int> rowDir = {0, 0, 1, -1};
    vector<int> colDir = {1, -1, 0, 0};

    // Start from the top-left corner (0, 0)
    bfsDeque.push_front({0, 0});
    minObstacles[0][0] = 0;  // No obstacles removed to start

    // Perform BFS
    while (!bfsDeque.empty()) {
        auto [currentRow, currentCol] = bfsDeque.front();
        bfsDeque.pop_front();

        // Explore all 4 possible directions
        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + rowDir[i];
            int newCol = currentCol + colDir[i];

            // Check if the new cell is within bounds
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                // Calculate the cost (number of obstacles removed to reach this cell)
                int newObstacleCount = minObstacles[currentRow][currentCol] + grid[newRow][newCol];

                // If this path is better (requires fewer obstacle removals), update
                if (newObstacleCount < minObstacles[newRow][newCol]) {
                    minObstacles[newRow][newCol] = newObstacleCount;

                    // Push the new cell to the deque:
                    // - Front if it's an empty cell (grid[newRow][newCol] == 0)
                    // - Back if it contains an obstacle (grid[newRow][newCol] == 1)
                    if (grid[newRow][newCol] == 0) {
                        bfsDeque.push_front({newRow, newCol});
                    } else {
                        bfsDeque.push_back({newRow, newCol});
                    }
                }
            }
        }
    }

    // Return the minimum obstacles removed to reach the bottom-right corner
    return minObstacles[rows - 1][cols - 1];
    }
