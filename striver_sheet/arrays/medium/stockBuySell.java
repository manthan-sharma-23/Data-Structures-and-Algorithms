package striver_sheet.arrays.medium;

public class stockBuySell {
    public static void main(String[] args) {

    }

    static int MaxProfit(int[] nums) {
        int maxP = 0;
        int minPrice = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            minPrice = Math.min(minPrice, nums[i]);

            maxP = Math.max(maxP, nums[i] - minPrice);
        }

        return maxP;
    }
}
