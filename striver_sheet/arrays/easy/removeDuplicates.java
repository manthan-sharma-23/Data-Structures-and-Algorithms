package striver_sheet.arrays.easy;

import java.util.*;

public class removeDuplicates {
    public static void main(String[] args) {
        int[] nums = { 1, 1, 2, 3, 3, 4, 4 };
        System.out.println(RemoveDuplicatesOptimal(nums));

        System.out.println(Arrays.toString(nums));

    }

    // Brute force approach time complexity -- nlogn + N
    static int RemoveDuplicatesBruteForce(int[] nums) {
        Set<Integer> numSet = new HashSet<>();

        for (int num : nums) {
            numSet.add(num);
        }

        int index = 0;
        for (int num : numSet) {
            nums[index] = num;
            index++;
        }

        System.out.println(Arrays.toString(nums));

        return index;
    }

    // optimal
    static int RemoveDuplicatesOptimal(int[] nums) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }

        }
        return i+1;
    }
}
