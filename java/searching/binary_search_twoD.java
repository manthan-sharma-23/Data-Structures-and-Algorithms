package searching;

import java.util.*;

public class binary_search_twoD {
    public static void main(String[] args) {
        int[][] arr = {
                { 1, 2, 3 },
                { 2, 5, 8 },
                { 4, 10, 13 }
        };

        System.out.println(Arrays.toString(bounding_searchtwoD(arr, 3)));
    }

    // row and col diffferently sorted matrix
    static int[] bounding_searchtwoD(int[][] arr, int target) {
        int row = 0;
        int col = arr[row].length - 1;

        while (row < arr.length && col >= 0) {
            if (arr[row][col] == target) {
                return new int[] { row, col };
            }
            if (arr[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        return new int[] { -1, -1 };
    }
}