package arrays;

import java.util.Scanner;

public class input {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int[] roll_numbers = new int[5];

        for (int i = 0; i < roll_numbers.length; i++) {
            roll_numbers[i] = in.nextInt();
        }
        System.out.println();
        // for (int i = 0; i < roll_numbers.length; i++) {
        // System.out.print(roll_numbers[i] + " ");
        // }

        // same as above
        for (int num : roll_numbers) {
            System.out.print(num + " ");
        }
    }
}
