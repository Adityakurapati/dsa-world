class Palindrome {

        static void palindromeNum(int n) {
                int num = n, rev = 0, reminder;
                int originalNumber = num;
                while (num != 0) {
                        reminder = num % 10;
                        rev = rev * 10 + reminder;
                        num = num / 10;
                }
                if (originalNumber == rev) {
                        System.out.println("Number Is Palindrome ");
                }
                System.out.println("Number Is Not Palindrome ");

        }

        static Boolean palindromeStr(String text) {

                // aabbaa
                String rev = "";
                boolean ans = false;
                for (int i = text.length() - 1; i >= 0; i--) {
                        rev = rev + text.charAt(i);
                }
                if (text.equals(rev)) {
                        ans = true;
                }
                return ans;
        }

        public static void main(String aeg[]) {
                // if (palindromeNum(2332)) {
                if (palindromeStr("abba")) {
                        System.out.println("Given String/Number IS Prime");
                } else {
                        System.out.println("String/Number Is Not Palindrome");
                }
        }
}