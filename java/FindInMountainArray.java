package LeetCode;

class FindInMountainArray {

	static class MountainArray {

		int[] mountainArr;
		MountainArray(int[]mountainArr) {
			this.mountainArr = mountainArr;
		}

		public int get(int index) {
			return this.mountainArr[index];
		}

		public int length() {
			return this.mountainArr.length;
		}
	}

	private static int findSummit(MountainArray mountainArr, int length) {
		int low = 0;
		int high = length - 1;

		while (low < high) {
			int mid = (low + high) >>> 1;
			if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low;
	}

	private static int binarySearchLeft(MountainArray mountainArr, int fromIndex, int toIndex, int key) {
		int low = fromIndex;
		int high = toIndex;

		while (low <= high) {
			int mid = (low + high) >>> 1;
			int midVal = mountainArr.get(mid);

			if (midVal < key) {
				low = mid + 1;
			} else if (midVal > key) {
				high = mid - 1;
			} else {
				return mid;				 // key found
			}
		}
		return -1;  // key not found.
	}

	private static int binarySearchRight(MountainArray mountainArr, int fromIndex, int toIndex, int key) {
		int low = fromIndex;
		int high = toIndex;

		while (low <= high) {
			int mid = (low + high) >>> 1;
			int midVal = mountainArr.get(mid);

			if (midVal > key){
				low = mid + 1;
			} else if (midVal < key) {
				high = mid - 1;
			} else {
				return mid; // key found
			}
		}
		return -1;  // key not found.
	}

	public static int findInMountainArray(int target, MountainArray mountainArr) {
		int length = mountainArr.length();
		int summitIdx = findSummit(mountainArr, length);
		if (mountainArr.get(summitIdx) == target) {
			return summitIdx;
		}
		int left = binarySearchLeft(mountainArr, 0, summitIdx, target);
		if (left != -1) {
			return left;
		} else {
			return binarySearchRight(mountainArr, summitIdx + 1, length - 1, target);
		}
	}

	public static void main(String[] args) {
		int[]arr = new int[]{0, 5, 3, 1};
		MountainArray mountainArr = new MountainArray(arr);
		System.out.println(findInMountainArray(1, mountainArr));
	}
}