import java.util.*;

public class MergeSort {
        public static void main(String[] args) {
                int[] ans = mergeSort(new int[] { 45, 5, 6, 7, 6, 4, 7 });
                System.out.println("Result : " + Arrays.toString(ans));
        }

        public static int[] mergeSort(int arr[]) {
                if (arr.length == 1) {
                        return arr;
                }

                int mid = arr.length / 2;
                int[] left = mergeSort(Arrays.copyOfRange(arr, 0, mid));
                int[] right = mergeSort(Arrays.copyOfRange(arr, mid, arr.length));

                return merge(left, right);
        }

        public static int[] merge(int[] left, int[] right) {
                int[] result = new int[left.length + right.length];

                int fp = 0;
                int sp = 0;
                int tp = 0;
                while (fp < left.length && sp < right.length) {
                        if (left[fp] > right[sp]) {
                                result[tp] = right[sp];
                                sp++;
                        } else if (left[fp] < right[sp]) {
                                result[tp] = left[fp];
                                fp++;
                        }
                        tp++;
                }

                while (fp < left.length) {
                        result[tp++] = left[fp];
                        fp++;
                        tp++;
                }
                while (sp < right.length) {
                        result[tp++] = right[sp];
                        sp++;
                        tp++;
                }
                return result;

        }

        // Inplace
        public static void mergeSortInplace(int arr[], int start, int end) {
                if (end - start == 1) {
                        return;
                }

                int mid = start + (end - start) / 2;
                mergeSortInplace(arr, start, mid);
                mergeSortInplace(arr, mid, end);

                mergeInplace(arr, start, mid, end);
        }

        public static int[] mergeInplace(int[] arr, int start, int m, int end) {
                int[] result = new int[end - start];

                int fp = start;
                int sp = m;
                int tp = 0;
                while (fp < m && sp < end) {
                        if (arr[fp] > arr[sp]) {
                                result[tp] = arr[sp];
                                sp++;
                        } else if (arr[fp] < arr[sp]) {
                                result[tp] = arr[fp];
                                fp++;
                        }
                        tp++;
                }

                while (fp < m) {
                        result[tp++] = arr[fp];
                        fp++;
                        tp++;
                }
                while (sp < end) {
                        result[tp++] = arr[sp];
                        sp++;
                        tp++;
                }

                for (int k = 0; k < result.length; k++) {
                        arr[k + start] = result[k];
                }

        }
}
