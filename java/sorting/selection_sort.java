package sorting;

import java.util.*;

public class selection_sort {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int arr[] = { 2, 4, 1,-3, -4, 5,-3 };

        arr = selection_sort_(arr);

        System.out.println(Arrays.toString(arr));

    }

    static int[] selection_sort_(int[] arr) {
        // smallest fix at first algo
        int n = arr.length - 1;
        for (int i = 0; i <= n; i++) {
            int min = i;
            for (int j = i; j <= n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }

            }

            // swap
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

        return arr;
    }
}
