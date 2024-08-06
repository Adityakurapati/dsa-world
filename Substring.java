import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Substring {
        public static void mian(String a[]) {
                String result = removeCharacters("baccad");
                System.out.println(result);
                skip("baccad");

                String[] myres = subset("", "abc", true);
                for (String s : myres) {
                        System.out.println(s);
                }
        }

        public static String helper(String s) {
                if (s.length == 1) {
                        if (s.equal("a")) {
                                return "";
                        }
                        return s;
                }
                if (s.chatAt(0) == 'a') {
                        return helper(s.substring(1));
                }
                return s.chatAt(0) + helper(s.substring(1));
        }

        public static String removeCharacters(String s) {
                if (up.isEmpty()) {
                        return "";
                }
                return helper(s);
        }

        public static void skip(String p, String up) {
                if (up.isEmpty()) {
                        system.out.println(p);
                        return;
                }
                char ch = up.charAt(0);
                if (ch == 'a') {
                        skip(p, up.substring(1));
                } else {
                        skip(p + ch, up.substring(1));
                }
        }

        public static String skipApple(String up) {
                if (up.isEmpty()) {
                        return "";
                }
                char ch = up.charAt(0);
                if (up.startsWith("apple")) {
                        return skipApple(up.substring(5));
                } else {
                        return ch + skipApple(up.substring(1));
                }
        }

        public static String skipApp(String up) {
                if (up.isEmpty()) {
                        return "";
                }
                char ch = up.charAt(0);
                if (up.startsWith("app") && up.charAt(3) != 'l') {
                        return skipApp(up.substring(3));
                } else {
                        return ch + skipApp(up.substring(1));
                }
        }

        public static String[] subset(String p, String up, boolean oper) {
                if (up.isEmpty()) {
                        return new String[] { p };
                }
                String[] result = new String[4];
                if (oper) {
                        rs = p + up.charAt(0);
                } else {
                        rs = p;
                }
                up = up.substring(1);

                String[] left = subset(rs, up, true);
                String[] right = subset(rs, up, false);

                System.arraycopy(left, 0, right, 0, left.length);
                System.arraycopy(right, 0, right, left.length, right.length);
                return result;
        }

        public static void subsetWithoutReturn(String p, String up) {
                if (up.isEmpty()) {
                        return;

                }
                char ch = up.chatAt(0);
                subsetWithoutReturn(p + ch, up.substring(1));
                subsetWithoutReturn(p, up.substring(1));
        }

        public static void subsetWithoutReturn(String p, String up) {
                if (up.isEmpty()) {
                        return;

                }
                char ch = up.chatAt(0);
                subsetWithoutReturn(p + ch, up.substring(1));
                subsetWithoutReturn(p, up.substring(1));
                subsetWithoutReturn(p + (int) ch, up.substring(1));
        }

        public static ArrayList<String> subsetAsciiRet(String p, String up) {
                if (up.isEmpty()) {
                        ArrayList<String> list = new ArrayList<>();
                        list.add(p);
                        return list;
                }

                char ch = up.chatAt(0);
                ArrayList<String> first = subsetAsciiRet(p + ch, up);
                ArrayList<String> sec = subsetAsciiRet(p, up);
                ArrayList<String> third = subsetAsciiRet(p + (int) ch, up);

                first.addAll(sec);
                first.addAll(third);
                return first;
        }

        public static List<List> subArray(int arr[]) {
                List<List> outer = new ArrayList<>();

                outer.add(new ArrayList());

                for (int num : arr) {
                        int size = outer.size();

                        for (int i = 0; i < size; i++) {
                                List<Integer> internal = new ArrayList<>(outer.get(i));
                                internal.add(num);
                                outer.add(internal);
                        }
                }

                return outer;
        }

        public static List<List> subArrayDuplicate(int arr[]) {

                Arrays.sort(arr);
                List<List> outer = new ArrayList<>();

                outer.add(new ArrayList());

                int start = 0, end = 0;
                for (int i = 0; i < arr.length; i++) {

                        int start = 0;
                        if (i > 0 && arr[i] == arr[i - 1]) {
                                start = end + 1;
                        }
                        end = outer.length() - 1;
                        int size = outer.size();

                        for (int j = start; j < size; j++) {
                                List<Integer> internal = new ArrayList<>(outer.get(j));
                                internal.add(arr[i]);
                                outer.add(internal);
                        }
                }

                return outer;
        }

}