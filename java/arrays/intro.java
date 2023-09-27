package arrays;

import java.util.*;

public class intro {
    public static void main(String[] args) {
        int[] rolls = { 1, 2, 3, 4, 5 }; // Store 5 roll numbers

        int[] rollnums = new int[4];
        rollnums[0] = 2;
        rollnums[1] = 34;

        System.out.println(Arrays.toString(rollnums));


        //dynamic memory allocation
        int[] ros; // declaration of array --compile time 
        ros = new int[4]; // initialisation -- Actual object being created in heap memory  --run time

    }
}
