package LeetCode;

import java.util.HashSet;

class MinimumWindowSubstring {
    // 记录最大值信息，便于更新
    static class bestInfo {
        final int left;
        final int right;
        final int length;
        public bestInfo(int left, int right) {
            this.left = left;
            this.right = right;
            this.length = right - left;
        }
    }

    // 检查所有子串中字符数量是否满足要求
    private boolean hasNotAllIncluded(HashSet<Integer> set, int[]times) {
        for (int i : set) {
            if (times[i] < 0) {
                return true;
            }
        }
        return false;
    }

    public String minWindow(String s, String t) {
        int[]times = new int[128];
        HashSet<Integer> set = new HashSet<>();
        // 将所有t中字符出现次数记录到数组中，并加入关注字符集set
        for (int i = 0; i < t.length(); i++) {
            int ch = t.charAt(i);
            set.add(ch);
            times[ch]--;
        }

        int left = 0, right = 0;
        // 找以0开头的字符串中，包含t的最短子串
        while (right < s.length() && hasNotAllIncluded(set, times)) {
            times[s.charAt(right++)]++;
        }
        // 如果已经达到右边界且未找到，直接返回空字符串
        if (right == s.length() && hasNotAllIncluded(set, times)) {
            return "";
        }
        // 找到一个符合要求的字符串，记录最优值信息
        bestInfo best = new bestInfo(left, right);
        boolean hasAllIncluded = true;
        int lackChar = 0;
        // 在循环中，我们只允许两种状态：
        // 1.[if语句块]当前s.substring(left, right)已经包含t，left左移
        // 2.[else语句块]当前s.substring(left, right)不包含t，只缺失一个字符一次
        // 当left到达s.length() - t.length() + 1，且right到达s.length()，则无论如何都不能包含t，为退出循环的条件
        while (right < s.length() || left <= s.length() - t.length()) {
            if (hasAllIncluded) {
                int ch = s.charAt(left++);
                // 如果关注字符集不包含该字符，或该字符盈余，更新最优值
                if (!set.contains(ch) || times[ch] > 0) {
                    best = right - left < best.length ? new bestInfo(left, right) : best;
                }
                // 如果关注字符集包含该字符，且无盈余，记为缺失字符，更新状态为不包含
                if (set.contains(ch) && times[ch] == 0) {
                    lackChar = ch;
                    hasAllIncluded = false;
                }
                // 更新left右移的数组
                times[ch]--;
            } else {
                // 如果right已到达右边界，且未能包含数组，退出循环
                if (right == s.length()) {
                    break;
                }
                int ch = s.charAt(right++);
                // 如果刚好缺失该字符，则此时已包含t，更新最优值，更新状态为包含
                if (ch == lackChar) {
                    best = right - left < best.length ? new bestInfo(left, right) : best;
                    hasAllIncluded = true;
                }
                // 更新right右移的数组
                times[ch]++;
            }
        }
        return s.substring(best.left, best.right);
    }
}