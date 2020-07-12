class Solution {
public:
    string reverse(char*chars, int length) {
        if (chars[0] == '0' && length == 1) {
		    return "0";
	    }
	    string ret;
	    for (int i = 0;i < length;i++) {
	    	if (chars[length - 1] == '0') {
		    	break;
		    }
		    ret += chars[length - i - 1];
	    }
	    delete[]chars;
	    return ret;
    }

    string addBinary(string a, string b) {
        if (a.length() == 0) {
	    	return b;
	    }
	    else if (b.length() == 0) {
	    	return a;
	    }
	    int length = a.length() >= b.length() ? a.length() + 1 : b.length() + 1;
	    char*ret  = new char[length];
	    char carry = 0;
	    int i = 0;
	    int j = a.length() - 1;
	    int k = b.length() - 1;
	    while (j >= 0 && k >= 0) {
	    	ret[i] = a[j] + b[k] + carry - '0';
	    	carry = 0;
		    if (ret[i] >= '2') {
		    	ret[i] -= 2;
		    	carry = 1;
		    }
		    i++;
		    j--;
		    k--;
	    }

	    while (j >= 0) {
		    ret[i] = a[j] + carry;
    		    carry = 0;
	    	if (ret[i] >= '2') {
		    	ret[i] -= 2;
			    carry = 1;
	    	}
		    i++;
		    j--;
    	}

	    while (k >= 0) {
	    	ret[i] = b[k] + carry;
	    	carry = 0;
	    	if (ret[i] >= '2') {
	    		ret[i] -= 2;
	    		carry = 1;
	    	}
	    	i++;
	    	k--;
	    }
	    if (carry) {
	    	ret[i] = '1';
    	}
	    else {
		    length--;
	    }

	    return reverse(ret, length);
    }
};
