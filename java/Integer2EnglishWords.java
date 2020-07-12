package LeetCode;

class Integer2EnglishWords {

    private String getThousandString(int num) {
        String[]ones = {"", "One ", "Two ", "Three ", "Four ",
                "Five ", "Six ", "Seven ", "Eight ", "Nine "};
        String[]teen = {"Ten ", "Eleven ", "Twelve ", "Thirteen " , "Fourteen ",
                "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        String[]ty = {"", "Twenty ", "Thirty ", "Forty ",
                "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        StringBuilder sb = new StringBuilder();
        int hundred = num / 100;
        if (hundred != 0) {
            sb.append(ones[hundred]);
            sb.append("Hundred ");
            if (num % 100 == 0) {
                return sb.toString();
            }
        }
        int ten = num % 100 / 10;
        if (ten > 1) {
            sb.append(ty[ten - 1]);
            if (num % 10 != 0) {
                sb.append(ones[num % 10]);
            }
        } else if (ten == 1){
            sb.append(teen[num % 10]);
        } else {
            sb.append(ones[num % 10]);
        }
        return sb.toString();
    }

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        String[]thousand = {"", "Thousand ", "Million ", "Billion "};
        int n = num, cnt = 0;
        while (n > 0) {
            n /= 10;
            cnt++;
        }
        StringBuilder sb = new StringBuilder();
        cnt = cnt % 3 == 0 ? cnt / 3 : cnt / 3 + 1;
        while (cnt-- > 0) {
            int thousands = (int)Math.pow(1000, cnt);
            int threeDigits = num / thousands;
            if (threeDigits != 0) {
                sb.append(getThousandString(threeDigits));
                sb.append(thousand[cnt]);
            }
            num %= thousands;
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    public static void main(String[] args) {
        Integer2EnglishWords s = new Integer2EnglishWords();
        System.out.println(s.numberToWords(1234567));
    }
}