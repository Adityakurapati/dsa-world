public class Chess {
        public static void main(String[] args) {
                System.out.println();
                chkPossibility(new boolean[4][4], 0); // Start from row 0
        }

        public static void chkPossibility(boolean board[][], int r) {
                if (r == board.length) {
                        for (int i = 0; i < board.length; i++) {
                                for (int j = 0; j < board[0].length; j++) {
                                        if (board[i][j]) {
                                                System.out.print("Q ");
                                        } else {
                                                System.out.print("X ");
                                        }
                                }
                                System.out.println();
                        }
                        System.out.println();
                        return;
                }

                for (int c = 0; c < board.length; c++) {
                        if (isSafe(board, r, c)) {
                                board[r][c] = true;
                                chkPossibility(board, r + 1);
                                board[r][c] = false;
                        }
                }
        }

        public static boolean isSafe(boolean[][] board, int row, int col) {
                // Check the same column
                for (int i = 0; i < row; i++) {
                        if (board[i][col]) {
                                return false;
                        }
                }

                // Check upper-left diagonal
                for (int i = 1; i <= Math.min(row, col); i++) {
                        if (board[row - i][col - i]) {
                                return false;
                        }
                }

                // Check upper-right diagonal
                for (int i = 1; i <= Math.min(row, board.length - col - 1); i++) {
                        if (board[row - i][col + i]) {
                                return false;
                        }
                }

                return true;
        }
}
