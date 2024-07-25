import java.util.*;
import java.util.Array;

class Solution {
        public int[] twoSum(int num[], int target) {
                for (int i = 0; i < num.length; i++) {
                        if (num[i] + num[i + 1] == target) {
                                return new int[] { i, i + 1 };
                        }
                }
                return new int[] {};
        }

        public static void main(String arg[]) {
                int num[] = { 2, 4, 5, 6 };
                int target = 9;
                int result[] = twoSum(num, target);
        }
}