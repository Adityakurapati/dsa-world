public class PrimeOptimized {
        static int count = 0;

        public static void main(String[] args) {
                for (int i = 0; i < 40; i++) {
                        System.out.println(i + " => " + isPrime(i));
                }
                System.out.println("Count: " + count);

                sieve();

                System.out.printf("" + sqrt(40, 2));
                factorsOfNum(36);
        }

        static Boolean isPrime(int n) {
                if (n <= 1) {
                        return false;
                }
                int c = 2;
                while (c * c <= n) {
                        if (n % c == 0) {
                                return false;
                        }
                        c++;
                }
                count++;
                return true;
        }

        // Print Primes in 0 - Range
        // Prime numbers are made false
        static void sieve() {
                boolean arr[] = new boolean[41]; // Array size should be 41 to include 40
                for (int i = 2; i * i <= 40; i++) {
                        if (!arr[i]) {
                                for (int j = i * i; j <= 40; j += i) { // Start from i*i to optimize
                                        arr[j] = true;
                                }
                        }
                }
                for (int i = 2; i <= 40; i++) { // Start from 2, as 0 and 1 are not primes
                        if (!arr[i]) {
                                System.out.println(i);
                        }
                }
        }

        public static double sqrt(int n, int p) {
                int s = 0;
                int e = n;
                double root = 0.0;

                // Binary search for the integer part of the square root
                while (s <= e) {
                        int mid = s + (e - s) / 2;
                        if (mid * mid == n) {
                                return mid;
                        }

                        if (mid * mid > n) {
                                e = mid - 1;
                        } else {
                                s = mid + 1;
                                root = mid; // keep track of the closest integer root
                        }
                }

                // Linear search for the fractional part
                double increment = 0.1;
                for (int i = 0; i < p; i++) {
                        while (root * root <= n) {
                                root += increment;
                        }
                        root -= increment; // go back one step as the while loop overshoots
                        increment /= 10;
                }

                return root;
        }

        public static void factorsOfNum(int n) {
                for (int i = 1; i < Math.sqrt(n); i++) {

                        if (n % i == 0) {
                                if (n / i == i) {
                                        System.out.println("  6 " + i);
                                } else {
                                        System.out.println(" " + (n / i) + " " + i);
                                }
                        }
                }
        }
}
