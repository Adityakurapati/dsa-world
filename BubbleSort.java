import java.util.Arrays;

public class BubbleSort {

        static void sort(int arr[]) {
                // For Passes
                int swap_counter = 0;
                for (int i = 1; i < arr.length; i++) {
                        int j = 1;
                        int swaps = 0;
                        while (j < arr.length - i + 1) {
                                if (arr[j - 1] > arr[j]) {
                                        int temp = arr[j];
                                        arr[j] = arr[j - 1];
                                        arr[j - 1] = temp;
                                        swaps++;
                                        swap_counter++;
                                }
                                j++;
                        }
                        if (swaps == 0) {
                                break;
                        }
                }
                System.out.println("Total Swaps: " + swap_counter);
        }

        // Selection Sort
        static int findMaxIndex(int arr[], int start, int end) {
                int maxIndex = start;
                for (int i = start + 1; i <= end; i++) {
                        if (arr[i] > arr[maxIndex]) {
                                maxIndex = i;
                        }
                }
                return maxIndex;
        }

        static void selectionSort(int elements[]) {
                int len = elements.length;
                // passes
                for (int i = 0; i < len - 1; i++) {
                        int maxIndex = findMaxIndex(elements, 0, len - i - 1);
                        if (maxIndex != len - i - 1) {
                                int temp = elements[len - i - 1];
                                elements[len - i - 1] = elements[maxIndex];
                                elements[maxIndex] = temp;
                        }
                }
        }

        static void insertoinSort(int[] arr) {
                for (int i = 0; i < arr.length - 1; i++) {
                        int j = i + 1;
                        while (j > 0 && arr[j] < arr[j - 1]) {
                                int temp = arr[j - 1];
                                arr[j - 1] = arr[j];
                                arr[j] = temp;
                                j -= 1;
                        }
                        System.out.println(Arrays.toString(arr));

                }
        }

        // Cyclic Sort
        static void cyclic(int[] arr) {

                int elementPointer = 0;
                int allSorted = 0;
                while (!(allSorted == arr.length - 1)) {
                        int originalPosition = arr[elementPointer] - 1;
                        if (originalPosition == elementPointer) {
                                elementPointer++;
                                allSorted++;
                        } else {
                                int temp = arr[elementPointer];
                                arr[elementPointer] = arr[originalPosition];
                                arr[originalPosition] = temp;
                                allSorted++;
                        }
                }
        }

        public static void cyclicSort(int[] arr) {
                int i = 0;
                while (i < arr.length) {
                        int correctIndex = arr[i] - 1;
                        if (correctIndex >= 0 && correctIndex < arr.length && arr[i] != arr[correctIndex]) {
                                int temp = arr[i];
                                arr[i] = arr[correctIndex];
                                arr[correctIndex] = temp;
                        } else {
                                i++;
                        }
                }
        }

        public static void main(String[] args) {
                int arr[] = { 2, 4, 5, 3, 8, 66, 6, 7 };

                sort(arr);
                System.out.println("\n\nSorted by Bubble Sort:\n");
                System.out.println(Arrays.toString(arr));

                int arr2[] = { 2, 4, 5, 3, 8, 66, 6, 7 };
                selectionSort(arr2);
                System.out.println("\n\nSorted by Selection Sort:\n");
                System.out.println(Arrays.toString(arr2));

                int arr3[] = { 2, 4, 5, 3, 8, 66, 6, 7 };
                insertoinSort(arr3);
                System.out.println("\n\nSorted by Insertion Sort:\n");
                System.out.println(Arrays.toString(arr3));

                int arr4[] = { 2, 4, 1, 3, 5, 7, 9 };
                cyclicSort(arr4);
                System.out.println("\n\nSorted by Cyclic Sort:\n");
                System.out.println(Arrays.toString(arr4));
        }
}
