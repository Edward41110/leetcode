package LeetCode;

import java.util.Arrays;

class SearchInRotatedSortedArray {

	public static int search(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;
		if (target > nums[0]) {
			while (left <= right) {
				int mid = left + ((right - left) >> 1);
				if (nums[mid] == target) {
					return mid;
				} else if (nums[mid] < target && nums[0] <= nums[mid]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
		} else if (target < nums[0]) {
			while (left <= right) {
				int mid = left + ((right - left) >> 1);
				if (nums[mid] == target) {
					return mid;
				} else if (nums[mid] > target && nums[0] > nums[mid]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		} else {
			return 0;
		}
		return -1;
	}

	public static int[] generateRandomArray() {
		int length = (int)(7 * Math.random()) + 3;
		int maxValue = (int)(10 * Math.random()) + length;
		boolean[]used = new boolean[maxValue];
		int[]sortedArray = new int[length];
		int[]nums = new int[length];
		for (int i = 0; i < length; i++) {
			int num = (int)(maxValue * Math.random());
			while (used[num]) {
				num = (int)(maxValue * Math.random());
			}
			sortedArray[i] = num;
			used[num] = true;
		}
		Arrays.sort(sortedArray);
		int breakPoint = (int)(length * Math.random());
		while (breakPoint >= length) {
			breakPoint = (int)(length * Math.random());
		}
		if (length - breakPoint >= 0) {
			System.arraycopy(sortedArray, breakPoint, nums, 0, length - breakPoint);
		}
		if (breakPoint >= 0) {
			System.arraycopy(sortedArray, 0, nums, length - breakPoint, breakPoint);
		}
		return nums;
	}

	public static int correctMethod(int[]nums, int target) {
		int ret = -1;
		if (nums == null || nums.length == 0) {
			return ret;
		}
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == target) {
				ret = i;
				break;
			}
		}
		return ret;
	}

	public static void test() {
		int testTime = 100000;
		for (int i = 0; i < testTime; i++) {
			int[]nums = generateRandomArray();
			int target = nums[(int)(nums.length * Math.random())];
			int test = search(nums, target);
			int answer = correctMethod(nums, target);
			if (test != answer) {
				for (int num : nums) {
					System.out.print(num + "\t");
				}
				System.out.println();
				System.out.println("target:" + target);
				System.out.println("test:" + test);
				System.out.println("answer:" + answer);
				break;
			}
		}

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		test();
	}
}
