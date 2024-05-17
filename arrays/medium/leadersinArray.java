package arrays.medium;

import java.util.ArrayList;
import java.util.List;

public class leadersinArray {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 2, 1 };

        List<Integer> list = leadersinArrayBrute(nums);

        System.out.println(list);
    }

    static List<Integer> leadersinArrayBrute(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> list = new ArrayList<>();
        list.add(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            boolean large = true;
            for (int j = i+1; j < n; j++) {
                if (nums[j] >= nums[i]) {
                    large = false;
                    break;
                }
            }
            if (large) {
                list.add(nums[i]);
            }
        }
        return list;
    }

    static List<Integer> leadersinArrayOptimal(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> list = new ArrayList<>();
        int index = n - 1;
        int max = Integer.MIN_VALUE;

        while (index >= 0) {
            if (nums[index] > max) {
                list.add(nums[index]);
                max = nums[index];
            }

            index--;
        }
        return list;
    }
}
