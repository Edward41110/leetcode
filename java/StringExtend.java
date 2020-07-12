package LeetCode;

public class StringExtend {

	public static int getLongest(char[]charArr){
		int[]next = new int[charArr.length + 1];
		next[0] = -1;
		next[1] = 0;
		int cur = 2;
		int cn = 0;
		while (cur <= charArr.length) {
			if (charArr[cn] == charArr[cur - 1]) {
				next[cur++] = ++cn;
			} else if (cn > 0) {
				cn = next[cn];
			} else {
				next[cur++] = 0;
			}
		}
		return next[cur - 1];
	}
	
	public static String toTwoStringByKMP(String str) {
		if (str == null) {
			return null;
		}
		return str + str.substring(getLongest(str.toCharArray()));
	}
	
	public static char[]manacherString(String str) {
		char[]charArr = str.toCharArray();
		char[]res = new char[str.length() * 2 + 1];
		int index = 0;
		for (int i = 0;i != res.length;i++) {
			res[i] = (i & 1) == 0 ? '#' : charArr[index++];
		}
		return res;
	}
	
	public static int manacher(String str) {
		if (str == null || str.length() == 0) {
			return 0;
		}
		char[]charArr = manacherString(str);
		int[]pArr = new int[charArr.length];
		int C = -1;
		int R = -1;
		int i;
		for (i = 0;i < charArr.length;i++) {
			if (i > R || i + pArr[2 * C - i] == R) {
				int j = i > R ? 1 : R - i + 1;
				while (i - j >= 0 && i + j < charArr.length && charArr[i - j] == charArr[i + j]) {
					j++;
				}
				pArr[i] = --j;
				if (j > R - i + 1) {
					C = i;
					R = i + j;
					if (R == charArr.length - 1) {
						break;
					}
				}
			} else if (i + pArr[2 * C - i] < R) {
				pArr[i] = pArr[2 * C - i];
			} else if (i + pArr[2 * C - i] > R) {
				pArr[i] = R - i;
			}
		}
		return pArr[i];
	}
	
	public static String reverse(String str) {
		StringBuilder res = new StringBuilder();
		char[]charArr = str.toCharArray();
		for (int i = 0;i < str.length();i++) {
			res.append(charArr[charArr.length - i - 1]);
		}
		return res.toString();
	}
	
	public static String toPalindromeByManacher(String str) {
		int res = manacher(str);
		return str + reverse(str.substring(0, str.length() - res));
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(toTwoStringByKMP("abcabc"));
		System.out.println(toPalindromeByManacher("abcbc"));
	}
}
