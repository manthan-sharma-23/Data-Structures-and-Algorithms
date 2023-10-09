package arrays;

import java.util.*;

public class intro {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        // int[] rolls = { 1, 2, 3, 4, 5 }; // Store 5 roll numbers

        int n = sc.nextInt();
        int[] rollnums = new int[n];

        rollnums[0] = 2;
        rollnums[1] = 34;

        System.out.println(Arrays.toString(rollnums));

        // dynamic memory allocation DMA
        int[] ros; // declaration of array --compile time

        ros = new int[4]; // initialisation -- Actual object being created in heap memory --run time

        System.out.println(ros[1]);
    }
}
