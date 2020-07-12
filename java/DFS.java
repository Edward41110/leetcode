package LeetCode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class DFS {

	public static List<List<Integer>> permute(int[]nums) {
		List<List<Integer>> res = new ArrayList<>();
		if (nums == null) {
			return res;
		}
		Deque<Integer> path = new ArrayDeque<>();
		boolean[]used = new boolean[nums.length];
		dfs(nums, 0, path, used, res);
		return res;
	}

	public static void dfs(int[] nums, int depth, Deque<Integer> path, boolean[] used, List<List<Integer>> res) {
		if (depth == nums.length) {
			res.add(new ArrayList<>(path));
			return;
		}
		for (int i = 0; i < nums.length; i++) {
			if (used[i]) {
				continue;
			}
			path.addLast(nums[i]);
			used[i] = true;
			dfs(nums, depth + 1, path, used, res);
			path.removeLast();
			used[i] = false;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[]nums = {1};
		System.out.println(permute(nums));
	}
}
