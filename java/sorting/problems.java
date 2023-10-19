package sorting;

import java.util.*;

public class problems {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int arr[] = { 0, 2, 4, 1, 5 };

        int nums = missing_number_search(arr);
        System.out.println(nums);

    }

    static void swap(int arr[], int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    static void cycle_sort(int arr[]) {
        int i = 0;
        while (i < arr.length) {
            if (arr[i] < arr.length && arr[i] != arr[arr[i]]) {
                swap(arr, i, arr[i]);
            } else {
                i++;
            }

        }
    }

    static int missing_number_search(int arr[]) {
        // sort the arr first
        cycle_sort(arr);
        System.out.println(Arrays.toString(arr));
        int num = 0;

        for (int i = 1; i < arr.length; i++) {
            int difference = arr[i] - arr[i - 1];
            if (difference == 2) {
                num = arr[i - 1] + 1;
            }

        }

        return num;

    }
}
