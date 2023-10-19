package sorting;
// When given numbers in range 1 to N  use cyclic sort

import java.util.Arrays;

public class cyclic_sort {
    public static void main(String[] args) {
        int arr[] = { 3, 5, 4, 2, 1 };
        cyclic_sort_(arr);
        System.out.println(Arrays.toString(arr));

    }

    static void swap(int arr[], int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    static void cyclic_sort_(int arr[]) {
        int n = arr.length;
        int i = 0;
        while (i < n) {
            int correct_index = arr[i] - 1;
            if (arr[i] != arr[correct_index]) {
                swap(arr, i, correct_index);
            } else {
                i++;
            }
        }

    }
}
