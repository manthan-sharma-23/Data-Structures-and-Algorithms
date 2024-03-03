package striver_sheet.arrays.medium;

import java.util.*;

/**
 * twoSum
 */
public class twoSum {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5, 6, 7 };

        int target = 3;

        int[] indexe = twoSumBetter(nums, target);

        System.out.println(Arrays.toString(indexe));
    }

    // O(n2)-- Time
    // O(1) -- Space
    static int[] twoSumBruteForce(int[] nums, int target) {
        int result[] = new int[2];
        result[0] = result[1] = -1;
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

    static int[] twoSumBetter(int[] nums, int target) {
        int[] ans = new int[2];
        ans[0] = ans[1] = -1;
        HashMap<Integer, Integer> mpp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.containsKey(moreNeeded)) {
                ans[0] = mpp.get(moreNeeded);
                ans[1] = i;
                return ans;
            }

            mpp.put(nums[i], i);

        }

        return ans;

    }

    //optimal 
    static int[] twoSumOptimal(int[] nums, int target) {
        Arrays.sort(nums);
        int[] result = new int[2];
        result[0] = result[1] = -1;
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result[0] = left;
                result[1] = right;
                return result;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }

        }
        return result;
    }
}