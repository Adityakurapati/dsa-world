public class RecursionArrays {

        static int values[];

        public static void main(String[] args) {
                int[] arr = { 2, 4, 5, 6, 7, 6, 6, 90 };

                System.out.println("Result: " + chkIsSorted(arr));
                System.out.println("Result: " + search(arr, 6, 0));
                System.out.println("Result: " + searchFromLast(arr, 6, arr.length - 1));
                findAllIndex(arr, 6, arr.length - 1);
                // System.out.println("Result: " + values.toString());
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
}