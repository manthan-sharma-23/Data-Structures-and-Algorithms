package sorting;

import java.util.Arrays;

public class bubble {
    public static void main(String[] args) {
        int arr[] = { -1,9,-3 };
        System.out.println(Arrays.toString(bubble_sort(arr)));
    }

    static int[] bubble_sort(int arr[]) {
        boolean swapped = false;
        int n = arr.length;
        if (n <= 1)
            return arr;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n - i; j++) {

                if (arr[j] < arr[j - 1]) {
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }

        }
        return arr;
    }
}
