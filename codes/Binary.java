class Binary {
        static int search(int arr[], int target) {
                int min = 0, max = arr.length - 1;
                int sorted = 0; // 0: unsorted, 1: ascending, 2: descending

                if (arr[0] > arr[1]) {
                        sorted = 2;
                        for (int i = 1; i < arr.length - 1; i++) {
                                if (arr[i] < arr[i + 1]) {
                                        sorted = 0;
                                        break;
                                }
                        }
                } else if (arr[0] < arr[1]) {
                        sorted = 1;
                        for (int i = 1; i < arr.length - 1; i++) {
                                if (arr[i] > arr[i + 1]) {
                                        sorted = 0;
                                        break;
                                }
                        }
                }

                if (sorted == 1) { // Ascending order
                        while (min <= max) {
                                int mid = min + (max - min) / 2;
                                if (target == arr[mid]) {
                                        return mid;
                                } else if (target < arr[mid]) {
                                        max = mid - 1;
                                } else {
                                        min = mid + 1;
                                }
                        }
                } else if (sorted == 2) { // Descending order
                        while (min <= max) {
                                int mid = min + (max - min) / 2;
                                if (target == arr[mid]) {
                                        return mid;
                                } else if (target < arr[mid]) {
                                        min = mid + 1;
                                } else {
                                        max = mid - 1;
                                }
                        }
                }
                return -1;
        }

        public static void main(String arg[]) {
                int arr1[] = { 10, 20, 40, 50, 90, 120, 570, 600, 783 }; // Ascending order
                int arr2[] = { 94, 90, 87, 76, 64, 43, 2, 1 }; // Descending order
                System.out.println(search(arr1, 90)); // Should return the index of 90 in arr1
                System.out.println(search(arr2, 90)); // Should return the index of 90 in arr2
        }
}
