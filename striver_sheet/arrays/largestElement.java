package striver_sheet.arrays;

import java.util.Arrays;

public class largestElement {
    public static void main(String[] args) {
        int arr[] = { 6, 3, 2, 12, 12, 12 };
        int largest = secondLargestElmt_(arr);
        System.out.println(largest);

    }

    static int largestElement_(int arr[]) {
        int max = arr[0];
        for (int elmt : arr) {
            if (elmt > max) {
                max = elmt;
            }
        }

        return max;
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

    static int secondLargestElmt_(int arr[]) {
        // approach i thought of--> sort the array and n-2 index. with some edge cases .
        insertion_sort_(arr);
        System.out.println(Arrays.toString(arr));
        int num = arr[arr.length - 1];
        for (int k = arr.length - 2; k >= 0; k--) {
            if (num != arr[k]) {
                num = arr[k];
                break;
            }
        }
        return num;

    }
}
