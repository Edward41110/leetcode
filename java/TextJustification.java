package LeetCode;

import java.util.ArrayList;
import java.util.List;

class TextJustification {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int i = 0;
        while (true) {
            StringBuilder sb = new StringBuilder();
            int cur = i, curWidth = -1;
            while (cur < words.length && curWidth + words[cur].length() + 1 <= maxWidth) {
                curWidth += words[cur++].length() + 1;
            }
            if (cur == words.length) {
                for (int j = i;j < cur;j++) {
                    sb.append(words[j]).append(" ");
                }
                sb.deleteCharAt(sb.length() - 1);
                for (int j = sb.length(); j < maxWidth; j++) {
                    sb.append(" ");
                }
                res.add(sb.toString());
                break;
            } else {
                for (int j = i; j < cur; j++) {
                    sb.append(words[j]);
                    if (cur > j + 1) {
                        int interval = cur - i - 1;
                        int adjust = interval - j + i - 1;
                        int spaces = (maxWidth - curWidth + interval + adjust) / interval;
                        for (int k = 0; k < spaces; k++) {
                            sb.append(" ");
                        }
                    } else {
                        for (int k = sb.length(); k < maxWidth; k++) {
                            sb.append(" ");
                        }
                    }
                }
            }
            i = cur;
            res.add(sb.toString());
        }
        return res;
    }

    public static void main(String[] args) {
        String[]words = new String[]{"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
        TextJustification s = new TextJustification();
        List<String> res = s.fullJustify(words, 16);
        for (String str : res) {
            System.out.println(str);
        }
    }
}