package sorting;

import java.util.Arrays;

public class insertion_sort {
    public static void main(String[] args) {
        int arr[] = { 2, 3, 1, 5, 4, -2, -4 };
        insertion_sort_(arr);
        System.out.println(Arrays.toString(arr));

    }

    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void insertion_sort_(int arr[]) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j > 0; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j, j - 1);
                } else {
                    break;
                }
            }
        }

    }
}
