package LeetCode;

import java.util.ArrayDeque;
import java.util.Deque;

class decodeString {
    public String decodeString(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        Deque<Integer> times = new ArrayDeque<>();
        Deque<StringBuilder> dq = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();

        // index:已经处理好的字段
        int index = 0;
        char ch = s.charAt(0);
        OUT:
        while (true) {
            int i = index;
            if (ch >= '0' && ch <= '9') {
                while (ch >= '0' && ch <= '9') {
                    ch = s.charAt(++i);
                }
                times.push(Integer.parseInt(s.substring(index, i)));
                // 跳过'['
                index = ++i;
                ch = s.charAt(i);
            }
            // 拿到新数字，要另起炉灶
            dq.push(sb);
            sb = new StringBuilder();
            while (ch < '0' || ch > '9') {
                if (ch == ']') {
                    // 字符串复制
                    int time = times.pop();
                    String str = sb.toString();
                    for (int j = 1;j < time;j++) {
                        sb.append(str);
                    }
                    // 连接到上一段末尾
                    sb = dq.pop().append(sb);
                } else {
                    sb.append(ch);
                }
                // 跳过']'
                index = ++i;
                if (i == s.length()) {
                    break OUT;
                }
                ch = s.charAt(i);
            }
        }
        return sb.toString();
    }
}