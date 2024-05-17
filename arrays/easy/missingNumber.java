package arrays.easy;

import java.util.Arrays;

public class missingNumber {
    public static void main(String[] args) {
        int[] a = { 0, 2, 3, 4, 1, 0 };
        int number = missingNumberOptimalXOR(a);

        System.out.println(number);
    }

    static int missingNumberBruteForce(int[] nums) {
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

    static int missingNumberOptimalXOR(int nums[]) {
        int n = nums.length;
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < n-1; i++) {
            xor1 ^= (i + 1);
            xor2 ^= nums[i];
        }
        
        return xor1 ^ xor2;
    }

}
