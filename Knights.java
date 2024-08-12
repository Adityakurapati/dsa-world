public class Knights {
        public static void main(String[] args) {
                int n = 4; // Board size
                int knights = 4; // Number of knights to place
                boolean[][] board = new boolean[n][n];
                knight(board, 0, 0, knights);
        }

        public static void knight(boolean board[][], int row, int col, int knights) {
                if (knights == 0) {
                        printBoard(board);
                        return;
                }

                if (row == board.length) {
                        return; // End of board reached
                }

                if (col == board.length) {
                        knight(board, row + 1, 0, knights);
                        return;
                }

                if (isSafe(board, row, col)) {
                        board[row][col] = true;
                        knight(board, row, col + 1, knights - 1);
                        board[row][col] = false;
                }
                knight(board, row, col + 1, knights);
        }

        public static boolean isSafe(boolean board[][], int row, int col) {
                // Check all possible knight moves
                int[][] directions = {
                                { -2, -1 }, { -2, 1 }, { -1, -2 }, { -1, 2 },
                                { 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 }
                };

                for (int[] dir : directions) {
                        int newRow = row + dir[0];
                        int newCol = col + dir[1];
                        if (isValid(board, newRow, newCol) && board[newRow][newCol]) {
                                return false;
                        }
                }

                return true;
        }

        private static boolean isValid(boolean board[][], int row, int col) {
                return row >= 0 && row < board.length && col >= 0 && col < board.length;
        }

        private static void printBoard(boolean[][] board) {
                for (boolean[] row : board) {
                        for (boolean cell : row) {
                                System.out.print(cell ? "K " : ". ");
                        }
                        System.out.println();
                }
                System.out.println();
        }
}
