public class GCD_LCM {
        public static void main(String[] args) {
                System.out.println("\nGCD : - " + gcd(10, 2));
                System.out.println("LCM : - " + lcm(10, 2));
        }

        public static int gcd(int n1, int n2) {
                if (n1 == 0) {
                        return n2;
                }
                return gcd(n2 % n1, n1);
        }

        public static int lcm(int a, int b) {
                return a * b / gcd(a, b);
        }
}
