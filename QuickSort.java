import java.util.Arrays;

public class QuickSort {
        public static class Node {
                int value;
                Node left;
                Node right;

                Node(int value) {
                        this.value = value;
                        left = null;
                        right = null;
                }
        }

        static Node insert(int value, Node root) {
                if (root == null) {
                        return new Node(value);
                } else if (root.value > value) {
                        root.left = insert(value, root.left);
                } else if (root.value < value) {
                        root.right = insert(value, root.right);
                }
                return root;
        }

        static void quickSort(int[] arr) {
                quickSortHelper(arr, 0, arr.length - 1);
        }

        static void quickSortHelper(int[] arr, int low, int high) {
                if (low < high) {
                        int pivotIndex = partition(arr, low, high);
                        quickSortHelper(arr, low, pivotIndex - 1);
                        quickSortHelper(arr, pivotIndex + 1, high);
                }
        }

        static int partition(int[] arr, int low, int high) {
                int pivot = arr[low];
                int left = low + 1;
                int right = high;

                while (true) {
                        while (left <= right && arr[left] <= pivot) {
                                left++;
                        }
                        while (left <= right && arr[right] > pivot) {
                                right--;
                        }
                        if (left > right) {
                                break;
                        }
                        int temp = arr[left];
                        arr[left] = arr[right];
                        arr[right] = temp;
                }

                int temp = arr[low];
                arr[low] = arr[right];
                arr[right] = temp;

                return right;
        }

        // Inorder traversal method
        static void inorderTraversal(Node root) {
                if (root != null) {
                        inorderTraversal(root.left);
                        System.out.print(root.value + " ");
                        inorderTraversal(root.right);
                }
        }

        public static void main(String[] args) {
                int[] unsorted = { 23, 4, 6, 77, 5, 87, 34, 65 };
                quickSort(unsorted);
                System.out.println("Sorted array: " + Arrays.toString(unsorted));

                Node root = insert(unsorted[0], null);
                for (int i = 1; i < unsorted.length; i++) {
                        root = insert(unsorted[i], root);
                }

                System.out.println("Inorder traversal of the BST:");
                inorderTraversal(root);
        }
}