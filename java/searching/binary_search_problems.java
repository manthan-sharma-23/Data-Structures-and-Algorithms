package searching;

import java.util.*;

public class binary_search_problems {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {

        // Problem--1
        // int arr[] = { 1, 3, 6, 9, 12, 14, 17, 19, 23, 26, 34 };
        // int elmt = problemOne(arr, 11);
        // System.out.println(elmt);

        // Problem-2
        char arr[] = { 'a', 'd', 'e', 'g', 'k', 'o', 'y' };
        char elmt = problemTwo(arr, 'o');
        System.out.println(elmt);

    }

    // Problem1 -- smallest number in the array greater than or equal to target
    // number
    static int problemOne(int arr[], int target) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            // System.out.println("tried");
            int mid = start + ((end - start) / 2);

            if (arr[mid] < target) {
                start = mid + 1;
            } else if (arr[mid] == target) {
                return arr[mid];
            } else {
                end = mid - 1;
            }
        }

        return arr[start];
        // return arr[end]; //To return floor of the number rather than ceil as in above
    }

    // Problem2-- problem1 but for characters
    // characeters
    static char problemTwo(char letters[], char target) {

        int start = 0;
        int end = letters.length - 1;
        while (start <= end) {

            int mid = start + ((end - start) / 2);
            if (letters[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }
        return letters[start % letters.length];
        // return arr[end]; //To return floor of the number rather than ceil as in above
    }

    // Problem 3 -- range of a particular number
    // int
    static int[] searchRange(int[] arr, int target) {
        int ans[] = { -1, -1 };

        // check for first occurence of target first
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (arr[mid] < target) {
                start = mid + 1;
            } else if (target > arr[mid]) {
                end = mid - 1;
            } else {
                // potential ans found
                return ans;
            }
        }
        return ans;
    }

    // this function just returns the index value of target.
    // int search(int[] nums,int target,boolean firstAndLastIndex){

    // }

}
