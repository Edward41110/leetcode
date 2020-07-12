package LeetCode;

import java.util.HashSet;

class longestConsecutiveSequence {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int i : nums) {
            set.add(i);
        }
        int maxLength = 0;
        for (int i : nums) {
            if (set.contains(i - 1)) {
                continue;
            }
            int curLength = 1;
            while (set.contains(i + 1)) {
                curLength++;
                i++;
            }
            maxLength = Math.max(curLength, maxLength);
        }
        return maxLength;
    }
}