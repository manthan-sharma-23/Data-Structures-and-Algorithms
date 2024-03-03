package striver_sheet.arrays.medium;

import java.util.*;

/**
 * twoSum
 */
public class twoSum {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5, 6, 7 };

        int target = 3;

        int[] indexe = twoSumBruteForce(nums, target);

        System.out.println(Arrays.toString(indexe));
    }

    static int[] twoSumBruteForce(int[] nums, int target) {
        int result[] = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return result;
    }
}