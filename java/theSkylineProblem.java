package LeetCode;

import java.util.*;

class theSkylineProblem {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        class Info {
            final int x;
            final int height;
            final boolean isUp;
            public Info(int x, int height, boolean isUp) {
                this.x = x;
                this.height = height;
                this.isUp = isUp;
            }
        }
        class comparator implements Comparator<Info> {
            @Override
            public int compare(Info o1, Info o2) {
                return o1.x - o2.x;
            }
        }
        if (buildings == null || buildings.length == 0) {
            return new ArrayList<>();
        }
        Info[]infos = new Info[2 * buildings.length];
        for (int i = 0; i < buildings.length; i++) {
            infos[2 * i] = new Info(buildings[i][0], buildings[i][2], true);
            infos[2 * i + 1] = new Info(buildings[i][1], buildings[i][2], false);
        }
        Arrays.sort(infos, new comparator());
        TreeMap<Integer, Integer> treeMap = new TreeMap<>();
        List<List<Integer>> res= new ArrayList<>();
        int curHeight = 0;
        for (int i = 0; i < infos.length; i++) {
            Info info = infos[i];
            if (info.isUp) {
                treeMap.put(info.height, treeMap.getOrDefault(info.height, 0) + 1);
            } else if (treeMap.get(info.height) == 1){
                treeMap.remove(info.height);
            } else {
                treeMap.put(info.height, treeMap.get(info.height) - 1);
            }
            if (i < infos.length - 1 && infos[i].x == infos[i + 1].x) {
                continue;
            }
            if (treeMap.isEmpty()) {
                curHeight = 0;
                List<Integer> list = new ArrayList<>();
                list.add(info.x);
                list.add(0);
                res.add(list);
            } else if (treeMap.lastKey() != curHeight) {
                curHeight = treeMap.lastKey();
                List<Integer> list = new ArrayList<>();
                list.add(info.x);
                list.add(curHeight);
                res.add(list);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        theSkylineProblem s = new theSkylineProblem();
        System.out.println(s.getSkyline(new int[][]{
                {0, 2, 3}, {2, 5, 3}
        }));
    }
}
