import java.util.Scanner;

class PerfectSquare {
        // Method to check if a number is a perfect square
        static boolean isPerfectSquare(int num) {
                if (num < 0) {
                        return false; // Negative numbers cannot be perfect squares
                }

                int sqrt = (int) Math.sqrt(num); // Calculate the square root of the number
                return (sqrt * sqrt == num); // Check if the square of the sqrt is equal to the number
        }

        public static void main(String[] args) {
                if (isPerfectSquare(4)) {
                        System.out.println("The number is a perfect square.");
                } else {
                        System.out.println("The number is not a perfect square.");
                }

        }
}
