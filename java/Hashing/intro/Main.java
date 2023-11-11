package Hashing.intro;

import java.util.*;

public class Main {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int arr[] = { 2, 3, 4, 2, 14, 3, 3, 2, 2, 6, 7, 56, 12 };
        System.out.println("Your array --> " + Arrays.toString(arr));
        int[] hashedArr = HashedArr(arr);

        // System.out.println("Hashed Array --> " + Arrays.toString(hashedArr));

        System.out.print("Enter the number to get the count of - ");
        int num = in.nextInt();
        System.out.println("count for the " + num + " is " + hashedArr[num]);

    }

    static int GreatestNumber(int[] arr) {
        int num = Integer.MIN_VALUE;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > num) {
                num = arr[i];
            }
        }

        return num;
    }

    // create an Hashed array
    static int[] HashedArr(int[] arr) {
        int length = GreatestNumber(arr) + 1;
        int hash[] = new int[length];
        for (int i = 0; i < arr.length; i++) {
            hash[arr[i]] += 1;
        }
        return hash;
    }
}
