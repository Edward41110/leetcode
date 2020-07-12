package LeetCode;

class GetLastMoment {
    public int getLastMoment(int n, int[] left, int[] right) {
        
        if (left.length == 0) {
            return n - right[0];
        } else if (right.length == 0) {
            return left[left.length - 1];
        } else {
            return (Math.max(left[left.length - 1], n - right[0]));
        }
    }
}
