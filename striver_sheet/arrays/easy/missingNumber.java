package striver_sheet.arrays.easy;

import java.util.Arrays;

public class missingNumber {
    public static void main(String[] args) {
        int[] a = { 1, 0, 3 };
        int number = missingNumber(a);

        System.out.println(number);
    }

    static int missingNumber(int[] nums) {
        int n = nums.length;
        int miss = -1;
        int[] hash = new int[n + 1];
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = nums[i];
        }

        System.out.println(Arrays.toString(hash));
        for (int i = 1; i < hash.length; i++) {
            if (hash[i] == 0) {
                miss = i;
            }
        }

        if (miss == -1) {
            miss = 0;
        }

        return miss;
    }

}
