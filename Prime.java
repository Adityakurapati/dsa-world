
class Prime {
        static void printPrimes(int n) {
                int i;
                int num;
                String primeNumbers = "";

                for (i = 1; i <= n; i++) {
                        int counter = 0;
                        for (num = i; num >= 1; num--) {
                                if (i % num == 0) {
                                        counter++;
                                }
                        }
                        if (counter == 2) {
                                primeNumbers += i + " ";
                        }
                }
                System.out.println("Prime Numbers: " + primeNumbers);
        }

        static boolean checkPrime(int num) {
                if (num <= 1) {
                        return false;
                }
                for (int i = 2; i <= Math.sqrt(num); i++) {
                        if (num % i == 0) {
                                return false;
                        }
                }
                return true;
        }

        public static void main(String[] args) {
                printPrimes(10);
                if (checkPrime(5)) {
                        System.out.println("Given Number Is Prime");
                } else {
                        System.out.println("Given Number Is Not Prime");
                }
        }
}
