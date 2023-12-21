package striver_sheet.arrays;

import java.util.*;

public class moveZerosToRight {
    public static void main(String[] args) {
        int[] nums = { 1, 0, 3, 0, 5, 0, 6, 0 };
        moveZeroesOptimal(nums);
        System.out.println(Arrays.toString(nums));

    }

    static void moveZeroesBruteForce(int[] nums) {
        int n = nums.length;
        int zero = 0;
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                arr[i - zero] = nums[i];
            } else {
                arr[n - zero - 1] = nums[i];
                zero++;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }

    static void moveZeroesOptimal(int[] nums) {
        int snowBallSize = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                snowBallSize++;
            } else if (snowBallSize > 0) {
                int t = nums[i];
                nums[i] = 0;
                nums[i - snowBallSize] = t;
            }
        }
    }
}
