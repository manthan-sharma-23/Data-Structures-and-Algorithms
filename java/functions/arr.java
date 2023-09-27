package functions;

import java.util.Arrays;

public class arr {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4 };
        int a = 90;
        System.out.println(Arrays.toString(arr));
        Change(arr);
        System.out.println(Arrays.toString(arr));
        {
            a = 45; // changes the original value reaasign original reference varibale to a new one
            int c = 99;
        }

        System.out.println(a);
        // System.out.println(c); //values initialized in the block will remain in thhe
        // block
    }

    static void Change(int[] nums) {
        nums[0] = 99;
    }
}
