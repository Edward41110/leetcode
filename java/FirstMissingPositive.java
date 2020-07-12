package LeetCode;

class FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 1;
        }
        int i;
        for (i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                break;
            }
        }
        if (i == nums.length) {
            return 1;
        }
        for (i = 0; i < nums.length; i++) {
            if (nums[i] <= 0 || nums[i] > nums.length) {
                nums[i] = 1;
            }
        }
        for (i = 0; i < nums.length; i++) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for (i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                break;
            }
        }
        return i + 1;
    }

    public static void main(String[] args) {
        FirstMissingPositive s = new FirstMissingPositive();
        System.out.println(s.firstMissingPositive(new int[]{3,4,-1,1}));
    }
}