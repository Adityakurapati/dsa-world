import java.util.ArrayList;

public class Permutations {
        public static void main(String[] args) {
                permutation("", "abc");

                ArrayList<String> result = permutationRet("", "abc");
                for (String ans : result) {
                        System.out.println(ans);
                }
        }

        public static void permutation(String p, String up) {
                if (up.isEmpty()) {
                        System.out.println(p);
                        return;
                }

                char ch = up.charAt(0);

                for (int i = 0; i <= p.length(); i++) {
                        String first = p.substring(0, i);
                        String sec = p.substring(i, p.length());
                        permutation(first + ch + sec, up.substring(1));
                }
        }

        public static ArrayList<String> permutationRet(String p, String up) {
                if (up.isEmpty()) {
                        ArrayList<String> list = new ArrayList<>();
                        list.add(p);
                        return list;
                }
                char ch = up.charAt(0);

                ArrayList<String> ans = new ArrayList<>();

                for (int i = 0; i < p.length(); i++) {
                        String first = p.substring(0, i);
                        String second = p.substring(i, p.length());
                        ans.addAll(permutationRet(first + ch + second, up.substring(1)));
                }
                return ans;
        }

        public static int permutationCount(String p, String up) {
                if (up.isEmpty()) {
                        return 1;
                }

                int count = 0;
                char ch = up.charAt(0);

                for (int i = 0; i <= p.length(); i++) {
                        String first = p.substring(0, i);
                        String sec = p.substring(i, p.length());
                        count = count + permutationCount(first + ch + sec, up.substring(1));
                }
                return count;
        }
}
