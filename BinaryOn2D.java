import java.util.Arrays;

public class BinaryOn2D {
        static int[] search2D(int matrix[][], int target) {
                int row = 0;
                int col = matrix.length - 1;
                while (row < matrix.length && col >= 0) {
                        if (matrix[row][col] == target) {
                                return new int[] { row, col };
                        } else if (target < matrix[row][col]) {
                                col--;
                        } else if (target > matrix[row][col]) {
                                row++;
                        }
                }
                return new int[] { -1, -1 };
        }

        static int[] binarySearch(int row, int cstart, int cend, int target, int matrix[][]) {
                while (cstart < cend) {
                        int mid = cstart + (cend - cstart) / 2;
                        if (target == matrix[row][mid]) {
                                return new int[] { row, mid };
                        } else if (target > matrix[row][mid]) {
                                cstart = mid + 1;
                        } else {
                                cend = mid - 1;
                        }
                }
        }

        static int[] searchRowWise(int matrix[][], int target) {
                int rows = matrix.length - 1;
                int cols = matrix[0].length - 1;
                if (rows == 1) {
                        binarySearch(rows, 0, cols - 1, target, matrix);
                }

                // When we have
                int rStart = 0;
                int rEnd = rows - 1;
                int cmid = cols / 2;
                while (rStart < (rEnd - 1)) {
                        int mid = rStart + (rEnd - rStart) / 2;

                        if (matrix[rows][mid] == target) {
                                return new int[] { rows, mid };
                        } else if (target < matrix[rows][mid]) {
                                rEnd = mid;
                        } else {
                                rStart = mid;
                        }
                }

                // Last 2rows Are There
                if (matrix[rStart][cmid] == target) {
                        return new int[] { rStart, cmid };
                }
                if (matrix[rEnd][cmid] == target) {
                        return new int[] { rEnd, cmid };
                }

                if (target <= matrix[rStart][cmid - 1]) {
                        binarySearch(rStart, 0, cmid - 1, target, matrix);
                }
                if (target <= matrix[rEnd][cmid - 1]) {
                        binarySearch(rEnd, 0, cmid - 1, target, matrix);
                }
                if (target >= matrix[rStart][cmid + 1]) {
                        binarySearch(rStart, cmid + 1, cols, target, matrix);
                }
                if (target >= matrix[rEnd][cmid + 1]) {
                        binarySearch(rEnd, cmid + 1, cols, target, matrix);
                }
        }

        public static void main(String a[]) {
                int matrix[][] = {
                                { 10, 20, 30, 40 },
                                {
                                                15, 25, 35, 45
                                }, { 28, 2937, 49 },
                                {
                                                33, 34, 38, 50
                                }
                };
                System.out.println("Found Index : " + Arrays.toString(search2D(matrix, 2448)));

                int RowMatrix[][] = { {} };

        }
}
