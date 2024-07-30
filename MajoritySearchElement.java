/*
public class MajoritySearchElement {
        public static int findMajorityElement(int[] arr) {
                int n = arr.length;

                for (int i = 0; i < n; i++) {
                        int count = 0;
                        for (int j = 0; j < n; j++) {
                                if (arr[i] == arr[j]) {
                                        count++;
                                }
                        }
                        if (count > n / 2) {
                                return arr[i];
                        }
                }

                return -1;
        }

        public static void main(String[] args) {
                int[] arr = { 2, 2, 1, 1, 1, 2, 2 };
                int result = findMajorityElement(arr);
                if (result != -1) {
                        System.out.println("The majority element is: " + result);
                } else {
                        System.out.println("No majority element found.");
                }
        }
}
*/
public class MajoritySearchElement {
        public static int findMajorityElement(int[] arr) {
                int n = arr.length;

                // Using Moore's Voting Algorithm
                int candidate = arr[0];
                int count = 1;

                // Find a candidate for majority element
                for (int i = 1; i < n; i++) {
                        if (count == 0) {
                                candidate = arr[i];
                                count = 1;
                        } else if (arr[i] == candidate) {
                                count++;
                        } else {
                                count--;
                        }
                }

                // Verify if the candidate is actually the majority element
                count = 0;
                for (int i = 0; i < n; i++) {
                        if (arr[i] == candidate) {
                                count++;
                        }
                }

                if (count > n / 2) {
                        return candidate;
                } else {
                        return -1; // No majority element found
                }
        }

        public static findMajorityElementHeap(int arr){
                
        }

        // public static int findMajorityUsingHeap(int arr[]){

        // }

        public static void main(String[] args) {
                int[] arr = { 2, 2, 1, 1, 1, 2, 2 };
                int result = findMajorityElement(arr);
                if (result != -1) {
                        System.out.println("The majority element is: " + result);
                } else {
                        System.out.println("No majority element found.");
                }
        }
}