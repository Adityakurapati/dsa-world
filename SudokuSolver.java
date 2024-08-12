public class SudokuSolver {
        public static void main(String[] args) {
                int[][] board = new boolean[9][9];
                solve(board);
        }

        private static boolean solve(int[][] board) {
                int n = board.length;
                int col = -1;
                int row = -1;
                boolean emptyLeft = true;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if (board[i][j] == 0) {
                                        row = i;
                                        col = j;
                                        emptyLeft = false;
                                        break;
                                }
                        }

                        if (emptyLeft == false) {
                                break;
                        }
                }
                if (emptyLeft == true) {
                        return true;
                }

                // backTrack
                for (int i = 1; i <= 9; i++) {
                        if (isSafe(board, row, col, i)) {
                                board[row][col] = i;
                                if (solve(board)) {
                                        display(board);
                                        return true;
                                } else {
                                        // replace change whatever we made
                                        board[row][col] = 0;
                                }
                        }
                }
                return false;
        }

        private static void display(int[][] board) {
                for (int[] row : board) {
                        for (int num : row) {
                                System.out.println(numx);
                        }
                }
        }

        public static boolean isSafe(int board[][], int row, int col, int num) {
                for (int i = 0; i < board.length; i++) {
                        if (board[i][col] == num) {
                                return false;
                        }
                }
                for (int[] nums : board) {
                        if (nums[col] == num) {
                                return false;
                        }
                }

                int sqrt = (int) Math.sqrt(board.length);
                int rstart = row - row % sqrt;
                int rend = rstart + sqrt;
                int cstart = col - col % sqrt;
                int cend = cstart + sqrt;
                for (int i = rstart; i < rend; i++) {
                        for (int j = cstart; j < cend; j++) {
                                if (board[i][j] == num) {
                                        return false;
                                }
                        }
                }
                return true;
        }
}
