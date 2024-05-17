package arrays.easy;

import java.util.*;

public class imageResolver {

    static int[][] imageSmoother(int[][] img) {
        int[][] gray = new int[img.length][img[0].length];
        for (int i = 0; i < gray.length; i++) {
            for (int j = 0; j < gray[0].length; j++) {

                gray[i][j] = pixelGenerator(img, i, j);
            }
        }
        return gray;

    }

    static int pixelGenerator(int[][] img, int row, int col) {
        int sum = 0;
        int count = 0;
        int m = img.length;
        int n = img[0].length;

        for (int i = Math.max(0, row - 1); i <= Math.min(m - 1, row + 1); i++) {
            for (int j = Math.max(0, col - 1); j <= Math.min(n - 1, col + 1); j++) {
                sum += img[i][j];
                count++;
            }
        }
        return sum / count;
    }

    public static void main(String[] args) {
        int[][] img = { { 100, 200, 100 }, { 200, 50, 200 }, { 100, 200, 100 } };
        for (int[] row : img) {
            for (int pix : row) {
                System.out.print(pix + " ");
            }
            System.out.println();
        }
        int[][] gray = imageSmoother(img);
        System.out.println();
        for (int[] row : gray) {
            for (int pix : row) {
                System.out.print(pix + " ");
            }
            System.out.println();
        }
    }
}