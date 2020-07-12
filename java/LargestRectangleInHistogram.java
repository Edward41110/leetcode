package LeetCode;

import java.util.LinkedList;
import java.util.Stack;

class LargestRectangleInHistogram {

	public static int largestRectangleArea(int[] heights) {
		if (heights == null || heights.length == 0) {
			return 0;
		}
		Stack<LinkedList<Integer>> stack = new Stack<>();
		int[]left = new int[heights.length];
		int[]right = new int[heights.length];

		for (int i = 0; i < heights.length; i++) {
			if (stack.isEmpty()) {
				stack.push(new LinkedList<>());
				stack.peek().add(i);
			} else {
				if (heights[i] > heights[stack.peek().getLast()]) {
					stack.push(new LinkedList<>());
					stack.peek().add(i);
				} else if (heights[i] == heights[stack.peek().getLast()]) {
					stack.peek().add(i);
				} else {
					LinkedList<Integer> list = stack.pop();
					for (int j : list) {
						right[j] = i;
						if (stack.isEmpty()) {
							left[j] = -1;
						} else {
							left[j] = stack.peek().getLast();
						}
					}
					i--;
				}
			}
		}
		while (!stack.isEmpty()) {
			LinkedList<Integer> list = stack.pop();
			for (int i : list) {
				right[i] = heights.length;
				if (stack.isEmpty()) {
					left[i] = -1;
				} else {
					left[i] = stack.peek().getLast();
				}
			}
		}
		int maxArea = 0;
		for (int i = 0; i < heights.length; i++) {
			maxArea = Math.max(heights[i] * (right[i] - left[i] - 1), maxArea);
		}
		return maxArea;
	}

	public static void main(String[] args) {
		int[]nums = new int[]{2, 1, 5, 6, 2, 3};
		System.out.println(largestRectangleArea(nums));
	}
}