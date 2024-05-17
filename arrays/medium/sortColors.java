package arrays.medium;

import java.util.Arrays;
import java.util.HashMap;

public class sortColors {
    public static void main(String[] args) {
        int[] colors = { 0, 1, 2, 2, 0, 1, 1, 0 };
        int[] sortedColors = sortColorsBruteForce(colors);
        System.out.println(Arrays.toString(sortedColors));
    }

    static int[] sortColorsBruteForce(int[] colors) {
        int[] result = new int[colors.length];
        HashMap<Integer, Integer> colorMap = new HashMap<>();
        for (int i : colors) {
            if (colorMap.containsKey(i)) {
                colorMap.put(i, colorMap.get(i) + 1);
            } else {
                colorMap.put(i, 1);
            }
        }
        
        return result;
    }
}
