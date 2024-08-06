package Google_Amazon;

import java.util.ArrayList;

public class PrintCharsForDigits {
        public static void main(String[] args) {

        }

        public static void dial(String p, String up) {
                if (up.isEmpty()) {
                        System.out.println(p);
                        return;
                }

                int digit = up.charAt(0) - '0';
                int start = (digit - 1 * 3);
                int end = (digit * 3);
                for (int i = start; i < end; i++) {
                        char ch = (char) ('a' + i);

                        dial(p + ch, up.substring(1));
                }

        }

        public static ArrayList<String> dial2(String p, String up) {
                if (up.isEmpty()) {
                        ArrayList<String> list = new ArrayList<>();
                        list.add(p);
                        return list;
                }

                ArrayList<String> result = new ArrayList<>();
                int digit = up.charAt(0) - '0';
                int start = (digit - 1 * 3);
                int end = (digit * 3);
                for (int i = start; i < end; i++) {
                        char ch = (char) ('a' + i);

                        result.addAll(dial2(p + ch, up.substring(1)));
                }
                // result.addAll(dial2(p + (char)('a'+start), up.substring(1)));
                // result.addAll(dial2(p + (char)('a'+start+1), up.substring(1)));
                // result.addAll(dial2(p + (char)('a'+start+2), up.substring(1)));



                return result;

        }
}
