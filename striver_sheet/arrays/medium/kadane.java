package striver_sheet.arrays.medium;

import java.util.*;

public class kadane {
    public static void main(String[] args) {

    }

    static int maxSubArraySumBetter(int[] nums) {
        int maxI = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];

                maxI = Math.max(maxI, sum);
            }
        }

        return maxI;
    }

    // Kadane's
    static int KadaneAlgo(int[] nums) {
        int maxI = Integer.MIN_VALUE;

        int sum = 0;

        for (int i = 0; i < nums.length; i++) {

            sum += nums[i];

            if (sum > maxI) {
                maxI = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxI;
    }
}
