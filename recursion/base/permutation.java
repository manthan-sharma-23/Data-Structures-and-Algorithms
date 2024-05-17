// Order wise permutations of an array

package recursion.base;

import java.util.ArrayList;
import java.util.List;

/**
 * permutation
 */
public class permutation {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3 };
        ArrayPermutations(arr);

    }

    static void recurPermute(int[] nums, List<Integer> ds, List<List<Integer>> ans, boolean[] freq) {
        if (ds.size() == nums.length) {
            ans.add(new ArrayList<>(ds));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!freq[i]) {
                freq[i] = true;
                ds.add(nums[i]);
                recurPermute(nums, ds, ans, freq);
                ds.remove(ds.size() - 1);
                freq[i] = false;
            }
        }
    }

    static void ArrayPermutations(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        boolean[] freq = new boolean[nums.length];
        recurPermute(nums, ds, ans, freq);
        System.out.println(ans);
    }
}