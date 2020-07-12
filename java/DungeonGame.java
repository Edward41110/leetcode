package LeetCode;

class DungeonGame {

    public int calculateMinimumHp(int[][] dungeon) {
        int row = dungeon.length, col = dungeon[0].length;
        int[][]dp = new int[row][col];
        dp[row - 1][col - 1] = Math.max(1 - dungeon[row - 1][col - 1], 1);
        for (int i = row - 2; i >= 0; i--) {
            dp[i][col - 1] = Math.max(dp[i + 1][col - 1] - dungeon[i][col - 1], 1);
        }
        for (int i = col - 2; i >= 0; i--) {
            dp[row - 1][i] = Math.max(dp[row - 1][i + 1] - dungeon[row - 1][i], 1);
        }
        for (int i = row - 2;i >= 0;i--) {
            for (int j = col - 2;j >= 0;j--) {
                dp[i][j] = Math.max(Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }

    public static void main(String[] args) {
        int[][]dungeon = new int[3][3];
        dungeon[0] = new int[]{-2, -3, 3};
        dungeon[1] = new int[]{-5, -10, 1};
        dungeon[2] = new int[]{10, 30, -5};
        DungeonGame s = new DungeonGame();
        System.out.println(s.calculateMinimumHp(dungeon));
    }
}