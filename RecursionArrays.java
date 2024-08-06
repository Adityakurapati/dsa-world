import java.util.*;

public class RecursionArrays {

        static int values[];

        public static void main(String[] args) {
                int[] arr = { 2, 4, 5, 6, 7, 6, 6, 90 };

                System.out.println("Result: " + chkIsSorted(arr));
                System.out.println("Result: " + search(arr, 6, 0));
                System.out.println("Result: " + searchFromLast(arr, 6, arr.length - 1));
                findAllIndex(arr, 6, arr.length - 1);
                // System.out.println("Result: " + values.toString());
                System.out.println("Result: " + findAllIndexes(arr, 6, arr.length - 1, new ArrayList<Integer>()));
        }

        public static boolean helper(int[] arr, int index) {
                if (index >= arr.length - 1) {
                        return true;
                }
                return (arr[index] <= arr[index + 1]) && helper(arr, index + 1);
        }

        public static boolean chkIsSorted(int[] arr) {
                if (arr == null || arr.length == 0) {
                        return true;
                }
                return helper(arr, 0);
        }

        public static int search(int[] arr, int target, int index) {

                if (index >= arr.length) {
                        return -1;
                }
                if (arr[index] == target) {
                        return index;
                }
                return search(arr, target, index + 1);
        }

        public static int searchFromLast(int[] arr, int target, int index) {

                if (index < 0) {
                        return -1;
                }
                if (arr[index] == target) {
                        return index;
                }
                return searchFromLast(arr, target, index - 1);
        }

        public static void findAllIndex(int[] arr, int target, int index) {
                if (index >= arr.length) {
                        return;
                }
                if (arr[index] == target) {
                        arr[arr.length] = index;
                }
                findAllIndex(arr, target, index + 1);
        }

        public static ArrayList<Integer> findAllIndexes(int[] arr, int target, int index, ArrayList<Integer> list) {
                if (index >= arr.length) {
                        return list;
                }
                if (arr[index] == target) {
                        list.add(index);
                }
                return findAllIndexes(arr, target, index + 1, list);
        }

        public static ArrayList<Integer> findAllIndexes2(int[] arr, int target, int index) {
                ArrayList<Integer> list = new ArrayList<Integer>();
                if (index >= arr.length) {
                        return list;
                }
                if (arr[index] == target) {
                        list.add(index);
                }
                ArrayList<Integer> ansFromBelow = findAllIndexes2(arr, target, index + 1);
                list.addAll(ansFromBelow);
                return list;
        }

        public static int binarySearchPartial(int arr[], int target, int start, int end) {
                if (start > end) {
                        return -1;
                }
                int mid = start + (end - start) / 2;
                if (arr[mid] == target) {
                        return mid;
                }

                if (arr[start] < arr[mid]) {
                        if (target >= arr[start] && target <= arr[mid]) {
                                return binarySearchPartial(arr, target, start, mid - 1);
                        } else {
                                return binarySearchPartial(arr, target, mid + 1, end);

                                return binarySearchPartial(arr, target, start, mid - 1);
                        }
                }

                if (target >= arr[mid] && target <= arr[end]) {
                        return binarySearchPartial(arr, target, mid + 1, end);
                }
                return binarySearchPartial(arr, target, start, end - 1);

        }
}