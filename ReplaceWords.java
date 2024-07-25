import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;

class ReplaceWords {
        static String replace(String word, List<String> dictionary) {
                for (String root : dictionary) {
                        if (word.startsWith(root)) {
                                return root;
                        }
                }
                return word;
        }

        static String replaceWords(String sentence, List<String> dictionary) {
                // Sort dictionary by length of strings
                Collections.sort(dictionary, Comparator.comparingInt(String::length));

                String[] sentenceArray = sentence.split(" ");
                for (int i = 0; i < sentenceArray.length; i++) {
                        sentenceArray[i] = replace(sentenceArray[i], dictionary);
                }

                // Join the words back into a single string
                return String.join(" ", sentenceArray);
        }

        public static void main(String[] args) {
                List<String> dic = new ArrayList<>();
                dic.add("cat");
                dic.add("rat");
                dic.add("bat");

                System.out.println(replaceWords("the cat was rat by the bat", dic));
        }
}
