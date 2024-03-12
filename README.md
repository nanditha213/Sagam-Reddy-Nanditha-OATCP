We create a 2D vector, dp, of size n×n initialized with zeros. This vector is used to store the number of paths to reach each cell.

If the starting cell is open ('.'), we set dp[0][0] to 1; otherwise, it remains 0.

For each cell in the first row or the first column, if the cell is open ('.'), we set the corresponding cell in dp to the value of the cell above (for cells in the first column) or the value of the cell to the left (for cells in the first row).

We then iterate through each cell starting from (1, 1) to (n-1, n-1). For each open cell, we update dp[i][j] by adding the number of paths from the cell above (dp[i−1][j]) and the number of paths from the cell to the left (dp[i][j−1]).

Finally, we return the value stored in dp[n−1][n−1], which represents the number of paths from the top-left corner to the bottom-right corner of the grid, while moving only right and down and traversing only through open cells ('.').
