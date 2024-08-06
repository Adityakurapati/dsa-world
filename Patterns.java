import java.util.Arrays;

public class Patterns {
        public static void main(String[] args) {
                System.out.println("");
                printPattern(4, 0);

                int arr[] = { 23, 5, 6, 7 };
                // bubbleSort(arr, 3, 0);
                selectionSort(arr, 4, 0, 0);
                System.out.println("Result - " + Arrays.toString(arr));

        }

        static void printPatternROtated(int rows, int cols) {
                if (rows == 0) {
                        return;
                }
                if (cols < rows) {
                        System.out.print("*");
                        printPattern(rows, cols + 1);
                } else {
                        // Going To The Next Line

                        System.out.println("");
                        printPattern(rows - 1, 0);
                }
        }

        static void printPattern(int rows, int cols) {
                if (rows == 0) {
                        return;
                }
                if (cols < rows) {
                        printPattern(rows, cols + 1);
                        System.out.print("*");
                } else {
                        printPattern(rows - 1, 0);
                        System.out.println("");

                }
        }

        public static void bubbleSort(int arr[], int rows, int cols) {
                if (rows == 0) {
                        return;
                }
                if (cols < rows) {
                        if (arr[cols] > arr[cols + 1]) {
                                int temp = arr[cols];
                                arr[cols] = arr[cols + 1];
                                arr[cols + 1] = temp;
                        }
                        bubbleSort(arr, rows, cols + 1);
                } else {
                        bubbleSort(arr, rows - 1, 0);
                }
        }

        static int maxIndex = 0;

        public static void selectionSort(int arr[], int rows, int cols, int maxIndex) {
                if (rows == 0) {
                        return;
                }
                if (cols < rows) {
                        if (arr[cols] > arr[maxIndex]) {
                                selectionSort(arr, rows, cols, cols);
                        }
                        selectionSort(arr, rows, cols, maxIndex);
                } else {
                        if (maxIndex != rows) {
                                int temp = arr[cols];
                                arr[cols] = arr[rows - 1];
                                arr[rows - 1] = temp;
                        }
                        selectionSort(arr, rows - 1, 0, 0);
                }
        }
}