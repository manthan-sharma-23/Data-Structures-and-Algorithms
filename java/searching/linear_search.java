package searching;

import java.util.*;

public class linear_search {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        // int[] arr={2,3,4,6,18,20};
        // int target=in.nextInt();

        // int index=linearSearch(arr, target);
        // System.out.println("Index value "+index);

        // boolean result=linearSearchEnhanced(arr, target);
        // System.out.println("Result "+result);

        // String name = "Kunal";
        // char target = 'j';

        // boolean result=charSearch(name, target);
        // System.out.println(result);

        // boolean result = charSearchEnhanced(name, target);
        // System.out.println(result);

        // int[] arr = { 2, 3, -7, 6, -1, 20 };
        // int min_number = findMin(arr);
        // System.out.println(min_number);

        // IN THE TWO-D ARRAY
        int[][] arr = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { -7, 8, 9 },
                { 22, -2, 45, 98 },
                { 23, 65 }
        };

        int result = evenDigitsinTwoD(arr);
        System.out.println("Number of even number in the array is " + result);
        System.out.println("Minimum value of an integer " + Integer.MIN_VALUE);
        System.out.println("Maximum value of an integer " + Integer.MAX_VALUE);

    }

    // Integer linear search in an array
    static int linearSearch(int[] arr, int target) {
        if (arr.length == 0) {
            return -1;
        }
        // run for a loop
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // If want to check is element is present or not
    // Integer linear search in an array
    static boolean linearSearchEnhanced(int[] arr, int target) {
        if (arr.length == 0) {
            return false;
        }
        for (int elmt : arr) {
            if (elmt == target) {
                return true;
            }
        }
        return false;
    }

    static boolean charSearch(String name, char target) {
        if (name.length() == 0) {
            return false;
        }
        for (int i = 0; i < name.length(); i++) {
            if (target == name.charAt(i)) {
                return true;
            }
        }
        return false;
    }

    static boolean charSearchEnhanced(String name, char target) {
        if (name.length() == 0) {
            return false;
        }
        for (char chr : name.toCharArray()) {
            if (chr == target) {
                return true;
            }
        }
        return false;
    }

    // find minimum value in the array
    static int findMin(int[] arr) {
        if (arr.length == 0) {
            return Integer.MAX_VALUE;
        }
        int min = Integer.MAX_VALUE;

        for (int i : arr) {
            if (i < min) {
                min = i;
            }
        }

        return min;
    }

    // in twoD array searching
    static int[] twoDsearch(int[][] arr, int target) {

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] == target) {
                    return new int[] { i, j };
                }
            }
        }

        return new int[] { -1, -1 };
    }

    // maximum value in 2D arrays
    static int maxTwoD(int[][] arr) {
        int max = Integer.MIN_VALUE;

        // use enhanced for loop
        for (int[] nums : arr) {
            for (int target : nums) {
                if (target > max) {
                    max = target;
                }
            }
        }

        return max;
    }

    // minimum value in 2D arrays
    static int minTwoD(int[][] arr) {
        int min = Integer.MAX_VALUE;

        // use enhanced for loop
        for (int[] nums : arr) {
            for (int target : nums) {
                if (target < min) {
                    min = target;
                }
            }
        }

        return min;
    }

    // Number of even digits
    static int evenDigitsinTwoD(int[][] arr) {
        int count = 0;

        for (int nums[] : arr) {
            for (int element : nums) {
                if (checkDigits(element)) {
                    count++;
                }
            }
        }

        return count;

    }

    static boolean checkDigits(int element) {
        if (element < 0) {
            element = element * -1;
        }
        int digits = (int) (Math.log10(element)) + 1;

        if (digits % 2 == 0) {
            return true;
        }

        return false;
    }
}
