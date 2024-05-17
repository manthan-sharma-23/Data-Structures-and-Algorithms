package arrays.easy;

import java.util.*;

public class subArray {
    public static void main(String[] args) {
        int[] arr = { 1, 1, 0, 2, 3, 1, 0, 1 };
        int length = subArrayLengthBetter(arr, 3);
        System.out.println(length);
    }

    static int subArrayLength(int[] nums, int k) {
        int n = nums.length;
        int l = 0;
        for (int i = 0; i < n; i++) {
            long s = 0;
            for (int j = i; j < n; j++) {

                s += nums[j];

                if (s == k)
                    l = Math.max(l, j - i + 1);

            }
        }

        return l;
    }

    // int[] arr = { 1, 1, 0, 2, 3, 1, 0, 1 };
    static int subArrayLengthBetter(int[] a, long k) {
        int n = a.length;

        Map<Long, Integer> preSumMap = new HashMap<>();

        long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            // calculate the prefix sum till index i:
            sum += a[i];

            // if the sum = k, update the maxLen:
            if (sum == k) {
                maxLen = Math.max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e. x-k:
            long rem = sum - k;

            // Calculate the length and update maxLen:
            if (preSumMap.containsKey(rem)) {
                int len = i - preSumMap.get(rem);
                maxLen = Math.max(maxLen, len);
            }

            // Finally, update the map checking the conditions:
            if (!preSumMap.containsKey(sum)) {
                preSumMap.put(sum, i);
            }

            System.out.println(preSumMap);
        }

        return maxLen;
    }

}