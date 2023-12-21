package striver_sheet.arrays.easy;

import java.util.*;

public class rotateArrayKth {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5 };
        rotate(nums, 2);

    }

    static void rotate(int[] nums, int k) {
        k %= nums.length;
        int n = nums.length;
        reverseNum(nums, 0, n - 1);
        reverseNum(nums, 0, k - 1);
        reverseNum(nums, k, n - 1);
    }

    static void reverseNum(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
