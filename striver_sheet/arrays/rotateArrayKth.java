package striver_sheet.arrays;

import java.util.*;

public class rotateArrayKth {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5 };
        System.out.println(Arrays.toString(nums));
        RotateByKth(nums, 2);

        System.out.println(Arrays.toString(nums));

    }

    static void RotateRight(int[] nums) {
        System.out.println(Arrays.toString(nums));
        int temp = nums[nums.length - 1];
        int elmt = nums[0];
        for (int i = 0; i < nums.length - 1; i++) {
            elmt = nums[i + 1];
            nums[i + 1] = nums[i];
        }
        nums[0] = temp;

    }

    static void RotateByKth(int[] nums, int k) {
        k = k % nums.length;
        while (k > 0) {
            RotateRight(nums);
            k--;
        }
    }
}
