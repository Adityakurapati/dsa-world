public class Recursion {

        static int sum = 0;
        static int rem;
        static int ans = 0;

        public static void main(String[] args) {
                recurse(5);
                revRecurse(5);
                System.out.println("" + fact(2));
                System.out.println("" + sum(1342));
                // System.out.println("" + reverse(1342));
                reverse(1342);
                System.out.println("reverse : " + sum);
                System.out.println("reverse2 : " + reverse2(2345));
        }

        public static void recurse(int n) {
                if (n == 0) {
                        return;
                }
                System.out.print(" " + n);
                recurse(n - 1);
        }

        public static void revRecurse(int n) {

                if (n == 0)
                        return;
                revRecurse(n - 1);
                System.out.println(" " + n);

        }

        public static void recurseBoth(int n) {
                if (n == 0) {
                        return;
                }
                System.out.println(" " + n);
                recurseBoth(n - 1);
                System.out.println(" " + n);

        }

        public static int fact(int n) {
                if (n == 1) {
                        return 1;
                }
                return n * fact(n - 1);
                // fact(n);

        }

        public static int sum(int n) {
                if (n == 0)
                        return 0;
                return (n % 10) + sum(n / 10);
        }

        public static int prod(int n) {
                if (n % 10 == n)
                        return n;
                return (n % 10) + prod(n / 10);
        }

        // public static concept(int n){
        // if(n==0){
        // return;
        // }
        // System.out.println(""+n);
        // //n never changes (infinite)
        // // concept(n--);
        // // WOrks Good
        // concept(--n);
        // }

        public static void reverse(int n) {
                if (n == 0) {
                        return;
                }
                rem = n % 10;
                sum = sum * 10 + rem;
                reverse(n / 10);
        }

        public static int helper(int n, int power) {
                if (n % 10 == n) {
                        return n;
                }
                int rem = n % 10;
                return rem * (int) (Math.pow(10, power - 1)) + helper(n / 10, power - 1);
        }

        public static int reverse2(int num) {
                // if (num == 0) {
                // return;
                // }
                int digits = (int) (Math.log10(num)) + 1;
                return helper(num, digits);
        }

        public static int helper2(int n, int count) {
                // return count at leaf condition where n/10 ==0
                if (n == 0) {
                        return ans;
                }
                if ((n % 10) == 0) {
                        return helper2(n, count + 1);
                }
                return helper2(n, count);
        }

        public static int chkZero(int n, int count) {
                return helper2(n, count);
        }
        // public static boolean palindrome(int n){

        // }
}
