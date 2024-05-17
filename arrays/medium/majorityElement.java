package arrays.medium;

// More's Voting Algorithm

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class majorityElement {

    public static void main(String[] args) {
        int[] nums = { 3, 2, 3 };
        int it = majorityElementOptimal(nums);

        System.out.println(it);
    }

    // returns index
    // O(2n) -> Time
    // Space != O(1)
    static int majorityElementBetter(int[] nums) {
        int n = nums.length;
        int result = -1;
        HashMap<Integer, Integer> map = new HashMap<>();

        // arrange the hash map
        for (int i = 0; i < nums.length; i++) {
            int value = map.getOrDefault(nums[i], 0);
            map.put(nums[i], value + 1);
        }

        System.out.println(map);

        for (Map.Entry<Integer, Integer> it : map.entrySet()) {
            if (it.getValue() > (n / 2)) {
                result = it.getKey();
            }
        }

        return result;
    }

    static int majorityElementOptimal(int[] nums) {

        int elmt = 0;
        int c = 0;
        for (int i = 0; i < nums.length; i++) {
            if (c == 0) {
                c = 1;
                elmt = nums[i];
            } else if (nums[i] == elmt) {
                c++;
            } else {
                c--;
            }
        }

        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == elmt) {
                count++;
            }
        }

        if (count >nums.length / 2)
            return elmt;

        return -1;
    }
}
