package Google_Amazon;

public class DiceForming {
        public static void main(String[] args) {
                dicePossibilityFor("", 4);
        }

        public static void dicePossibilityFor(String p, int num) {
                if (num == 0) {
                        System.out.println(p);
                        return;
                }

                for (int i = 1; i <= 6 && i <= num; i++) {
                        dicePossibilityFor(p + i, num - i);
                }
        }
}
