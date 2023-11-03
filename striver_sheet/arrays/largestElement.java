package striver_sheet.arrays;

import java.util.*;

public class largestElement {
    public static void main(String[] args) {
        int arr[] = { -4, -9, -1 };
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

    static boolean checkIfArrayIsSorted(int nums[]) {
        int prev = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < prev) {
                return false;
            }
            prev = nums[i - 1];
        }

        return true;

    }

    static int secondLargestElmt_(int arr[]) {

        // BRUTE FORCE APPROACH
        // approach i thought of--> sort the array and n-2 index. with some edge cases .
        // gets time complexity of NlogN +N

        // insertion_sort_(arr);
        // System.out.println(Arrays.toString(arr));
        // int num = arr[arr.length - 1];
        // for (int k = arr.length - 2; k >= 0; k--) {
        // if (num != arr[k]) {
        // num = arr[k];
        // return num;
        // }
        // }

        // BETTER APPROACH
        // total time complexity for two passes --> O(2N)
        // int num = Integer.MIN_VALUE;
        // int largest = largestElement_(arr); // First find the largest O(n)
        // for (int i = 0; i < arr.length; i++) { // Then find the second largest O(n)
        // if (arr[i] > num && arr[i] != largest) {
        // num = arr[i];
        // }
        // }
        // return num;

        // MOST OPTIMAL APPROACH
        // O(N) approach
        int num = Integer.MIN_VALUE;
        int largest = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > largest) {
                num = largest;
                largest = arr[i];
            } else if (arr[i] > num && arr[i] < largest) {
                num = arr[i];
            }
        }
        return num;
    }
}