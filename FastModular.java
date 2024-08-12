public class FastModular {
        public static void main(String[] args) {
                int a = 3, b = 302, c = 5;
                String binaryString = Integer.toBinaryString(b); // Convert to binary string

                int len = binaryString.length();
                int sum = 1; // Initialize result as 1
                int base = a % c; // Ensure base is within modulus

                // Iterate over binaryString to calculate (a^b) % c
                for (int i = len - 1; i >= 0; i--) {
                        if (binaryString.charAt(i) == '1') {
                                sum = (sum * base) % c;
                        }
                        // Square the base and take modulo c for the next bit
                        base = (base * base) % c;
                }

                System.out.println("Binary representation of " + b + " is: " + binaryString);
                System.out.println("Result of " + a + "^" + b + " mod " + c + " is: " + sum);
        }
}
